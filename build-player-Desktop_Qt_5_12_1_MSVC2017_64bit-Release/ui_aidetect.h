/********************************************************************************
** Form generated from reading UI file 'aidetect.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIDETECT_H
#define UI_AIDETECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AIDetect
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *openFile;
    QComboBox *model;
    QPushButton *reset;
    QPushButton *startDetect;
    QPushButton *loadFile;
    QPushButton *selectDevice;
    QPushButton *stopDetect;
    QPlainTextEdit *textEditlog;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QLabel *lab_video;
    QLabel *lab_msg;

    void setupUi(QWidget *AIDetect)
    {
        if (AIDetect->objectName().isEmpty())
            AIDetect->setObjectName(QString::fromUtf8("AIDetect"));
        AIDetect->resize(1088, 542);
        gridLayout = new QGridLayout(AIDetect);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(AIDetect);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 40));
        widget->setMaximumSize(QSize(16777215, 40));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(7);
        gridLayout_2->setContentsMargins(1, 1, 1, 1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 5, 1, 1);

        openFile = new QPushButton(widget);
        openFile->setObjectName(QString::fromUtf8("openFile"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(openFile->sizePolicy().hasHeightForWidth());
        openFile->setSizePolicy(sizePolicy1);
        openFile->setMinimumSize(QSize(120, 0));

        gridLayout_2->addWidget(openFile, 0, 1, 1, 1);

        model = new QComboBox(widget);
        model->addItem(QString());
        model->addItem(QString());
        model->addItem(QString());
        model->addItem(QString());
        model->setObjectName(QString::fromUtf8("model"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(model->sizePolicy().hasHeightForWidth());
        model->setSizePolicy(sizePolicy2);
        model->setMinimumSize(QSize(120, 0));

        gridLayout_2->addWidget(model, 0, 3, 1, 1);

        reset = new QPushButton(widget);
        reset->setObjectName(QString::fromUtf8("reset"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(reset->sizePolicy().hasHeightForWidth());
        reset->setSizePolicy(sizePolicy3);
        reset->setMinimumSize(QSize(120, 0));
        reset->setMaximumSize(QSize(120, 16777215));

        gridLayout_2->addWidget(reset, 0, 4, 1, 1);

        startDetect = new QPushButton(widget);
        startDetect->setObjectName(QString::fromUtf8("startDetect"));
        sizePolicy3.setHeightForWidth(startDetect->sizePolicy().hasHeightForWidth());
        startDetect->setSizePolicy(sizePolicy3);
        startDetect->setMinimumSize(QSize(120, 0));

        gridLayout_2->addWidget(startDetect, 0, 6, 1, 1);

        loadFile = new QPushButton(widget);
        loadFile->setObjectName(QString::fromUtf8("loadFile"));
        sizePolicy3.setHeightForWidth(loadFile->sizePolicy().hasHeightForWidth());
        loadFile->setSizePolicy(sizePolicy3);
        loadFile->setMinimumSize(QSize(120, 0));

        gridLayout_2->addWidget(loadFile, 0, 2, 1, 1);

        selectDevice = new QPushButton(widget);
        selectDevice->setObjectName(QString::fromUtf8("selectDevice"));
        sizePolicy2.setHeightForWidth(selectDevice->sizePolicy().hasHeightForWidth());
        selectDevice->setSizePolicy(sizePolicy2);
        selectDevice->setMinimumSize(QSize(120, 0));

        gridLayout_2->addWidget(selectDevice, 0, 0, 1, 1);

        stopDetect = new QPushButton(widget);
        stopDetect->setObjectName(QString::fromUtf8("stopDetect"));
        sizePolicy3.setHeightForWidth(stopDetect->sizePolicy().hasHeightForWidth());
        stopDetect->setSizePolicy(sizePolicy3);
        stopDetect->setMinimumSize(QSize(120, 0));

        gridLayout_2->addWidget(stopDetect, 0, 7, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        textEditlog = new QPlainTextEdit(AIDetect);
        textEditlog->setObjectName(QString::fromUtf8("textEditlog"));
        textEditlog->setMinimumSize(QSize(170, 350));
        textEditlog->setMaximumSize(QSize(170, 16777215));

        gridLayout->addWidget(textEditlog, 0, 1, 3, 1);

        frame = new QFrame(AIDetect);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(1, 1, 1, 1);
        lab_video = new QLabel(frame);
        lab_video->setObjectName(QString::fromUtf8("lab_video"));

        gridLayout_3->addWidget(lab_video, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 1, 0, 1, 1);

        lab_msg = new QLabel(AIDetect);
        lab_msg->setObjectName(QString::fromUtf8("lab_msg"));
        lab_msg->setMinimumSize(QSize(0, 15));
        lab_msg->setMaximumSize(QSize(16777215, 15));

        gridLayout->addWidget(lab_msg, 2, 0, 1, 1);


        retranslateUi(AIDetect);

        QMetaObject::connectSlotsByName(AIDetect);
    } // setupUi

    void retranslateUi(QWidget *AIDetect)
    {
        AIDetect->setWindowTitle(QApplication::translate("AIDetect", "MainWindow", nullptr));
        openFile->setText(QApplication::translate("AIDetect", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        model->setItemText(0, QApplication::translate("AIDetect", "yolov5s", nullptr));
        model->setItemText(1, QApplication::translate("AIDetect", "yolov5m", nullptr));
        model->setItemText(2, QApplication::translate("AIDetect", "yolov5l", nullptr));
        model->setItemText(3, QApplication::translate("AIDetect", "yolov5x", nullptr));

        reset->setText(QApplication::translate("AIDetect", "\351\207\215\347\275\256", nullptr));
        startDetect->setText(QApplication::translate("AIDetect", "\345\274\200\345\247\213\346\243\200\346\265\213", nullptr));
        loadFile->setText(QApplication::translate("AIDetect", "\345\212\240\350\275\275\346\250\241\345\236\213", nullptr));
        selectDevice->setText(QApplication::translate("AIDetect", "\351\200\211\346\213\251\350\256\276\345\244\207", nullptr));
        stopDetect->setText(QApplication::translate("AIDetect", "\345\201\234\346\255\242\346\243\200\346\265\213", nullptr));
        lab_video->setText(QString());
        lab_msg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AIDetect: public Ui_AIDetect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIDETECT_H
