/********************************************************************************
** Form generated from reading UI file 'realmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REALMAINWINDOW_H
#define UI_REALMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RealMainWindow
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labIcon;
    QLabel *labTitle;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QToolButton *btnMonitor;
    QToolButton *btnPlayback;
    QToolButton *btnSettings;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QPushButton *btnMinimize;
    QPushButton *btnMaximize;
    QPushButton *btnClose;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *RealMainWindow)
    {
        if (RealMainWindow->objectName().isEmpty())
            RealMainWindow->setObjectName(QString::fromUtf8("RealMainWindow"));
        RealMainWindow->resize(800, 600);
        RealMainWindow->setMinimumSize(QSize(500, 100));
        RealMainWindow->setCursor(QCursor(Qt::ArrowCursor));
        RealMainWindow->setMouseTracking(true);
        gridLayout_2 = new QGridLayout(RealMainWindow);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(1, 1, 1, 1);
        widgetTitle = new QWidget(RealMainWindow);
        widgetTitle->setObjectName(QString::fromUtf8("widgetTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetTitle->sizePolicy().hasHeightForWidth());
        widgetTitle->setSizePolicy(sizePolicy);
        widgetTitle->setMinimumSize(QSize(0, 70));
        widgetTitle->setMaximumSize(QSize(16777215, 70));
        horizontalLayout_2 = new QHBoxLayout(widgetTitle);
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labIcon = new QLabel(widgetTitle);
        labIcon->setObjectName(QString::fromUtf8("labIcon"));

        horizontalLayout_2->addWidget(labIcon);

        labTitle = new QLabel(widgetTitle);
        labTitle->setObjectName(QString::fromUtf8("labTitle"));

        horizontalLayout_2->addWidget(labTitle);

        horizontalSpacer = new QSpacerItem(424, 38, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widget = new QWidget(widgetTitle);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        btnMonitor = new QToolButton(widget);
        btnMonitor->setObjectName(QString::fromUtf8("btnMonitor"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnMonitor->sizePolicy().hasHeightForWidth());
        btnMonitor->setSizePolicy(sizePolicy2);
        btnMonitor->setPopupMode(QToolButton::InstantPopup);

        horizontalLayout->addWidget(btnMonitor);

        btnPlayback = new QToolButton(widget);
        btnPlayback->setObjectName(QString::fromUtf8("btnPlayback"));
        sizePolicy2.setHeightForWidth(btnPlayback->sizePolicy().hasHeightForWidth());
        btnPlayback->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(btnPlayback);

        btnSettings = new QToolButton(widget);
        btnSettings->setObjectName(QString::fromUtf8("btnSettings"));
        sizePolicy2.setHeightForWidth(btnSettings->sizePolicy().hasHeightForWidth());
        btnSettings->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(btnSettings);


        horizontalLayout_2->addWidget(widget);

        widget_2 = new QWidget(widgetTitle);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        widget_2->setMaximumSize(QSize(70, 16777215));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnMinimize = new QPushButton(widget_2);
        btnMinimize->setObjectName(QString::fromUtf8("btnMinimize"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnMinimize->sizePolicy().hasHeightForWidth());
        btnMinimize->setSizePolicy(sizePolicy3);
        btnMinimize->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(btnMinimize, 0, 0, 1, 1);

        btnMaximize = new QPushButton(widget_2);
        btnMaximize->setObjectName(QString::fromUtf8("btnMaximize"));
        sizePolicy3.setHeightForWidth(btnMaximize->sizePolicy().hasHeightForWidth());
        btnMaximize->setSizePolicy(sizePolicy3);
        btnMaximize->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(btnMaximize, 0, 1, 1, 1);

        btnClose = new QPushButton(widget_2);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        sizePolicy3.setHeightForWidth(btnClose->sizePolicy().hasHeightForWidth());
        btnClose->setSizePolicy(sizePolicy3);
        btnClose->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(btnClose, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 46, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);


        horizontalLayout_2->addWidget(widget_2);


        gridLayout_2->addWidget(widgetTitle, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(RealMainWindow);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));

        gridLayout_2->addWidget(stackedWidget, 1, 0, 1, 1);


        retranslateUi(RealMainWindow);

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(RealMainWindow);
    } // setupUi

    void retranslateUi(QWidget *RealMainWindow)
    {
        RealMainWindow->setWindowTitle(QApplication::translate("RealMainWindow", "MainWindow", nullptr));
        labIcon->setText(QString());
        labTitle->setText(QString());
        btnMonitor->setText(QApplication::translate("RealMainWindow", "\350\247\206 \351\242\221 \347\233\221 \346\216\247", nullptr));
        btnPlayback->setText(QApplication::translate("RealMainWindow", "\350\247\206 \351\242\221 \345\233\236 \346\224\276", nullptr));
        btnSettings->setText(QApplication::translate("RealMainWindow", "\347\263\273 \347\273\237 \350\256\276 \347\275\256", nullptr));
        btnMinimize->setText(QString());
        btnMaximize->setText(QString());
        btnClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RealMainWindow: public Ui_RealMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REALMAINWINDOW_H
