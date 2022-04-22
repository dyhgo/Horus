/********************************************************************************
** Form generated from reading UI file 'selectdevicedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTDEVICEDIALOG_H
#define UI_SELECTDEVICEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectDeviceDialog
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;

    void setupUi(QDialog *SelectDeviceDialog)
    {
        if (SelectDeviceDialog->objectName().isEmpty())
            SelectDeviceDialog->setObjectName(QString::fromUtf8("SelectDeviceDialog"));
        SelectDeviceDialog->resize(517, 410);
        buttonBox = new QDialogButtonBox(SelectDeviceDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(270, 80, 171, 321));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listWidget = new QListWidget(SelectDeviceDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 20, 201, 241));

        retranslateUi(SelectDeviceDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SelectDeviceDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SelectDeviceDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SelectDeviceDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectDeviceDialog)
    {
        SelectDeviceDialog->setWindowTitle(QApplication::translate("SelectDeviceDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectDeviceDialog: public Ui_SelectDeviceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTDEVICEDIALOG_H
