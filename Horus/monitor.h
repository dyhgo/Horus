#ifndef MONITOR_H
#define MONITOR_H

#include <QWidget>
#include <QHash>
#include "widget.h"
#include "ffmpeg.h"
#include "mainwindow.h"

namespace Ui {
class Monitor;
}

class Monitor : public QWidget {
    Q_OBJECT

  private:

    void setActionForButton();
    void init();
    void btnCheckSet(QToolButton*);

  public:
    explicit Monitor(MainWindow* w, QWidget* parent = nullptr);
    ~Monitor() Q_DECL_OVERRIDE;

    void hide_all_videos();

  private slots:


    void on_actOne_triggered();

    void on_actFour_triggered();

    void on_actNine_triggered();

    void on_actSixteen_triggered();

    void on_Monitor_customContextMenuRequested(const QPoint& pos);

    void btnClicked_monitor_slot(const QString& objName);


  public:
    Ui::Monitor* ui;

    QVector<Widget*> widgets;

    MainWindow* m_mainwindow;


};

#endif // MONITOR_H
