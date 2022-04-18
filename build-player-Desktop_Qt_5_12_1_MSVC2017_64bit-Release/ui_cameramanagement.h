/********************************************************************************
** Form generated from reading UI file 'cameramanagement.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAMANAGEMENT_H
#define UI_CAMERAMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraManagement
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QToolButton *btnAdd;
    QToolButton *btnDel;
    QToolButton *btnSave;
    QToolButton *btnClear;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableInfo;

    void setupUi(QWidget *CameraManagement)
    {
        if (CameraManagement->objectName().isEmpty())
            CameraManagement->setObjectName(QString::fromUtf8("CameraManagement"));
        CameraManagement->resize(899, 523);
        verticalLayout = new QVBoxLayout(CameraManagement);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        widget = new QWidget(CameraManagement);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 30));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        btnAdd = new QToolButton(widget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnAdd->sizePolicy().hasHeightForWidth());
        btnAdd->setSizePolicy(sizePolicy);
        btnAdd->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(btnAdd);

        btnDel = new QToolButton(widget);
        btnDel->setObjectName(QString::fromUtf8("btnDel"));
        sizePolicy.setHeightForWidth(btnDel->sizePolicy().hasHeightForWidth());
        btnDel->setSizePolicy(sizePolicy);
        btnDel->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(btnDel);

        btnSave = new QToolButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        sizePolicy.setHeightForWidth(btnSave->sizePolicy().hasHeightForWidth());
        btnSave->setSizePolicy(sizePolicy);
        btnSave->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(btnSave);

        btnClear = new QToolButton(widget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        sizePolicy.setHeightForWidth(btnClear->sizePolicy().hasHeightForWidth());
        btnClear->setSizePolicy(sizePolicy);
        btnClear->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(btnClear);

        horizontalSpacer = new QSpacerItem(482, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        tableInfo = new QTableWidget(CameraManagement);
        if (tableInfo->columnCount() < 2)
            tableInfo->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableInfo->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableInfo->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableInfo->setObjectName(QString::fromUtf8("tableInfo"));

        verticalLayout->addWidget(tableInfo);


        retranslateUi(CameraManagement);

        QMetaObject::connectSlotsByName(CameraManagement);
    } // setupUi

    void retranslateUi(QWidget *CameraManagement)
    {
        CameraManagement->setWindowTitle(QApplication::translate("CameraManagement", "Form", nullptr));
        btnAdd->setText(QApplication::translate("CameraManagement", "\346\267\273\345\212\240", nullptr));
        btnDel->setText(QApplication::translate("CameraManagement", "\345\210\240\351\231\244", nullptr));
        btnSave->setText(QApplication::translate("CameraManagement", "\344\277\235\345\255\230", nullptr));
        btnClear->setText(QApplication::translate("CameraManagement", "\346\270\205\347\251\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CameraManagement", "\350\256\276\345\244\207\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CameraManagement", "\345\234\260\345\235\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CameraManagement: public Ui_CameraManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAMANAGEMENT_H
