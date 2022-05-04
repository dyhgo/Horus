#ifndef CAMERAMANAGEMENT_H
#define CAMERAMANAGEMENT_H

#include <QWidget>
#include <QSet>
#include <QMessageBox>
#include "mainwindow.h"

namespace Ui {
class CameraManagement;
}

class CameraManagement : public QWidget {
    Q_OBJECT

  public:
    explicit CameraManagement(MainWindow* w, QWidget* parent = nullptr);
    ~CameraManagement();

  private slots:
    void on_btnAdd_clicked();

    void on_btnDel_clicked();

    void on_btnClear_clicked();

    void on_btnSave_clicked();

  private:
    Ui::CameraManagement* ui;

    void initTable();
    void appendInfo(QString deviceName, QString url);
    void clearEmptyRow();
    bool existEmptyCell();
    bool existDuplicateDevice();
    void saveInfo();

    MainWindow* m_mainwindow;
};

#endif // CAMERAMANAGEMENT_H
