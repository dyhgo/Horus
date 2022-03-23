#include "ffmpeg.h"
#include "qfontdatabase.h"
#include "qpushbutton.h"
#include "qtreewidget.h"
#include "qlayout.h"
#include "qtimer.h"
#include "qdir.h"
#include "qpainter.h"
#include "qevent.h"
#include "qmimedata.h"
#include "qurl.h"
#include "qdebug.h"

FFmpegThread::FFmpegThread(QObject* parent) : QThread(parent) {
    setObjectName("FFmpegThread");
    stopped = false;
    isPlay = false;

    frameFinish = false;
    videoWidth = 0;
    videoHeight = 0;
    oldWidth = 0;
    oldHeight = 0;
    videoStreamIndex = -1;
    audioStreamIndex = -1;

    url = "rtsp://192.168.1.128:554/1";

    buffer = NULL;
    avPacket = NULL;
    avFrame = NULL;
    avFrame2 = NULL;
    avFrame3 = NULL;
    avFormatContext = NULL;
    videoCodec = NULL;
    audioCodec = NULL;
    swsContext = NULL;

    options = NULL;
    videoDecoder = NULL;
    audioDecoder = NULL;

    //初始化注册,一个软件中只注册一次即可
    FFmpegThread::initlib();
}

//一个软件中只需要初始化一次就行
void FFmpegThread::initlib() {
    static QMutex mutex;
    QMutexLocker locker(&mutex);
    static bool isInit = false;
    if (!isInit) {
        //注册库中所有可用的文件格式和解码器
        av_register_all();
        //注册所有设备,主要用于本地摄像机播放支持
#ifdef ffmpegdevice
        avdevice_register_all();
#endif
        //初始化网络流格式,使用网络流时必须先执行
        avformat_network_init();

        isInit = true;
        qDebug() << TIMEMS << "init ffmpeg lib ok" << " version:" << FFMPEG_VERSION;
#if 0
        //输出所有支持的解码器名称
        QStringList listCodeName;
        AVCodec* code = av_codec_next(NULL);
        while (code != NULL) {
            listCodeName << code->name;
            code = code->next;
        }

        qDebug() << TIMEMS << listCodeName;
#endif
    }
}

bool FFmpegThread::init() {
    //在打开码流前指定各种参数比如:探测时间/超时时间/最大延时等
    //设置缓存大小,1080p可将值调大
    av_dict_set(&options, "buffer_size", "8192000", 0);
    //以tcp方式打开,如果以udp方式打开将tcp替换为udp
    av_dict_set(&options, "rtsp_transport", "tcp", 0);
    //设置超时断开连接时间,单位微秒,3000000表示3秒
    av_dict_set(&options, "stimeout", "3000000", 0);
    //设置最大时延,单位微秒,1000000表示1秒
    av_dict_set(&options, "max_delay", "1000000", 0);
    //自动开启线程数
    av_dict_set(&options, "threads", "auto", 0);

    //打开视频流
    avFormatContext = avformat_alloc_context();

    int result = avformat_open_input(&avFormatContext, url.toStdString().data(), NULL, &options);
    if (result < 0) {
        qDebug() << TIMEMS << "open input error" << url;
        return false;
    }

    //释放设置参数
    if (options != NULL) {
        av_dict_free(&options);
    }

    //获取流信息
    result = avformat_find_stream_info(avFormatContext, NULL);
    if (result < 0) {
        qDebug() << TIMEMS << "find stream info error";
        return false;
    }

    //----------视频流部分开始,打个标记方便折叠代码----------
    if (1) {
        videoStreamIndex = av_find_best_stream(avFormatContext, AVMEDIA_TYPE_VIDEO, -1, -1, &videoDecoder, 0);
        if (videoStreamIndex < 0) {
            qDebug() << TIMEMS << "find video stream index error";
            return false;
        }

        //获取视频流
        AVStream* videoStream = avFormatContext->streams[videoStreamIndex];

        //获取视频流解码器,或者指定解码器
        videoCodec = videoStream->codec;
        videoDecoder = avcodec_find_decoder(videoCodec->codec_id);
        //videoDecoder = avcodec_find_decoder_by_name("h264_qsv");
        if (videoDecoder == NULL) {
            qDebug() << TIMEMS << "video decoder not found";
            return false;
        }

        //设置加速解码
        videoCodec->lowres = videoDecoder->max_lowres;
        videoCodec->flags2 |= AV_CODEC_FLAG2_FAST;

        //打开视频解码器
        result = avcodec_open2(videoCodec, videoDecoder, NULL);
        if (result < 0) {
            qDebug() << TIMEMS << "open video codec error";
            return false;
        }

        //获取分辨率大小
        videoWidth = videoStream->codec->width;
        videoHeight = videoStream->codec->height;

        //如果没有获取到宽高则返回
        if (videoWidth == 0 || videoHeight == 0) {
            qDebug() << TIMEMS << "find width height error";
            return false;
        }

        QString videoInfo = QString("视频流信息 -> 索引: %1  解码: %2  格式: %3  时长: %4 秒  分辨率: %5*%6")
                            .arg(videoStreamIndex).arg(videoDecoder->name).arg(avFormatContext->iformat->name)
                            .arg((avFormatContext->duration) / 1000000).arg(videoWidth).arg(videoHeight);
        qDebug() << TIMEMS << videoInfo;
    }
    //----------视频流部分开始----------

    //----------音频流部分开始,打个标记方便折叠代码----------
    if (1) {
        //循环查找音频流索引
        audioStreamIndex = -1;
        for (uint i = 0; i < avFormatContext->nb_streams; i++) {
            if (avFormatContext->streams[i]->codec->codec_type == AVMEDIA_TYPE_AUDIO) {
                audioStreamIndex = i;
                break;
            }
        }

        //有些没有音频流,所以这里不用返回
        if (audioStreamIndex == -1) {
            qDebug() << TIMEMS << "find audio stream index error";
        } else {
            //获取音频流
            AVStream* audioStream = avFormatContext->streams[audioStreamIndex];
            audioCodec = audioStream->codec;

            //获取音频流解码器,或者指定解码器
            audioDecoder = avcodec_find_decoder(audioCodec->codec_id);
            //audioDecoder = avcodec_find_decoder_by_name("aac");
            if (audioDecoder == NULL) {
                qDebug() << TIMEMS << "audio codec not found";
                return false;
            }

            //打开音频解码器
            result = avcodec_open2(audioCodec, audioDecoder, NULL);
            if (result < 0) {
                qDebug() << TIMEMS << "open audio codec error";
                return false;
            }

            QString audioInfo = QString("音频流信息 -> 索引: %1  解码: %2  比特率: %3  声道数: %4  采样: %5")
                                .arg(audioStreamIndex).arg(audioDecoder->name).arg(avFormatContext->bit_rate)
                                .arg(audioCodec->channels).arg(audioCodec->sample_rate);
            qDebug() << TIMEMS << audioInfo;
        }
    }
    //----------音频流部分结束----------

    //预分配好内存
    avPacket = av_packet_alloc();
    avFrame = av_frame_alloc();
    avFrame2 = av_frame_alloc();
    avFrame3 = av_frame_alloc();

    //比较上一次文件的宽度高度,当改变时,需要重新分配内存
    if (oldWidth != videoWidth || oldHeight != videoHeight) {
        int byte = avpicture_get_size(AV_PIX_FMT_RGB32, videoWidth, videoHeight);
        buffer = (uint8_t*)av_malloc(byte * sizeof(uint8_t));
        oldWidth = videoWidth;
        oldHeight = videoHeight;
    }

    //定义像素格式
    AVPixelFormat srcFormat = AV_PIX_FMT_YUV420P;
    AVPixelFormat dstFormat = AV_PIX_FMT_RGB32;
    //通过解码器获取解码格式
    srcFormat = videoCodec->pix_fmt;

    //默认最快速度的解码采用的SWS_FAST_BILINEAR参数,可能会丢失部分图片数据,可以自行更改成其他参数
    int flags = SWS_FAST_BILINEAR;

    //开辟缓存存储一帧数据
    //以下两种方法都可以,avpicture_fill已经逐渐被废弃
    //avpicture_fill((AVPicture *)avFrame3, buffer, dstFormat, videoWidth, videoHeight);
    av_image_fill_arrays(avFrame3->data, avFrame3->linesize, buffer, dstFormat, videoWidth, videoHeight, 1);

    //图像转换
    swsContext = sws_getContext(videoWidth, videoHeight, srcFormat, videoWidth, videoHeight, dstFormat, flags, NULL, NULL, NULL);

    //输出视频信息
    //av_dump_format(avFormatContext, 0, url.toStdString().data(), 0);

    //qDebug() << TIMEMS << "init ffmpeg finsh";
    return true;
}

void FFmpegThread::run() {
    while (!stopped) {
        //根据标志位执行初始化操作
        if (isPlay) {
            this->init();
            isPlay = false;
            continue;
        }

        frameFinish = av_read_frame(avFormatContext, avPacket);
        if (frameFinish >= 0) {
            //判断当前包是视频还是音频
            int index = avPacket->stream_index;
            if (index == videoStreamIndex) {
                //解码视频流 avcodec_decode_video2 方法已被废弃
#if 0
                avcodec_decode_video2(videoCodec, avFrame2, &frameFinish, avPacket);
#else
                frameFinish = avcodec_send_packet(videoCodec, avPacket);
                if (frameFinish < 0) {
                    continue;
                }

                frameFinish = avcodec_receive_frame(videoCodec, avFrame2);
                if (frameFinish < 0) {
                    continue;
                }
#endif

                if (frameFinish >= 0) {
                    //将数据转成一张图片
                    sws_scale(swsContext, (const uint8_t* const*)avFrame2->data, avFrame2->linesize, 0, videoHeight, avFrame3->data, avFrame3->linesize);

                    //以下两种方法都可以
                    //QImage image(avFrame3->data[0], videoWidth, videoHeight, QImage::Format_RGB32);
                    QImage image((uchar*)buffer, videoWidth, videoHeight, QImage::Format_RGB32);
                    if (!image.isNull()) {
                        emit receiveImage(image);
                    }

                    msleep(1);
                }
            } else if (index == audioStreamIndex) {
                //解码音频流,这里暂不处理,以后交给sdl播放
            }
        }

        av_packet_unref(avPacket);
        av_freep(avPacket);
        msleep(1);
    }

    //线程结束后释放资源
    free();
    stopped = false;
    isPlay = false;
    qDebug() << TIMEMS << "stop ffmpeg thread";
}

void FFmpegThread::setUrl(const QString& url) {
    this->url = url;
}

void FFmpegThread::free() {
    if (swsContext != NULL) {
        sws_freeContext(swsContext);
        swsContext = NULL;
    }

    if (avPacket != NULL) {
        av_packet_unref(avPacket);
        avPacket = NULL;
    }

    if (avFrame != NULL) {
        av_frame_free(&avFrame);
        avFrame = NULL;
    }

    if (avFrame2 != NULL) {
        av_frame_free(&avFrame2);
        avFrame2 = NULL;
    }

    if (avFrame3 != NULL) {
        av_frame_free(&avFrame3);
        avFrame3 = NULL;
    }

    if (videoCodec != NULL) {
        avcodec_close(videoCodec);
        videoCodec = NULL;
    }

    if (audioCodec != NULL) {
        avcodec_close(audioCodec);
        audioCodec = NULL;
    }

    if (avFormatContext != NULL) {
        avformat_close_input(&avFormatContext);
        avFormatContext = NULL;
    }

    av_dict_free(&options);
    //qDebug() << TIMEMS << "close ffmpeg ok";
}

void FFmpegThread::play() {
    //通过标志位让线程执行初始化
    isPlay = true;
}

void FFmpegThread::pause() {

}

void FFmpegThread::next() {

}

void FFmpegThread::stop() {
    //通过标志位让线程停止
    stopped = true;
}

//实时视频显示窗体类
FFmpegWidget::FFmpegWidget(QWidget* parent) : QWidget(parent) {
    thread = new FFmpegThread(this);
    connect(thread, SIGNAL(receiveImage(QImage)), this, SLOT(updateImage(QImage)));
    image = QImage();

    flowBgColor = "#000000";
    flowPressColor = "#5EC7D9";
    borderWidth = 5;

    setFocusPolicy(Qt::StrongFocus);
    //设置支持拖放
    setAcceptDrops(true);

    this->setFlowEnable(true);
    this->initFlowPanel();
    this->initFlowStyle();

}

FFmpegWidget::~FFmpegWidget() {
    close();
}

void FFmpegWidget::paintEvent(QPaintEvent*) {
    if (image.isNull()) {
        return;
    }

    //qDebug() << TIMEMS << "paintEvent" << objectName();
    QPainter painter(this);
    painter.drawImage(this->rect(), image);
}

void FFmpegWidget::updateImage(const QImage& image) {
    //this->image = image.copy();
    this->image = image;
    this->update();
}

void FFmpegWidget::setUrl(const QString& url) {
    thread->setUrl(url);
}

void FFmpegWidget::open() {
    //qDebug() << TIMEMS << "open video" << objectName();
    clear();

    thread->play();
    thread->start();
}

void FFmpegWidget::pause() {
    thread->pause();
}

void FFmpegWidget::next() {
    thread->next();
}

void FFmpegWidget::close() {
    //qDebug() << TIMEMS << "close video" << objectName();
    if (thread->isRunning()) {
        thread->stop();
        thread->quit();
        thread->wait(500);
    }

    QTimer::singleShot(1, this, SLOT(clear()));
}

void FFmpegWidget::clear() {
    image = QImage();
    update();
}

// =================================以下是悬浮条=====================================

void FFmpegWidget::initFlowPanel() {
    //顶部工具栏,默认隐藏,鼠标移入显示移除隐藏
    flowPanel = new QWidget(this);
    flowPanel->setObjectName("flowPanel");
    flowPanel->setVisible(false);

    //用布局顶住,左侧弹簧
    QHBoxLayout* layout = new QHBoxLayout;
    layout->setSpacing(2);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addStretch();
    flowPanel->setLayout(layout);

    //按钮集合名称,如果需要新增按钮则在这里增加即可
    QList<QString> btns;
    btns << "btnFlowVideo" << "btnFlowSnap" << "btnFlowSound" << "btnFlowAlarm" << "btnFlowClose";

    //有多种办法来设置图片,qt内置的图标+自定义的图标+图形字体
    //既可以设置图标形式,也可以直接图形字体设置文本
#if 0
    QList<QIcon> icons;
    icons << QApplication::style()->standardIcon(QStyle::SP_ComputerIcon);
    icons << QApplication::style()->standardIcon(QStyle::SP_FileIcon);
    icons << QApplication::style()->standardIcon(QStyle::SP_DirIcon);
    icons << QApplication::style()->standardIcon(QStyle::SP_DialogOkButton);
    icons << QApplication::style()->standardIcon(QStyle::SP_DialogCancelButton);
#else
    QList<int> icons;
    icons << 0xe68d << 0xe672 << 0xe674 << 0xea36 << 0xe74c;

    //判断图形字体是否存在,不存在则加入
    QFont iconFont;
    QFontDatabase fontDb;
    if (!fontDb.families().contains("iconfont")) {
        int fontId = fontDb.addApplicationFont(":/res/font/iconfont.ttf");
        QStringList fontName = fontDb.applicationFontFamilies(fontId);
        if (fontName.count() == 0) {
            qDebug() << "load iconfont.ttf error";
        }
    }

    if (fontDb.families().contains("iconfont")) {
        iconFont = QFont("iconfont");
        iconFont.setPixelSize(17);
#if (QT_VERSION >= QT_VERSION_CHECK(4,8,0))
        iconFont.setHintingPreference(QFont::PreferNoHinting);
#endif
    }
#endif

    //循环添加顶部按钮
    for (int i = 0; i < btns.count(); i++) {
        QPushButton* btn = new QPushButton;
        //绑定按钮单击事件,用来发出信号通知
        //connect(btn, SIGNAL(clicked(bool)), this, SLOT(btnClicked()));
        //设置标识,用来区别按钮
        btn->setObjectName(btns.at(i));
        //设置固定宽度
        btn->setFixedWidth(20);
        //设置拉伸策略使得填充
        btn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        //设置焦点策略为无焦点,避免单击后焦点跑到按钮上
        btn->setFocusPolicy(Qt::NoFocus);

#if 0
        //设置图标大小和图标
        btn->setIconSize(QSize(16, 16));
        btn->setIcon(icons.at(i));
#else
        btn->setFont(iconFont);
        btn->setText((QChar)icons.at(i));
#endif

        //将按钮加到布局中
        layout->addWidget(btn);
    }
}

void FFmpegWidget::initFlowStyle() {
    //设置样式以便区分,可以自行更改样式,也可以不用样式
    QStringList qss;
    QString rgba = QString("rgba(%1,%2,%3,150)").arg(flowBgColor.red()).arg(flowBgColor.green()).arg(flowBgColor.blue());
    qss.append(QString("#flowPanel{background:%1;border:none;}").arg(rgba));
    qss.append(QString("QPushButton{border:none;padding:0px;background:rgba(0,0,0,0);}"));
    qss.append(QString("QPushButton:pressed{color:%1;}").arg(flowPressColor.name()));
    flowPanel->setStyleSheet(qss.join(""));
}



//void FFmpegWidget::btnClicked() {

//}

bool FFmpegWidget::getFlowEnable() const {
    return this->flowEnable;
}

QColor FFmpegWidget::getFlowBgColor() const {
    return this->flowBgColor;
}

QColor FFmpegWidget::getFlowPressColor() const {
    return this->flowPressColor;
}

void FFmpegWidget::setFlowEnable(bool flowEnable) {
    this->flowEnable = flowEnable;
}

void FFmpegWidget::setFlowBgColor(const QColor& flowBgColor) {
    if (this->flowBgColor != flowBgColor) {
        this->flowBgColor = flowBgColor;
        this->initFlowStyle();
    }
}

void FFmpegWidget::setFlowPressColor(const QColor& flowPressColor) {
    if (this->flowPressColor != flowPressColor) {
        this->flowPressColor = flowPressColor;
        this->initFlowStyle();
    }
}

void FFmpegWidget::resizeEvent(QResizeEvent*) {
    //重新设置顶部工具栏的位置和宽高,可以自行设置顶部显示或者底部显示
    int height = 20;
    flowPanel->setGeometry(borderWidth, borderWidth, this->width() - (borderWidth * 2), height);
    //flowPanel->setGeometry(borderWidth, this->height() - height - borderWidth, this->width() - (borderWidth * 2), height);

}

#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
void FFmpegWidget::enterEvent(QEnterEvent*)
#else
void FFmpegWidget::enterEvent(QEvent*)
#endif
{
    //这里还可以增加一个判断,是否获取了焦点的才需要显示
    if (this->hasFocus()) {}
    if (flowEnable) {
        flowPanel->setVisible(true);
    }
}

void FFmpegWidget::leaveEvent(QEvent*) {
    if (flowEnable) {
        flowPanel->setVisible(false);
    }
}
