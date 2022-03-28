#ifndef CAMERAMANAGEMENT_H
#define CAMERAMANAGEMENT_H

#include <QWidget>

namespace Ui {
class CameraManagement;
}

class CameraManagement : public QWidget
{
    Q_OBJECT

public:
    explicit CameraManagement(QWidget *parent = 0);
    ~CameraManagement();

private:
    Ui::CameraManagement *ui;
};

#endif // CAMERAMANAGEMENT_H
