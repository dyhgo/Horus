/********************************************************************************
** Form generated from reading UI file 'syssettings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSSETTINGS_H
#define UI_SYSSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SysSettings
{
public:

    void setupUi(QWidget *SysSettings)
    {
        if (SysSettings->objectName().isEmpty())
            SysSettings->setObjectName(QString::fromUtf8("SysSettings"));
        SysSettings->resize(652, 419);
        SysSettings->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(SysSettings);

        QMetaObject::connectSlotsByName(SysSettings);
    } // setupUi

    void retranslateUi(QWidget *SysSettings)
    {
        SysSettings->setWindowTitle(QApplication::translate("SysSettings", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SysSettings: public Ui_SysSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSSETTINGS_H
