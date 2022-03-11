#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

  private:

    void setActionForButton();

  public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

    void hide_all_videos();

  private slots:


    void on_actOne_triggered();

    void on_actFour_triggered();

    void on_actNine_triggered();

    void on_actSixteen_triggered();

    void on_MainWindow_customContextMenuRequested(const QPoint& pos);

  private:
    Ui::MainWindow* ui;

    QVector<Widget*> widgets;
};

#endif // MAINWINDOW_H
