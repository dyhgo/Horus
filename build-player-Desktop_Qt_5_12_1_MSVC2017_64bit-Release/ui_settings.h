/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widgetLeft;
    QVBoxLayout *verticalLayout;
    QToolButton *btnSysSettings;
    QToolButton *btnCameraManagement;
    QSpacerItem *verticalSpacer;
    QGridLayout *settingsInterface;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(867, 535);
        gridLayout_2 = new QGridLayout(Settings);
        gridLayout_2->setSpacing(1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(1, 1, 1, 1);
        widgetLeft = new QWidget(Settings);
        widgetLeft->setObjectName(QString::fromUtf8("widgetLeft"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetLeft->sizePolicy().hasHeightForWidth());
        widgetLeft->setSizePolicy(sizePolicy);
        widgetLeft->setMinimumSize(QSize(90, 0));
        widgetLeft->setMaximumSize(QSize(90, 16777215));
        verticalLayout = new QVBoxLayout(widgetLeft);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        btnSysSettings = new QToolButton(widgetLeft);
        btnSysSettings->setObjectName(QString::fromUtf8("btnSysSettings"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnSysSettings->sizePolicy().hasHeightForWidth());
        btnSysSettings->setSizePolicy(sizePolicy1);
        btnSysSettings->setMinimumSize(QSize(0, 70));

        verticalLayout->addWidget(btnSysSettings);

        btnCameraManagement = new QToolButton(widgetLeft);
        btnCameraManagement->setObjectName(QString::fromUtf8("btnCameraManagement"));
        sizePolicy1.setHeightForWidth(btnCameraManagement->sizePolicy().hasHeightForWidth());
        btnCameraManagement->setSizePolicy(sizePolicy1);
        btnCameraManagement->setMinimumSize(QSize(0, 70));

        verticalLayout->addWidget(btnCameraManagement);

        verticalSpacer = new QSpacerItem(20, 386, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_2->addWidget(widgetLeft, 0, 0, 1, 1);

        settingsInterface = new QGridLayout();
        settingsInterface->setObjectName(QString::fromUtf8("settingsInterface"));

        gridLayout_2->addLayout(settingsInterface, 0, 1, 1, 1);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Form", nullptr));
        btnSysSettings->setText(QApplication::translate("Settings", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        btnCameraManagement->setText(QApplication::translate("Settings", "\346\221\204\345\203\217\346\234\272\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
