#include "realmainwindow.h"
#include "ui_realmainwindow.h"
#include <QTabWidget>


RealMainWindow::RealMainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::RealMainWindow) {
    ui->setupUi(this);
    MainWindow* w = new MainWindow();
    ui->tabWidget->clear();
    ui->tabWidget->addTab(w, "视频监控界面");
    ui->tabWidget->setCurrentIndex(0);

    Playback* p = new Playback();
    ui->tabWidget->addTab(p, "视频回放界面");
}

RealMainWindow::~RealMainWindow() {
    delete ui;
}
