/****************************************************************************
** Meta object code from reading C++ file 'Camera.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../components/Camera/Camera.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Camera.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Camera_t {
    QByteArrayData data[10];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Camera_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Camera_t qt_meta_stringdata_Camera = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Camera"
QT_MOC_LITERAL(1, 7, 10), // "imageReady"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "cv::Mat"
QT_MOC_LITERAL(4, 27, 20), // "connectStatusChanged"
QT_MOC_LITERAL(5, 48, 17), // "grabStatusChanged"
QT_MOC_LITERAL(6, 66, 11), // "cameraError"
QT_MOC_LITERAL(7, 78, 12), // "paramUpdated"
QT_MOC_LITERAL(8, 91, 17), // "Camera::ParamName"
QT_MOC_LITERAL(9, 109, 9) // "onTrigger"

    },
    "Camera\0imageReady\0\0cv::Mat\0"
    "connectStatusChanged\0grabStatusChanged\0"
    "cameraError\0paramUpdated\0Camera::ParamName\0"
    "onTrigger"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Camera[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,
       5,    0,   48,    2, 0x06 /* Public */,
       6,    1,   49,    2, 0x06 /* Public */,
       7,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 8,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Camera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Camera *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageReady((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 1: _t->connectStatusChanged(); break;
        case 2: _t->grabStatusChanged(); break;
        case 3: _t->cameraError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->paramUpdated((*reinterpret_cast< Camera::ParamName(*)>(_a[1]))); break;
        case 5: _t->onTrigger(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Camera::*)(cv::Mat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Camera::imageReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Camera::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Camera::connectStatusChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Camera::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Camera::grabStatusChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Camera::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Camera::cameraError)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Camera::*)(Camera::ParamName );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Camera::paramUpdated)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Camera::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_Camera.data,
    qt_meta_data_Camera,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Camera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Camera::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Camera.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int Camera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Camera::imageReady(cv::Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Camera::connectStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Camera::grabStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Camera::cameraError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Camera::paramUpdated(Camera::ParamName _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
