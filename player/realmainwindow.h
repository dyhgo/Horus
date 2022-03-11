#ifndef REALMAINWINDOW_H
#define REALMAINWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "playback.h"

namespace Ui {
class RealMainWindow;
}

class RealMainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit RealMainWindow(QWidget* parent = 0);
    ~RealMainWindow();

  private:
    Ui::RealMainWindow* ui;
};

#endif // REALMAINWINDOW_H
