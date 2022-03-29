#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include "syssettings.h"
#include "cameramanagement.h"
#include <QToolButton>


namespace Ui {
class Settings;
}

class Settings : public QWidget {
    Q_OBJECT

  public:
    explicit Settings(QWidget* parent = 0);
    ~Settings();

  private slots:
    void on_btnSysSettings_clicked();

    void on_btnCameraManagement_clicked();

  private:
    Ui::Settings* ui;

    QList<QToolButton*> btnsLeft;
    SysSettings* ss;
    CameraManagement* cm;
};

#endif // SETTINGS_H
