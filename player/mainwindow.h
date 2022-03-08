#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

    void hide_all_videos();

  private slots:
    void on_btnOne_clicked();

    void on_btnFour_clicked();

    void on_btnNine_clicked();

    void on_btnSixteen_clicked();

  private:
    Ui::MainWindow* ui;

    QVector<Widget*> widgets;
};

#endif // MAINWINDOW_H
