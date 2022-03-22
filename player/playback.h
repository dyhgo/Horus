#ifndef PLAYBACK_H
#define PLAYBACK_H

#include <QWidget>

namespace Ui {
class Playback;
}

class Playback : public QWidget {
    Q_OBJECT

  public:
    explicit Playback(QWidget* parent = 0);
    ~Playback();

  private:
    Ui::Playback* ui;
};

#endif // PLAYBACK_H
