#include "monitor.h"
#include "ui_monitor.h"
#include <QMenu>
#include "ui_widget.h"
#include "iconhelper.h"
#include <QAbstractButton>
#include <iostream>


void Monitor::setActionForButton() {
    ui->btnOne->setDefaultAction(ui->actOne);
    ui->btnOne->setText("");
    ui->btnFour->setDefaultAction(ui->actFour);
    ui->btnFour->setText("");
    ui->btnNine->setDefaultAction(ui->actNine);
    ui->btnNine->setText("");
    ui->btnSixteen->setDefaultAction(ui->actSixteen);
    ui->btnSixteen->setText("");
}

void Monitor::init() {

    QList<QToolButton*> btns = ui->widgetMulti->findChildren<QToolButton*>();

    foreach (QToolButton* btn, btns) {
        btn->setCheckable(true);
    }



    for (int i = 0; i < 16; ++i) {
        Widget* widget = new Widget();
        connect(widget, SIGNAL(btnClicked_widget_signal(QString)), this, SLOT(btnClicked_monitor_slot(QString)));
        widgets.push_back(widget);
    }


    ui->gridLayout->addWidget(widgets.at(0), 0, 0);

    setActionForButton();



//    ui->treeDevices->clear();
//    QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeDevices);
//    item->setText(0, "设备1");
//    ui->treeDevices->addTopLevelItem(item);
//    QTreeWidgetItem* item2 = new QTreeWidgetItem(ui->treeDevices);
//    item2->setText(0, "设备2");
//    ui->treeDevices->addTopLevelItem(item2);



    ui->btnOne->setChecked(true);
    ui->actOne->trigger();  // 写在前面会数组越界，因为先调用act_one_triggered()，里面remove qwidget，但是还没有创建qwidget
    //ui->btnOne->click();



}

void Monitor::btnCheckSet(QToolButton* cnt) {
    QList<QToolButton*> btns = ui->widgetMulti->findChildren<QToolButton*>();

    foreach (QToolButton* btn, btns) {
        btn->setChecked(btn == cnt);
    }
}


Monitor::Monitor(MainWindow* w, QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Monitor),
    m_mainwindow(w) {
    ui->setupUi(this);
    init();
}

Monitor::~Monitor() {
    delete ui;
}

void Monitor::hide_all_videos() {
    for (int i = 0; i < 16; ++i) {
        ui->gridLayout->removeWidget(widgets.at(i));
        widgets.at(i)->setVisible(false);
    }
}

void Monitor::on_actOne_triggered() {
    hide_all_videos();
    ui->gridLayout->addWidget(widgets.at(0), 0, 0);
    for (int i = 0; i < 1; ++i) {
        widgets.at(i)->setVisible(true);
    }
    btnCheckSet(ui->btnOne);
}

void Monitor::on_actFour_triggered() {
    hide_all_videos();

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            ui->gridLayout->addWidget(widgets.at(i * 2 + j), i, j, 1, 1);
        }
    }
    for (int i = 0; i < 4; ++i) {
        widgets.at(i)->setVisible(true);
    }
    btnCheckSet(ui->btnFour);
}

void Monitor::on_actNine_triggered() {
    hide_all_videos();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ui->gridLayout->addWidget(widgets.at(i * 3 + j), i, j, 1, 1);
        }
    }
    for (int i = 0; i < 9; ++i) {
        widgets.at(i)->setVisible(true);
    }
    btnCheckSet(ui->btnNine);
}

void Monitor::on_actSixteen_triggered() {
    hide_all_videos();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ui->gridLayout->addWidget(widgets.at(i * 4 + j), i, j, 1, 1);
        }
    }
    for (int i = 0; i < 16; ++i) {
        widgets.at(i)->setVisible(true);
    }
    btnCheckSet(ui->btnSixteen);
}

void Monitor::on_Monitor_customContextMenuRequested(const QPoint& pos) {
    Q_UNUSED(pos);
    QMenu* menu = new QMenu(this);
    menu->addAction(ui->actOne);
    menu->addAction(ui->actFour);
    menu->addAction(ui->actNine);
    menu->addAction(ui->actSixteen);
    menu->exec(QCursor::pos());
    delete menu;
}

void Monitor::btnClicked_monitor_slot(const QString& objName) {
    Widget* widget = static_cast<Widget*>(sender());
    QTreeWidgetItem* item = ui->treeDevices->currentItem();
    if (item == nullptr) return ;
    if (objName == "btnFlowClose") {
        widget->ui->playwidget->close();
    } else if (objName == "btnFlowVideo") {
        widget->ui->playwidget->setUrl(m_mainwindow->map[item->text(0)]);
        widget->ui->playwidget->open();
    } else if (objName == "btnFlowSnap") {
        QString dirName = QCoreApplication::applicationDirPath() + "/snap";
        QDir dir(dirName);
        if (!dir.exists()) {
            dir.mkdir(dirName);
        }
        QString picPath = QCoreApplication::applicationDirPath() + QString("/snap/%1.jpg").arg(STRDATETIME);
        widget->ui->playwidget->image.save(picPath, "JPG");
        QMessageBox* box = new QMessageBox(QMessageBox::Information, QString("截图保存"), QString("图片保存到") + picPath);
        box->show();
        box->button(QMessageBox::Ok)->hide();
        QTimer::singleShot(5000, box, SLOT(accept()));
        // TODO : 判断是否打开视频
    }
}


