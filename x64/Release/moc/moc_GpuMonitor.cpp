/****************************************************************************
** Meta object code from reading C++ file 'GpuMonitor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../UI/Performance/GpuMonitor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GpuMonitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GpuReaderThread_t {
    QByteArrayData data[4];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GpuReaderThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GpuReaderThread_t qt_meta_stringdata_GpuReaderThread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "GpuReaderThread"
QT_MOC_LITERAL(1, 16, 14), // "GpuInfosSingal"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 21) // "std::vector<GpuInfos>"

    },
    "GpuReaderThread\0GpuInfosSingal\0\0"
    "std::vector<GpuInfos>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GpuReaderThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void GpuReaderThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GpuReaderThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GpuInfosSingal((*reinterpret_cast< std::vector<GpuInfos>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GpuReaderThread::*)(std::vector<GpuInfos> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GpuReaderThread::GpuInfosSingal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GpuReaderThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_GpuReaderThread.data,
    qt_meta_data_GpuReaderThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GpuReaderThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GpuReaderThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GpuReaderThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int GpuReaderThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void GpuReaderThread::GpuInfosSingal(std::vector<GpuInfos> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_GpuMonitor_t {
    QByteArrayData data[8];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GpuMonitor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GpuMonitor_t qt_meta_stringdata_GpuMonitor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GpuMonitor"
QT_MOC_LITERAL(1, 11, 21), // "SetWidgetHeightSignal"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 9), // "nowHeight"
QT_MOC_LITERAL(4, 44, 15), // "GetGpuInfosSlot"
QT_MOC_LITERAL(5, 60, 21), // "std::vector<GpuInfos>"
QT_MOC_LITERAL(6, 82, 19), // "WidgetShowStateSlot"
QT_MOC_LITERAL(7, 102, 6) // "isShow"

    },
    "GpuMonitor\0SetWidgetHeightSignal\0\0"
    "nowHeight\0GetGpuInfosSlot\0"
    "std::vector<GpuInfos>\0WidgetShowStateSlot\0"
    "isShow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GpuMonitor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x0a /* Public */,
       6,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void GpuMonitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GpuMonitor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SetWidgetHeightSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->GetGpuInfosSlot((*reinterpret_cast< std::vector<GpuInfos>(*)>(_a[1]))); break;
        case 2: _t->WidgetShowStateSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GpuMonitor::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GpuMonitor::SetWidgetHeightSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GpuMonitor::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GpuMonitor.data,
    qt_meta_data_GpuMonitor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GpuMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GpuMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GpuMonitor.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GpuMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void GpuMonitor::SetWidgetHeightSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
