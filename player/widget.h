#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ffmpeg.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget {
    Q_OBJECT

  public:
    explicit Widget(QWidget* parent = 0);
    ~Widget();

  private slots:
    //void on_btnOpen_clicked();

  private:
    Ui::Widget* ui;

  protected:

    void enterEvent(QEvent*) override;
    void leaveEvent(QEvent*) override;
};

#endif // WIDGET_H
