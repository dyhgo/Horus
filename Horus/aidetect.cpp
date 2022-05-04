#include "aidetect.h"
#include "ui_aidetect.h"
#include <qtextcodec.h>
#include <QListWidget>
#include <QAbstractButton>
#include <QDialogButtonBox>
#include <iostream>


AIDetect::AIDetect(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::AIDetect) {
    ui->setupUi(this);

    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));

    timer = new QTimer(this);
    timer->setInterval(33);
    connect(timer, SIGNAL(timeout()), this, SLOT(readFrame()));
    ui->startDetect->setEnabled(false);
    ui->stopDetect->setEnabled(false);
    ui->selectDevice->setEnabled(false);
    ui->openFile->setEnabled(false);
    init();
}

AIDetect::~AIDetect() {
    capture->release();
    delete capture;
    delete [] yolo_nets;
    delete yolov5;
    delete ui;
}

void AIDetect::init() {
    capture = new cv::VideoCapture();
    yolo_nets = new NetConfig[4] {
        {0.5, 0.5, 0.5, "yolov5s"},
        {0.6f, 0.6f, 0.6f, "yolov5m"},
        {0.65f, 0.65f, 0.65f, "yolov5l"},
        {0.75, 0.75, 0.75, "yolov5x"}
    };
    conf = yolo_nets[0];
    yolov5 = new YOLOV5();
    yolov5->Initialization(conf);
    ui->textEditlog->appendPlainText(QString("默认模型类别：yolov5s args: %1 %2 %3")
                                     .arg(static_cast<double>(conf.nmsThreshold))
                                     .arg(static_cast<double>(conf.objThreshold))
                                     .arg(static_cast<double>(conf.confThreshold)));
}

void AIDetect::readFrame() {
    cv::Mat frame;
    capture->read(frame);
    if (frame.empty()) return;

    auto start = std::chrono::steady_clock::now();
    yolov5->detect(frame);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    ui->textEditlog->appendPlainText(QString("cost_time: %1 ms").arg(elapsed.count()));

//    double t0 = static_cast<double>(cv::getTickCount());
//    yolov5->detect(frame);
//    double t1 = static_cast<double>(cv::getTickCount());
//    ui->textEditlog->append(QStringLiteral("cost_time: %1 ").arg((t1 - t0) / cv::getTickFrequency()));

    cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
    QImage rawImage = QImage(static_cast<uchar*>((frame.data)), frame.cols, frame.rows, static_cast<int>(frame.step), QImage::Format_RGB888);
    ui->lab_video->setPixmap(QPixmap::fromImage(rawImage).scaled(ui->lab_video->width(), ui->lab_video->height()));
}


void AIDetect::initSelectDeviceDialog(QDialog* dialog) {

    dialog->setWindowTitle("选择设备");
    listWidget = new QListWidget(this);
    QDialogButtonBox* box = new QDialogButtonBox(dialog);
    QPushButton* btn = new QPushButton("确定");
    //btn->setDefault(true);
    //btn->setAutoDefault(false);
    btn->setFixedSize(150, 40);
    box->addButton(btn, QDialogButtonBox::YesRole);
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(listWidget);
    layout->addWidget(box);
    dialog->setLayout(layout);
    //dialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    //dialog->setWindowFlags(Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    dialog->setWindowFlag(Qt::WindowContextHelpButtonHint, false);
    dialog->setFixedSize(300, 300);
    connect(box, SIGNAL(accepted()), dialog, SLOT(accept()));
}



void AIDetect::on_selectDevice_clicked() {
    //qDebug() << m_mainwindow->map.count() << '\n';
    // 模态显示
    if (dialog == nullptr) {
        dialog = new QDialog(this);
        initSelectDeviceDialog(dialog);
    }



    listWidget->clear();
    foreach(const QString& str, m_mainwindow->map.keys()) {
        QListWidgetItem* item = new QListWidgetItem();  // 这句话不能放在循环外，否则只有一个
        item->setData(Qt::DisplayRole, str);
        listWidget->addItem(item);
    }
    listWidget->sortItems();
    int ret = dialog->exec();
    if (ret == QDialog::Accepted) {
        QListWidgetItem* item = listWidget->currentItem();
        if (item == nullptr || item->text().isEmpty()) {
            return ;
        }
        std::string url = m_mainwindow->map[item->text()].toStdString();
        capture->open(url);
        ui->lab_msg->setText(QString::fromStdString(url));
        if (!capture->isOpened()) {
            ui->textEditlog->appendPlainText("fail to open MP4!\n");
            return;
        }
        ui->openFile->setEnabled(false);
        ui->loadFile->setEnabled(false);
        ui->startDetect->setEnabled(true);
        ui->textEditlog->appendPlainText(QString("Open video: %1 succesfully!").arg(QString::fromStdString(url)));
        //获取整个帧数QStringLiteral
        long totalFrame = static_cast<long>(capture->get(cv::CAP_PROP_FRAME_COUNT));
        int width = static_cast<int>(capture->get(cv::CAP_PROP_FRAME_WIDTH));
        int height = static_cast<int>(capture->get(cv::CAP_PROP_FRAME_HEIGHT));
        ui->textEditlog->appendPlainText(QString("整个视频共 %1 帧, 宽=%2 高=%3 ").arg(totalFrame).arg(width).arg(height));
        //ui->lab_video->resize(QSize(width, height));

        //设置开始帧()
        long frameToStart = 0;
        capture->set(cv::CAP_PROP_POS_FRAMES, frameToStart);
        ui->textEditlog->appendPlainText(QString("从第 %1 帧开始读").arg(frameToStart));

        //获取帧率
        double rate = capture->get(cv::CAP_PROP_FPS);
        ui->textEditlog->appendPlainText(QString("帧率为: %1 ").arg(rate));
    }
}

void AIDetect::on_openFile_clicked() {
    QString filename = QFileDialog::getOpenFileName(this, QString("打开文件"), ".", "*.mp4 *.avi;;*.png *.jpg *.jpeg *.bmp");
    if(!QFile::exists(filename)) {
        return;
    }
    //QString filename = "rtmp://10.196.80.19:1935/record/DJI_1.MP4";
    ui->lab_msg->setText(filename);

    QMimeDatabase db;
    QMimeType mime = db.mimeTypeForFile(filename);
    if (mime.name().startsWith("image/")) {
        cv::Mat src = cv::imread(filename.toLatin1().data());
        if(src.empty()) {
            ui->lab_msg->setText("图像不存在！");
            return;
        }

        ui->selectDevice->setEnabled(false);
        ui->startDetect->setEnabled(true);

        cv::Mat temp;
        if(src.channels() == 4)
            cv::cvtColor(src, temp, cv::COLOR_BGRA2RGB);
        else if (src.channels() == 3)
            cv::cvtColor(src, temp, cv::COLOR_BGR2RGB);
        else
            cv::cvtColor(src, temp, cv::COLOR_GRAY2RGB);

        auto start = std::chrono::steady_clock::now();
        yolov5->detect(temp);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        ui->textEditlog->appendPlainText(QString("cost_time: %1 ms").arg(elapsed.count()));
        QImage img = QImage(static_cast<uchar*>(temp.data), temp.cols, temp.rows, static_cast<int>(temp.step), QImage::Format_RGB888);
        ui->lab_video->setPixmap(QPixmap::fromImage(img));
        //ui->lab_video->resize(ui->lab_video->pixmap()->size());
        filename.clear();
    } else if (mime.name().startsWith("video/")) {
        //filename = "rtmp://10.196.80.19:1935/record/DJI_1.MP4";
        capture->open(filename.toLatin1().data());
        //capture->open("rtmp://10.196.80.19:1935/record/DJI_1.MP4");
        //std::cout << filename.toStdString() << '\n';
        //capture = new cv::VideoCapture("rtmp://10.196.80.19:1935/record/DJI_1.MP4");
        //ui->textEditlog->append(QString::fromStdString(cv::getBuildInformation()));
        if (!capture->isOpened()) {
            ui->textEditlog->appendPlainText("fail to open MP4!\n");
            return;
        }
        //IsDetect_ok += 1;
//        if (IsDetect_ok == 2)
//            ui->startDetect->setEnabled(true);

        ui->selectDevice->setEnabled(false);
        ui->startDetect->setEnabled(true);
        ui->textEditlog->appendPlainText(QString::fromUtf8("Open video: %1 succesfully!").arg(filename));

        //获取整个帧数QStringLiteral
        long totalFrame = static_cast<long>(capture->get(cv::CAP_PROP_FRAME_COUNT));
        int width = static_cast<int>(capture->get(cv::CAP_PROP_FRAME_WIDTH));
        int height = static_cast<int>(capture->get(cv::CAP_PROP_FRAME_HEIGHT));
        ui->textEditlog->appendPlainText(QString("整个视频共 %1 帧, 宽=%2 高=%3 ").arg(totalFrame).arg(width).arg(height));
        //ui->lab_video->resize(QSize(width, height));

        //设置开始帧()
        long frameToStart = 0;
        capture->set(cv::CAP_PROP_POS_FRAMES, frameToStart);
        ui->textEditlog->appendPlainText(QString("从第 %1 帧开始读").arg(frameToStart));

        //获取帧率
        double rate = capture->get(cv::CAP_PROP_FPS);
        ui->textEditlog->appendPlainText(QString("帧率为: %1 ").arg(rate));
    }
}

void AIDetect::on_loadFile_clicked() {
    QString onnxFile = QFileDialog::getOpenFileName(this, QString("选择模型"), ".", "*.onnx");
    if(!QFile::exists(onnxFile)) {
        return;
    }
    ui->lab_msg->setText(onnxFile);
    if (!yolov5->loadModel(onnxFile.toLatin1().data())) {
        ui->textEditlog->appendPlainText(QString("加载模型失败！"));
        return;
    }
    //IsDetect_ok += 1;
    ui->openFile->setEnabled(true);
    ui->selectDevice->setEnabled(true);
    ui->loadFile->setEnabled(false);
    ui->textEditlog->appendPlainText(QString::fromUtf8("Open onnxFile: %1 succesfully!").arg(onnxFile));
//    if (IsDetect_ok == 2)
//        ui->startDetect->setEnabled(true);
}

void AIDetect::on_model_activated(const QString& arg1) {
    if (arg1.contains("s")) {
        conf = yolo_nets[0];
    } else if (arg1.contains("m")) {
        conf = yolo_nets[1];
    } else if (arg1.contains("l")) {
        conf = yolo_nets[2];
    } else if (arg1.contains("x")) {
        conf = yolo_nets[3];
    }
    yolov5->Initialization(conf);
    ui->textEditlog->appendPlainText(QString("使用模型类别：%1 args: %2 %3 %4")
                                     .arg(arg1)
                                     .arg(static_cast<double>(conf.nmsThreshold))
                                     .arg(static_cast<double>(conf.objThreshold))
                                     .arg(static_cast<double>(conf.confThreshold)));
}



void AIDetect::on_startDetect_clicked() {
    timer->start();
    ui->selectDevice->setEnabled(false);
    ui->openFile->setEnabled(false);
    ui->loadFile->setEnabled(false);
    ui->model->setEnabled(false);
    ui->reset->setEnabled(true);
    ui->startDetect->setEnabled(false);
    ui->stopDetect->setEnabled(true);
    ui->textEditlog->appendPlainText(QString("================\n"
                                     "    开始检测\n"
                                     "================\n"));
}

void AIDetect::on_stopDetect_clicked() {
    ui->selectDevice->setEnabled(false);
    ui->openFile->setEnabled(false);
    ui->loadFile->setEnabled(false);
    ui->model->setEnabled(false);
    ui->reset->setEnabled(true);
    ui->startDetect->setEnabled(true);
    ui->stopDetect->setEnabled(false);
    timer->stop();
    ui->textEditlog->appendPlainText(QString("==============\n"
                                     "    停止检测\n"
                                     "==============\n"));
}

void AIDetect::on_reset_clicked() {
    ui->stopDetect->click();
    ui->textEditlog->clear();
//    QList<QPushButton*> btns = ui->widget->findChildren<QPushButton*>();
//    foreach (QPushButton* btn, btns) {
//        btn->setEnabled(true);
//    }
    ui->selectDevice->setEnabled(false);
    ui->openFile->setEnabled(false);
    ui->loadFile->setEnabled(true);
    ui->model->setEnabled(true);
    ui->startDetect->setEnabled(false);
    ui->stopDetect->setEnabled(false);
    ui->lab_video->clear();
    //capture->release();
    ui->textEditlog->appendPlainText(QString("==============\n"
                                     "    重置\n"
                                     "==============\n"));
}




