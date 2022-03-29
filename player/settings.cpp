#include "settings.h"
#include "ui_settings.h"

Settings::Settings(RealMainWindow* w, QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Settings),
    m_realmainwindow(w) {
    ui->setupUi(this);

    btnsLeft << ui->btnSysSettings << ui->btnCameraManagement;
    ss = new SysSettings();
    cm = new CameraManagement(w);
    foreach (QToolButton* btn, btnsLeft) {
        btn->setCheckable(true);
    }
    ui->btnSysSettings->setChecked(true);
    ui->btnSysSettings->click();
}

Settings::~Settings() {
    delete ui;
    delete &btnsLeft;
    delete ss;
    delete cm;
}

void Settings::on_btnSysSettings_clicked() {
    foreach (QToolButton* btn, btnsLeft) {
        btn->setChecked(btn == ui->btnSysSettings);
    }

    ui->settingsInterface->removeWidget(cm);
    cm->setVisible(false);
    ui->settingsInterface->addWidget(ss, 0, 0);
    ss->setVisible(true);
}

void Settings::on_btnCameraManagement_clicked() {
    foreach (QToolButton* btn, btnsLeft) {
        btn->setChecked(btn == ui->btnCameraManagement);
    }
    ui->settingsInterface->removeEventFilter(ss);
    ss->setVisible(false);
    ui->settingsInterface->addWidget(cm, 0, 0);
    cm->setVisible(true);
}
