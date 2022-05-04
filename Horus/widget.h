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
    explicit Widget(QWidget* parent = nullptr);
    ~Widget() Q_DECL_OVERRIDE;

  signals:

    void btnClicked_widget_signal(const QString& str);

  private slots:
    void btnClicked_widget_slot(const QString& str);

  public:
    Ui::Widget* ui;

  protected:

    void enterEvent(QEvent*) override;
    void leaveEvent(QEvent*) override;
};

#endif // WIDGET_H
