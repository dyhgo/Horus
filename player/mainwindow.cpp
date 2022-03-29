#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include "ui_widget.h"

void MainWindow::setActionForButton() {
    ui->btnOne->setDefaultAction(ui->actOne);
    ui->btnFour->setDefaultAction(ui->actFour);
    ui->btnNine->setDefaultAction(ui->actNine);
    ui->btnSixteen->setDefaultAction(ui->actSixteen);
}

void MainWindow::init() {
    for (int i = 0; i < 16; ++i) {
        Widget* widget = new Widget();
        connect(widget, SIGNAL(btnClicked_widget_signal(QString)), this, SLOT(btnClicked_mainwindow_slot(QString)));
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







}

MainWindow::MainWindow(RealMainWindow* w, QWidget* parent) :
    QWidget(parent),
    ui(new Ui::MainWindow),
    m_realmainwindow(w) {
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::hide_all_videos() {
    for (int i = 0; i < 16; ++i) {
        ui->gridLayout->removeWidget(widgets.at(i));
        widgets.at(i)->setVisible(false);
    }
}

void MainWindow::on_actOne_triggered() {
    hide_all_videos();
    ui->gridLayout->addWidget(widgets.at(0), 0, 0);
    for (int i = 0; i < 1; ++i) {
        widgets.at(i)->setVisible(true);
    }
}

void MainWindow::on_actFour_triggered() {
    hide_all_videos();

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            ui->gridLayout->addWidget(widgets.at(i * 2 + j), i, j, 1, 1);
        }
    }
    for (int i = 0; i < 4; ++i) {
        widgets.at(i)->setVisible(true);
    }
}

void MainWindow::on_actNine_triggered() {
    hide_all_videos();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ui->gridLayout->addWidget(widgets.at(i * 3 + j), i, j, 1, 1);
        }
    }
    for (int i = 0; i < 9; ++i) {
        widgets.at(i)->setVisible(true);
    }
}

void MainWindow::on_actSixteen_triggered() {
    hide_all_videos();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ui->gridLayout->addWidget(widgets.at(i * 4 + j), i, j, 1, 1);
        }
    }
    for (int i = 0; i < 16; ++i) {
        widgets.at(i)->setVisible(true);
    }
}

void MainWindow::on_MainWindow_customContextMenuRequested(const QPoint& pos) {
    Q_UNUSED(pos);
    QMenu* menu = new QMenu(this);
    menu->addAction(ui->actOne);
    menu->addAction(ui->actFour);
    menu->addAction(ui->actNine);
    menu->addAction(ui->actSixteen);
    menu->exec(QCursor::pos());
    delete menu;
}

void MainWindow::btnClicked_mainwindow_slot(const QString& objName) {
    Widget* widget = (Widget*) sender();
    QTreeWidgetItem* item = ui->treeDevices->currentItem();
    if (item == nullptr) return ;
    if (objName == "btnFlowClose") {
        widget->ui->playwidget->close();
    } else if (objName == "btnFlowVideo") {
        widget->ui->playwidget->setUrl(m_realmainwindow->map[item->text(0)]);
        widget->ui->playwidget->open();
    }
}
