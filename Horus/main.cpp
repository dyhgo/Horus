#pragma execution_character_set("utf-8")
#include "widget.h"
#include <QApplication>
#include <QTextCodec>
#include "mainwindow.h"
#include "monitor.h"
#include "appinit.h"
#include <QFile>


int main(int argc, char* argv[]) {
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication a(argc, argv);


    QFont font;
    font.setFamily("MicroSoft Yahei");
    font.setPixelSize(12);
    a.setFont(font);

#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
#if _MSC_VER
    QTextCodec* codec = QTextCodec::codecForName("gbk");
#else
    QTextCodec* codec = QTextCodec::codecForName("utf-8");
#endif
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#else
    QTextCodec* codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
#endif

    //AppInit::Instance()->start();

//    Widget w;
//    w.setWindowTitle("视频流播放ffmpeg内核");
//    w.show();

//    MainWindow w;
//    w.setWindowTitle("视频流播放ffmpeg内核");
//    w.show();


    QFile file("qdarkstyle.qss");
    file.open(QIODevice::ReadOnly);
    QString styleSheet = QString::fromLatin1(file.readAll());
    a.setStyleSheet(styleSheet);
    file.close();
    MainWindow mainwindow;
    mainwindow.resize(1400, 900);
    mainwindow.show();


    return a.exec();
}
