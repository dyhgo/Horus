#ifndef FFMPEG_H
#define FFMPEG_H

#include <QWidget>
#include <QDateTime>
#include <QtGui>
#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#endif

#include "ffmpeghead.h"

class FFmpegThread : public QThread {
    Q_OBJECT


  public:
    explicit FFmpegThread(QObject* parent = 0);
    static void initlib();

  protected:
    void run();

  private:
    volatile bool stopped;          //线程停止标志位
    volatile bool isPlay;           //播放视频标志位

    int frameFinish;                //一帧完成
    int videoWidth;                 //视频宽度
    int videoHeight;                //视频高度
    int oldWidth;                   //上一次视频宽度
    int oldHeight;                  //上一次视频高度
    int videoStreamIndex;           //视频流索引
    int audioStreamIndex;           //音频流索引

    QString url;                    //视频流地址

    uint8_t* buffer;                //存储解码后图片buffer
    AVPacket* avPacket;             //包对象
    AVFrame* avFrame;               //帧对象
    AVFrame* avFrame2;              //帧对象
    AVFrame* avFrame3;              //帧对象
    AVFormatContext* avFormatContext;//格式对象
    AVCodecContext* videoCodec;     //视频解码器
    AVCodecContext* audioCodec;     //音频解码器
    SwsContext* swsContext;         //处理图片数据对象

    AVDictionary* options;          //参数对象
    AVCodec* videoDecoder;          //视频解码
    AVCodec* audioDecoder;          //音频解码

  signals:
    //收到图片信号
    void receiveImage(const QImage& image);

  public slots:
    //设置视频流地址
    void setUrl(const QString& url);

    //初始化视频对象
    bool init();
    //释放对象
    void free();
    //播放视频对象
    void play();
    //暂停播放
    void pause();
    //继续播放
    void next();
    //停止采集线程
    void stop();
};

//实时视频显示窗体类
class FFmpegWidget : public QWidget {
    Q_OBJECT
    Q_PROPERTY(bool flowEnable READ getFlowEnable WRITE setFlowEnable)
    Q_PROPERTY(QColor flowBgColor READ getFlowBgColor WRITE setFlowBgColor)
    Q_PROPERTY(QColor flowPressColor READ getFlowPressColor WRITE setFlowPressColor)
  public:
    explicit FFmpegWidget(QWidget* parent = 0);
    ~FFmpegWidget();

  protected:
    void paintEvent(QPaintEvent*);

  private:
    FFmpegThread* thread;
    QImage image;

  private slots:
    //接收图像并绘制
    void updateImage(const QImage& image);

  public slots:
    //设置视频流地址
    void setUrl(const QString& url);

    //打开设备
    void open();
    //暂停
    void pause();
    //继续
    void next();
    //关闭设备
    void close();
    //清空
    void clear();

// =================================以下是悬浮条=====================================

  public:


    //初始化悬浮条
    void initFlowPanel();
    //初始化悬浮条样式
    void initFlowStyle();



  private:

    QWidget* flowPanel;             //悬浮条面板
    QColor flowBgColor;             //悬浮条背景颜色
    QColor flowPressColor;          //悬浮条按下颜色
    bool flowEnable;                //是否显示悬浮条

    int borderWidth;                //边框宽度

  signals:

    void btnClicked_ffmpeg_signal(const QString& str);

  private slots:

    //处理按钮单击
    void btnClicked_ffmpeg_slot();

  public:

    bool getFlowEnable()            const;
    QColor getFlowBgColor()         const;
    QColor getFlowPressColor()      const;




  public slots:

    //设置是否启用悬浮条
    void setFlowEnable(bool flowEnable);
    //设置悬浮条背景颜色
    void setFlowBgColor(const QColor& flowBgColor);
    //设置悬浮条按下颜色
    void setFlowPressColor(const QColor& flowPressColor);

    // 关键代码
  protected:
    void resizeEvent(QResizeEvent*);
#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
    void enterEvent(QEnterEvent*);
#else
    void enterEvent(QEvent*);
#endif
    void leaveEvent(QEvent*);


};

#endif // FFMPEG_H
