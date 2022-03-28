#ifndef SYSSETTINGS_H
#define SYSSETTINGS_H

#include <QWidget>

namespace Ui {
class SysSettings;
}

class SysSettings : public QWidget
{
    Q_OBJECT

public:
    explicit SysSettings(QWidget *parent = 0);
    ~SysSettings();

private:
    Ui::SysSettings *ui;
};

#endif // SYSSETTINGS_H
