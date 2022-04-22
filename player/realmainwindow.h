#ifndef REALMAINWINDOW_H
#define REALMAINWINDOW_H

#include <QWidget>
//#include "mainwindow.h"
//#include "playback.h"
//#include "settings.h"
#include <QMouseEvent>
#include <QPoint>
#include <QCursor>
#include <QRect>
#include <QDebug>
#include <iostream>
#include <QHash>
#include <QTreeWidget>



#define PADDING 2

namespace Ui {
class RealMainWindow;
}

enum Direction {
    TOP = 0,
    BOTTOM = 1,
    LEFT,
    RIGHT,
    TOPLEFT,
    BOTTOMLEFT,
    TOPRIGHT,
    BOTTOMRIGHT,
    NONE
};

class RealMainWindow : public QWidget {
    Q_OBJECT

  public:
    explicit RealMainWindow(QWidget* parent = 0);
    ~RealMainWindow();

  private:

    void region(const QPoint& cursorGlobalPoint);
    void init();
    void iconSet();

  protected:

    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

    bool eventFilter(QObject* watched, QEvent* event) override;

  private:

    bool isLeftButtonPressed;
    QPoint mousePoint;
    Direction dir;

  private slots:


    void on_btnClose_clicked();

    void on_btnMaximize_clicked();

    void on_btnMinimize_clicked();
    void btnClicked();

  private:
    Ui::RealMainWindow* ui;


  public:
    QHash<QString, QString> map;
    QTreeWidget* treeWidget;

};

#endif // REALMAINWINDOW_H
