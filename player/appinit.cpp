#include "appinit.h"
#include <qmutex.h>
#include <qapplication.h>
#include <qwidget.h>
#include <qevent.h>

QScopedPointer<AppInit> AppInit::self;
AppInit* AppInit::Instance() {
    if (self.isNull()) {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if (self.isNull()) {
            self.reset(new AppInit);
        }
    }
    return self.data();
}

AppInit::AppInit(QObject* parent) : QObject(parent) {

}

bool AppInit::eventFilter(QObject* watched, QEvent* event) {
//    QWidget* w = (QWidget*) watched;
//    if (!w->property("canMove").toBool()) {
//        return QObject::eventFilter(watched, event);
//    }
//    static QPoint mousePoint;   // 鼠标坐标
//    static bool mousePressed = false;

//    QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
//    if (mouseEvent->type() == QEvent::MouseButtonPress) {
//        if (mouseEvent->button() == Qt::LeftButton) {
//            mousePressed = true;
//            mousePoint = mouseEvent->globalPos() - w->pos();
//        }
//    } else if (mouseEvent->type() == QEvent::MouseButtonRelease) {
//        mousePressed = false;
//    } else if (mouseEvent->type() == QEvent::MouseMove) {
//        if (mousePressed) {
//            w->move(mouseEvent->globalPos() - mousePoint);
//            //return true;
//        }
//    }
    moveWindow(watched, event);
    scaleWindow(watched, event);
    return QObject::eventFilter(watched, event);
}

void AppInit::moveWindow(QObject* watched, QEvent* event) {
    QWidget* w = (QWidget*) watched;
    if (w->property("canMove").toBool()) {
        static QPoint mousePoint;   // 鼠标坐标
        static bool mousePressed = false;
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->type() == QEvent::MouseButtonPress) {
            if (mouseEvent->button() == Qt::LeftButton) {
                mousePressed = true;
                mousePoint = mouseEvent->globalPos() - w->pos();
            }
        } else if (mouseEvent->type() == QEvent::MouseButtonRelease) {
            mousePressed = false;
        } else if (mouseEvent->type() == QEvent::MouseMove) {
            if (mousePressed) {
                w->move(mouseEvent->globalPos() - mousePoint);
                return ;
            }
        }
    }
}

void AppInit::scaleWindow(QObject* watched, QEvent* event) {

}

void AppInit::start() {
    qApp->installEventFilter(this);
}
