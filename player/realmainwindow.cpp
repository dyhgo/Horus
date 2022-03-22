#include "realmainwindow.h"
#include "ui_realmainwindow.h"
#include <QTabWidget>


RealMainWindow::RealMainWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::RealMainWindow) {
    ui->setupUi(this);

    ui->widgetTitle->installEventFilter(this);

    isLeftButtonPressed = false;
    this->dir = NONE;
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setMinimumWidth(500);
    this->setMinimumHeight(100);
    this->setMouseTracking(true);

    this->setProperty("movable", true);
    this->setProperty("resizable", true);


//    MainWindow* w = new MainWindow();
//    ui->tabWidget->clear();
//    ui->tabWidget->addTab(w, "视频监控界面");
//    ui->tabWidget->setCurrentIndex(0);

//    Playback* p = new Playback();
//    ui->tabWidget->addTab(p, "视频回放界面");
}

RealMainWindow::~RealMainWindow() {
    delete ui;
}



void RealMainWindow::mouseReleaseEvent(QMouseEvent* event) {
    if (!this->property("movable").toBool() && !this->property("resizable").toBool()) {
        QWidget::mouseReleaseEvent(event);
        return ;
    }
    if (event->button() == Qt::LeftButton) {
        isLeftButtonPressed = false;
        if (dir != NONE) {
            this->releaseMouse();
            this->setCursor(QCursor(Qt::ArrowCursor));
        }
    }
    QWidget::mouseReleaseEvent(event);
}

void RealMainWindow::mouseMoveEvent(QMouseEvent* event) {
    if (!this->property("movable").toBool() && !this->property("resizable").toBool()) {
        QWidget::mouseMoveEvent(event);
        return ;
    }
    QPoint gloPoint = event->globalPos();
    QRect rect = this->rect();
    QPoint tl = mapToGlobal(rect.topLeft());
    QPoint rb = mapToGlobal(rect.bottomRight());

    if(!isLeftButtonPressed) {
        this->region(gloPoint);
    } else {
        if(dir != NONE) {
            QRect rMove(tl, rb);

            switch(dir) {
            case LEFT:
                if(rb.x() - gloPoint.x() <= this->minimumWidth())
                    rMove.setX(tl.x());
                else
                    rMove.setX(gloPoint.x());
                break;
            case RIGHT:
                rMove.setWidth(gloPoint.x() - tl.x());
                break;
            case TOP:
                if(rb.y() - gloPoint.y() <= this->minimumHeight())
                    rMove.setY(tl.y());
                else
                    rMove.setY(gloPoint.y());
                break;
            case BOTTOM:
                rMove.setHeight(gloPoint.y() - tl.y());
                break;
            case TOPLEFT:
                if(rb.x() - gloPoint.x() <= this->minimumWidth())
                    rMove.setX(tl.x());
                else
                    rMove.setX(gloPoint.x());
                if(rb.y() - gloPoint.y() <= this->minimumHeight())
                    rMove.setY(tl.y());
                else
                    rMove.setY(gloPoint.y());
                break;
            case TOPRIGHT:
                rMove.setWidth(gloPoint.x() - tl.x());
                rMove.setY(gloPoint.y());
                break;
            case BOTTOMLEFT:
                rMove.setX(gloPoint.x());
                rMove.setHeight(gloPoint.y() - tl.y());
                break;
            case BOTTOMRIGHT:
                rMove.setWidth(gloPoint.x() - tl.x());
                rMove.setHeight(gloPoint.y() - tl.y());
                break;
            default:

                break;
            }
            this->setGeometry(rMove);
        } else {
            move(event->globalPos() - mousePoint);
            event->accept();
        }
    }
    QWidget::mouseMoveEvent(event);
}

void RealMainWindow::mousePressEvent(QMouseEvent* event) {
    if (!this->property("movable").toBool() && !this->property("resizable").toBool()) {
        QWidget::mousePressEvent(event);
        return ;
    }
    if (event->button() == Qt::LeftButton) {
        isLeftButtonPressed = true;
        if (dir != NONE) {
            this->mouseGrabber();
        } else {
            mousePoint = event->globalPos() - this->frameGeometry().topLeft();
        }
    }
    QWidget::mousePressEvent(event);
}

bool RealMainWindow::eventFilter(QObject* watched, QEvent* event) {
    if (watched == ui->widgetTitle && event->type() == QEvent::MouseButtonDblClick) {
        on_btnMaximize_clicked();
        return true;
    }
    return QWidget::eventFilter(watched, event);
}

void RealMainWindow::region(const QPoint& cursorGlobalPoint) {
    QRect rect = this->rect();
    QPoint tl = mapToGlobal(rect.topLeft());
    QPoint rb = mapToGlobal(rect.bottomRight());
    int x = cursorGlobalPoint.x();
    int y = cursorGlobalPoint.y();

    if(tl.x() + PADDING >= x && tl.x() <= x && tl.y() + PADDING >= y && tl.y() <= y) {
        // 左上角
        dir = TOPLEFT;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    } else if(x >= rb.x() - PADDING && x <= rb.x() && y >= rb.y() - PADDING && y <= rb.y()) {
        // 右下角
        dir = BOTTOMRIGHT;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    } else if(x <= tl.x() + PADDING && x >= tl.x() && y >= rb.y() - PADDING && y <= rb.y()) {
        //左下角
        dir = BOTTOMLEFT;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    } else if(x <= rb.x() && x >= rb.x() - PADDING && y >= tl.y() && y <= tl.y() + PADDING) {
        // 右上角
        dir = TOPRIGHT;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    } else if(x <= tl.x() + PADDING && x >= tl.x()) {
        // 左边
        dir = LEFT;
        this->setCursor(QCursor(Qt::SizeHorCursor));
    } else if( x <= rb.x() && x >= rb.x() - PADDING) {
        // 右边
        dir = RIGHT;
        this->setCursor(QCursor(Qt::SizeHorCursor));
    } else if(y >= tl.y() && y <= tl.y() + PADDING) {
        // 上边
        dir = TOP;
        this->setCursor(QCursor(Qt::SizeVerCursor));
    } else if(y <= rb.y() && y >= rb.y() - PADDING) {
        // 下边
        dir = BOTTOM;
        this->setCursor(QCursor(Qt::SizeVerCursor));
    } else {
        // 默认
        dir = NONE;
        this->setCursor(QCursor(Qt::ArrowCursor));
    }
}

void RealMainWindow::on_btnClose_clicked() {
    close();
}

void RealMainWindow::on_btnMaximize_clicked() {
    static bool max = false;
    if (max) {
        showNormal();
        this->setProperty("movable", true);
        this->setProperty("resizable", true);
    } else {
        showMaximized();
        this->setProperty("movable", false);
        this->setProperty("resizable", false);
    }
    max = !max;
}

void RealMainWindow::on_btnMinimize_clicked() {
    showMinimized();
}
