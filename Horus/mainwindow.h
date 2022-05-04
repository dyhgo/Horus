#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
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
class MainWindow;
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

class MainWindow : public QWidget {
    Q_OBJECT

  public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() Q_DECL_OVERRIDE;

  private:

    void region(const QPoint& cursorGlobalPoint);
    void init();
    void iconSet();

  protected:

    void mouseReleaseEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    bool eventFilter(QObject* watched, QEvent* event) Q_DECL_OVERRIDE;

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
    Ui::MainWindow* ui;


  public:
    QHash<QString, QString> map;
    QTreeWidget* treeWidget;

};

#endif // MAINWINDOW_H
