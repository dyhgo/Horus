/********************************************************************************
** Form generated from reading UI file 'monitor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITOR_H
#define UI_MONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Monitor
{
public:
    QAction *actOne;
    QAction *actFour;
    QAction *actNine;
    QAction *actSixteen;
    QGridLayout *gridLayout_2;
    QWidget *widgetGrid;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QWidget *widgetDevice;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeDevices;
    QWidget *widgetMulti;
    QHBoxLayout *horizontalLayout;
    QToolButton *btnOne;
    QToolButton *btnFour;
    QToolButton *btnNine;
    QToolButton *btnSixteen;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Monitor)
    {
        if (Monitor->objectName().isEmpty())
            Monitor->setObjectName(QString::fromUtf8("Monitor"));
        Monitor->resize(920, 691);
        Monitor->setContextMenuPolicy(Qt::CustomContextMenu);
        actOne = new QAction(Monitor);
        actOne->setObjectName(QString::fromUtf8("actOne"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/images/QDarkStyleSheet/z_one.png"), QSize(), QIcon::Normal, QIcon::Off);
        actOne->setIcon(icon);
        actFour = new QAction(Monitor);
        actFour->setObjectName(QString::fromUtf8("actFour"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/images/QDarkStyleSheet/z_four.png"), QSize(), QIcon::Normal, QIcon::Off);
        actFour->setIcon(icon1);
        actNine = new QAction(Monitor);
        actNine->setObjectName(QString::fromUtf8("actNine"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/images/QDarkStyleSheet/z_nine.png"), QSize(), QIcon::Normal, QIcon::Off);
        actNine->setIcon(icon2);
        actSixteen = new QAction(Monitor);
        actSixteen->setObjectName(QString::fromUtf8("actSixteen"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/images/QDarkStyleSheet/z_sixteen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actSixteen->setIcon(icon3);
        gridLayout_2 = new QGridLayout(Monitor);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widgetGrid = new QWidget(Monitor);
        widgetGrid->setObjectName(QString::fromUtf8("widgetGrid"));
        gridLayout_3 = new QGridLayout(widgetGrid);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(1, 1, 1, 1);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_2->addWidget(widgetGrid, 0, 0, 1, 1);

        widgetDevice = new QWidget(Monitor);
        widgetDevice->setObjectName(QString::fromUtf8("widgetDevice"));
        widgetDevice->setMinimumSize(QSize(170, 0));
        widgetDevice->setMaximumSize(QSize(170, 16777215));
        verticalLayout = new QVBoxLayout(widgetDevice);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeDevices = new QTreeWidget(widgetDevice);
        treeDevices->setObjectName(QString::fromUtf8("treeDevices"));

        verticalLayout->addWidget(treeDevices);


        gridLayout_2->addWidget(widgetDevice, 0, 1, 2, 1);

        widgetMulti = new QWidget(Monitor);
        widgetMulti->setObjectName(QString::fromUtf8("widgetMulti"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetMulti->sizePolicy().hasHeightForWidth());
        widgetMulti->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widgetMulti);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        btnOne = new QToolButton(widgetMulti);
        btnOne->setObjectName(QString::fromUtf8("btnOne"));
        sizePolicy.setHeightForWidth(btnOne->sizePolicy().hasHeightForWidth());
        btnOne->setSizePolicy(sizePolicy);
        btnOne->setMaximumSize(QSize(16777215, 16777215));
        btnOne->setIconSize(QSize(19, 19));
        btnOne->setCheckable(false);
        btnOne->setChecked(false);
        btnOne->setToolButtonStyle(Qt::ToolButtonIconOnly);

        horizontalLayout->addWidget(btnOne);

        btnFour = new QToolButton(widgetMulti);
        btnFour->setObjectName(QString::fromUtf8("btnFour"));
        sizePolicy.setHeightForWidth(btnFour->sizePolicy().hasHeightForWidth());
        btnFour->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(btnFour);

        btnNine = new QToolButton(widgetMulti);
        btnNine->setObjectName(QString::fromUtf8("btnNine"));
        sizePolicy.setHeightForWidth(btnNine->sizePolicy().hasHeightForWidth());
        btnNine->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(btnNine);

        btnSixteen = new QToolButton(widgetMulti);
        btnSixteen->setObjectName(QString::fromUtf8("btnSixteen"));
        sizePolicy.setHeightForWidth(btnSixteen->sizePolicy().hasHeightForWidth());
        btnSixteen->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(btnSixteen);

        horizontalSpacer = new QSpacerItem(586, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addWidget(widgetMulti, 1, 0, 1, 1);


        retranslateUi(Monitor);

        QMetaObject::connectSlotsByName(Monitor);
    } // setupUi

    void retranslateUi(QWidget *Monitor)
    {
        Monitor->setWindowTitle(QApplication::translate("Monitor", "MainWindow", nullptr));
        actOne->setText(QApplication::translate("Monitor", "1\347\224\273\351\235\242", nullptr));
#ifndef QT_NO_TOOLTIP
        actOne->setToolTip(QApplication::translate("Monitor", "1\347\224\273\351\235\242", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actOne->setShortcut(QApplication::translate("Monitor", "F1", nullptr));
#endif // QT_NO_SHORTCUT
        actFour->setText(QApplication::translate("Monitor", "4\347\224\273\351\235\242", nullptr));
#ifndef QT_NO_TOOLTIP
        actFour->setToolTip(QApplication::translate("Monitor", "4\347\224\273\351\235\242", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actFour->setShortcut(QApplication::translate("Monitor", "F2", nullptr));
#endif // QT_NO_SHORTCUT
        actNine->setText(QApplication::translate("Monitor", "9\347\224\273\351\235\242", nullptr));
#ifndef QT_NO_TOOLTIP
        actNine->setToolTip(QApplication::translate("Monitor", "9\347\224\273\351\235\242", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actNine->setShortcut(QApplication::translate("Monitor", "F3", nullptr));
#endif // QT_NO_SHORTCUT
        actSixteen->setText(QApplication::translate("Monitor", "16\347\224\273\351\235\242", nullptr));
#ifndef QT_NO_TOOLTIP
        actSixteen->setToolTip(QApplication::translate("Monitor", "16\347\224\273\351\235\242", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actSixteen->setShortcut(QApplication::translate("Monitor", "F4", nullptr));
#endif // QT_NO_SHORTCUT
        QTreeWidgetItem *___qtreewidgetitem = treeDevices->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("Monitor", "\350\256\276\345\244\207\345\210\227\350\241\250", nullptr));
        btnOne->setText(QString());
        btnFour->setText(QString());
        btnNine->setText(QString());
        btnSixteen->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Monitor: public Ui_Monitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITOR_H
