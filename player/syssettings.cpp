#include "syssettings.h"
#include "ui_syssettings.h"

SysSettings::SysSettings(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::SysSettings) {
    ui->setupUi(this);
}

SysSettings::~SysSettings() {
    delete ui;
}
