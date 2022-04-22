#include "cameramanagement.h"
#include "ui_cameramanagement.h"
#include <qtextcodec.h>


CameraManagement::CameraManagement(RealMainWindow* w, QWidget* parent) :
    QWidget(parent),
    ui(new Ui::CameraManagement),
    m_realmainwindow(w) {
    ui->setupUi(this);
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));

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
    appendInfo(QStringLiteral("设备1"), "rtmp://hls.hsrtv.cn/hls/hstv1");
    appendInfo(QStringLiteral("设备2"), "rtmp://hls.hsrtv.cn/hls/hstv2");
    appendInfo(QStringLiteral("设备3"), "rtmp://10.196.80.19:1935/record/DJI_1.MP4");
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

void CameraManagement::clearEmptyRow() {
    QTableWidgetItem* item;
    for (int i = 0; i < ui->tableInfo->rowCount(); i++) {
        bool allEmpty = true;
        for (int j = 0; j < ui->tableInfo->columnCount(); j++) {
            item = ui->tableInfo->item(i, j);
            if (!(item == nullptr || item->text().isEmpty())) {
                allEmpty = false;
                break;
            }
        }
        if (allEmpty) {
            ui->tableInfo->removeRow(i);
            i--;
        }
    }
}

bool CameraManagement::existEmptyCell() {
    QTableWidgetItem* item;
    for (int i = 0; i < ui->tableInfo->rowCount(); i++) {
        for (int j = 0; j < ui->tableInfo->columnCount(); j++) {
            item = ui->tableInfo->item(i, j);
            if (item == nullptr || item->text().isEmpty()) {
                return true;
            }
        }
    }
    return false;
}

bool CameraManagement::existDuplicateDevice() {
    QSet<QString> set;
    for (int i = 0; i < ui->tableInfo->rowCount(); i++) {
        set.insert(ui->tableInfo->item(i, 0)->text());
    }
    return set.size() < ui->tableInfo->rowCount();
}

void CameraManagement::saveInfo() {
    m_realmainwindow->map.clear();
    m_realmainwindow->treeWidget->clear();
    QTreeWidgetItem* item;
    for (int i = 0; i < ui->tableInfo->rowCount(); i++) {
        QTableWidgetItem* item1, *item2;
        item1 = ui->tableInfo->item(i, 0);
        item2 = ui->tableInfo->item(i, 1);
        m_realmainwindow->map.insert(item1->text(), item2->text());
        item = new QTreeWidgetItem(m_realmainwindow->treeWidget);
        item->setText(0, item1->text());
        m_realmainwindow->treeWidget->addTopLevelItem(item);
    }
}



void CameraManagement::on_btnSave_clicked() {
    if (existEmptyCell()) {
        QMessageBox::critical(this, QStringLiteral("摄像头管理 - 错误"), QStringLiteral("存在空项，无法保存"));
    } else if (existDuplicateDevice()) {
        QMessageBox::critical(this, QStringLiteral("摄像头管理 - 错误"), QStringLiteral("存在同名设备，无法保存"));
    } else {
        saveInfo();
    }
}
