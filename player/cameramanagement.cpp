#include "cameramanagement.h"
#include "ui_cameramanagement.h"

CameraManagement::CameraManagement(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::CameraManagement) {
    ui->setupUi(this);

    ui->tableInfo->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    initTable();
}

CameraManagement::~CameraManagement() {
    delete ui;
}

void CameraManagement::on_btnAdd_clicked() {
    int rowcount = ui->tableInfo->rowCount();
    ui->tableInfo->insertRow(rowcount);
}

void CameraManagement::on_btnDel_clicked() {
    int curRow = ui->tableInfo->currentRow();
    ui->tableInfo->removeRow(curRow);
}

void CameraManagement::on_btnClear_clicked() {
    int rowCount = ui->tableInfo->rowCount();
    for (int i = 0; i < rowCount; i++) {
        ui->tableInfo->removeRow(0);
    }
}

void CameraManagement::initTable() {
    appendInfo("设备1", "rtmp://hls.hsrtv.cn/hls/hstv1");
    appendInfo("设备2", "rtmp://hls.hsrtv.cn/hls/hstv2");
    ui->btnSave->click();
}

void CameraManagement::appendInfo(QString deviceName, QString url) {
    int rowCount = ui->tableInfo->rowCount();
    ui->tableInfo->insertRow(rowCount);
    QTableWidgetItem* item = new QTableWidgetItem(deviceName);
    ui->tableInfo->setItem(rowCount, 0, item);
    item = new QTableWidgetItem(url);
    ui->tableInfo->setItem(rowCount, 1, item);
}

void CameraManagement::on_btnSave_clicked() {

}
