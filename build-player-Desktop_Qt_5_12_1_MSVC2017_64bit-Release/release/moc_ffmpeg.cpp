/****************************************************************************
** Meta object code from reading C++ file 'ffmpeg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Horus/ffmpeg/ffmpeg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ffmpeg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FFmpegThread_t {
    QByteArrayData data[12];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FFmpegThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FFmpegThread_t qt_meta_stringdata_FFmpegThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FFmpegThread"
QT_MOC_LITERAL(1, 13, 12), // "receiveImage"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "image"
QT_MOC_LITERAL(4, 33, 6), // "setUrl"
QT_MOC_LITERAL(5, 40, 3), // "url"
QT_MOC_LITERAL(6, 44, 4), // "init"
QT_MOC_LITERAL(7, 49, 4), // "free"
QT_MOC_LITERAL(8, 54, 4), // "play"
QT_MOC_LITERAL(9, 59, 5), // "pause"
QT_MOC_LITERAL(10, 65, 4), // "next"
QT_MOC_LITERAL(11, 70, 4) // "stop"

    },
    "FFmpegThread\0receiveImage\0\0image\0"
    "setUrl\0url\0init\0free\0play\0pause\0next\0"
    "stop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FFmpegThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   57,    2, 0x0a /* Public */,
       6,    0,   60,    2, 0x0a /* Public */,
       7,    0,   61,    2, 0x0a /* Public */,
       8,    0,   62,    2, 0x0a /* Public */,
       9,    0,   63,    2, 0x0a /* Public */,
      10,    0,   64,    2, 0x0a /* Public */,
      11,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FFmpegThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FFmpegThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: _t->setUrl((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: { bool _r = _t->init();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->free(); break;
        case 4: _t->play(); break;
        case 5: _t->pause(); break;
        case 6: _t->next(); break;
        case 7: _t->stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FFmpegThread::*)(const QImage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FFmpegThread::receiveImage)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FFmpegThread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_FFmpegThread.data,
    qt_meta_data_FFmpegThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FFmpegThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FFmpegThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FFmpegThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int FFmpegThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void FFmpegThread::receiveImage(const QImage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_FFmpegWidget_t {
    QByteArrayData data[20];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FFmpegWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FFmpegWidget_t qt_meta_stringdata_FFmpegWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FFmpegWidget"
QT_MOC_LITERAL(1, 13, 24), // "btnClicked_ffmpeg_signal"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 3), // "str"
QT_MOC_LITERAL(4, 43, 11), // "updateImage"
QT_MOC_LITERAL(5, 55, 5), // "image"
QT_MOC_LITERAL(6, 61, 6), // "setUrl"
QT_MOC_LITERAL(7, 68, 3), // "url"
QT_MOC_LITERAL(8, 72, 4), // "open"
QT_MOC_LITERAL(9, 77, 5), // "pause"
QT_MOC_LITERAL(10, 83, 4), // "next"
QT_MOC_LITERAL(11, 88, 5), // "close"
QT_MOC_LITERAL(12, 94, 5), // "clear"
QT_MOC_LITERAL(13, 100, 22), // "btnClicked_ffmpeg_slot"
QT_MOC_LITERAL(14, 123, 13), // "setFlowEnable"
QT_MOC_LITERAL(15, 137, 10), // "flowEnable"
QT_MOC_LITERAL(16, 148, 14), // "setFlowBgColor"
QT_MOC_LITERAL(17, 163, 11), // "flowBgColor"
QT_MOC_LITERAL(18, 175, 17), // "setFlowPressColor"
QT_MOC_LITERAL(19, 193, 14) // "flowPressColor"

    },
    "FFmpegWidget\0btnClicked_ffmpeg_signal\0"
    "\0str\0updateImage\0image\0setUrl\0url\0"
    "open\0pause\0next\0close\0clear\0"
    "btnClicked_ffmpeg_slot\0setFlowEnable\0"
    "flowEnable\0setFlowBgColor\0flowBgColor\0"
    "setFlowPressColor\0flowPressColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FFmpegWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       3,   98, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   77,    2, 0x08 /* Private */,
       6,    1,   80,    2, 0x0a /* Public */,
       8,    0,   83,    2, 0x0a /* Public */,
       9,    0,   84,    2, 0x0a /* Public */,
      10,    0,   85,    2, 0x0a /* Public */,
      11,    0,   86,    2, 0x0a /* Public */,
      12,    0,   87,    2, 0x0a /* Public */,
      13,    0,   88,    2, 0x08 /* Private */,
      14,    1,   89,    2, 0x0a /* Public */,
      16,    1,   92,    2, 0x0a /* Public */,
      18,    1,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::QColor,   17,
    QMetaType::Void, QMetaType::QColor,   19,

 // properties: name, type, flags
      15, QMetaType::Bool, 0x00095103,
      17, QMetaType::QColor, 0x00095103,
      19, QMetaType::QColor, 0x00095103,

       0        // eod
};

void FFmpegWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FFmpegWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->btnClicked_ffmpeg_signal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->updateImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 2: _t->setUrl((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->open(); break;
        case 4: _t->pause(); break;
        case 5: _t->next(); break;
        case 6: _t->close(); break;
        case 7: _t->clear(); break;
        case 8: _t->btnClicked_ffmpeg_slot(); break;
        case 9: _t->setFlowEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setFlowBgColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 11: _t->setFlowPressColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FFmpegWidget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FFmpegWidget::btnClicked_ffmpeg_signal)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<FFmpegWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getFlowEnable(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->getFlowBgColor(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->getFlowPressColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<FFmpegWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFlowEnable(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setFlowBgColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->setFlowPressColor(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject FFmpegWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FFmpegWidget.data,
    qt_meta_data_FFmpegWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FFmpegWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FFmpegWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FFmpegWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FFmpegWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void FFmpegWidget::btnClicked_ffmpeg_signal(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
