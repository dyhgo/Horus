#ifndef PLAYBACK_H
#define PLAYBACK_H

#include <QMainWindow>

namespace Ui {
class Playback;
}

class Playback : public QMainWindow
{
    Q_OBJECT

public:
    explicit Playback(QWidget *parent = 0);
    ~Playback();

private:
    Ui::Playback *ui;
};

#endif // PLAYBACK_H
