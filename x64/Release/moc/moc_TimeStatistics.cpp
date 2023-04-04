/****************************************************************************
** Meta object code from reading C++ file 'TimeStatistics.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../UI/TimeStatistics.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TimeStatistics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TimeStatistics_t {
    QByteArrayData data[9];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimeStatistics_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimeStatistics_t qt_meta_stringdata_TimeStatistics = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TimeStatistics"
QT_MOC_LITERAL(1, 15, 17), // "GetAlgoResultSlot"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 10), // "TableIndex"
QT_MOC_LITERAL(4, 45, 3), // "bOK"
QT_MOC_LITERAL(5, 49, 4), // "Time"
QT_MOC_LITERAL(6, 54, 9), // "tableWord"
QT_MOC_LITERAL(7, 64, 18), // "ControlVisibleSlot"
QT_MOC_LITERAL(8, 83, 13) // "ResetDataSlot"

    },
    "TimeStatistics\0GetAlgoResultSlot\0\0"
    "TableIndex\0bOK\0Time\0tableWord\0"
    "ControlVisibleSlot\0ResetDataSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimeStatistics[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   29,    2, 0x0a /* Public */,
       7,    0,   38,    2, 0x0a /* Public */,
       8,    0,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Double, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TimeStatistics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TimeStatistics *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GetAlgoResultSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->ControlVisibleSlot(); break;
        case 2: _t->ResetDataSlot(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TimeStatistics::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_TimeStatistics.data,
    qt_meta_data_TimeStatistics,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TimeStatistics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimeStatistics::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TimeStatistics.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TimeStatistics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
