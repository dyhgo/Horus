#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QHash>
#include "widget.h"
#include "ffmpeg.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget {
    Q_OBJECT

  private:

    void setActionForButton();
    void init();

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

    void btnClicked_mainwindow_slot(const QString& objName);

  private:
    Ui::MainWindow* ui;

    QVector<Widget*> widgets;
    QHash<QString, QString> map;
};

#endif // MAINWINDOW_H
