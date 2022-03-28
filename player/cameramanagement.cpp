#include "cameramanagement.h"
#include "ui_cameramanagement.h"

CameraManagement::CameraManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CameraManagement)
{
    ui->setupUi(this);
}

CameraManagement::~CameraManagement()
{
    delete ui;
}
