#ifndef SELECTDEVICEDIALOG_H
#define SELECTDEVICEDIALOG_H

#include <QDialog>

namespace Ui {
class SelectDeviceDialog;
}

class SelectDeviceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectDeviceDialog(QWidget *parent = nullptr);
    ~SelectDeviceDialog();

private:
    Ui::SelectDeviceDialog *ui;
};

#endif // SELECTDEVICEDIALOG_H
