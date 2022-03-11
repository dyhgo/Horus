#include "playback.h"
#include "ui_playback.h"

Playback::Playback(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Playback)
{
    ui->setupUi(this);
}

Playback::~Playback()
{
    delete ui;
}
