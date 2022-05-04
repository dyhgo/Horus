#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include "syssettings.h"
#include "cameramanagement.h"
#include <QToolButton>
#include "mainwindow.h"


namespace Ui {
class Settings;
}

class Settings : public QWidget {
    Q_OBJECT

  public:
    explicit Settings(MainWindow* w, QWidget* parent = nullptr);
    ~Settings();

  private slots:
    void on_btnSysSettings_clicked();

    void on_btnCameraManagement_clicked();

  private:
    Ui::Settings* ui;

    QList<QToolButton*> btnsLeft;
    SysSettings* ss;
    CameraManagement* cm;

    MainWindow* m_mainwindow;
};

#endif // SETTINGS_H
