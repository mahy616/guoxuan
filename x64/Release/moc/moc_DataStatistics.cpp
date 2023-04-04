/****************************************************************************
** Meta object code from reading C++ file 'DataStatistics.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../UI/DataStatistics.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DataStatistics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataStatistics_t {
    QByteArrayData data[13];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataStatistics_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataStatistics_t qt_meta_stringdata_DataStatistics = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DataStatistics"
QT_MOC_LITERAL(1, 15, 17), // "GetAlgoResultSlot"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 10), // "TableIndex"
QT_MOC_LITERAL(4, 45, 3), // "bOK"
QT_MOC_LITERAL(5, 49, 4), // "Time"
QT_MOC_LITERAL(6, 54, 9), // "tableWord"
QT_MOC_LITERAL(7, 64, 18), // "GetModelChangeSlot"
QT_MOC_LITERAL(8, 83, 11), // "ModelChoice"
QT_MOC_LITERAL(9, 95, 18), // "ControlVisibleSlot"
QT_MOC_LITERAL(10, 114, 21), // "LabelsLeftClickedSlot"
QT_MOC_LITERAL(11, 136, 22), // "LabelsRightClickedSlot"
QT_MOC_LITERAL(12, 159, 13) // "ResetDataSlot"

    },
    "DataStatistics\0GetAlgoResultSlot\0\0"
    "TableIndex\0bOK\0Time\0tableWord\0"
    "GetModelChangeSlot\0ModelChoice\0"
    "ControlVisibleSlot\0LabelsLeftClickedSlot\0"
    "LabelsRightClickedSlot\0ResetDataSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataStatistics[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   44,    2, 0x0a /* Public */,
       7,    1,   53,    2, 0x0a /* Public */,
       9,    0,   56,    2, 0x0a /* Public */,
      10,    0,   57,    2, 0x0a /* Public */,
      11,    0,   58,    2, 0x0a /* Public */,
      12,    0,   59,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Double, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DataStatistics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataStatistics *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GetAlgoResultSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->GetModelChangeSlot((*reinterpret_cast< ModelChoice(*)>(_a[1]))); break;
        case 2: _t->ControlVisibleSlot(); break;
        case 3: _t->LabelsLeftClickedSlot(); break;
        case 4: _t->LabelsRightClickedSlot(); break;
        case 5: _t->ResetDataSlot(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataStatistics::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DataStatistics.data,
    qt_meta_data_DataStatistics,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataStatistics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataStatistics::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataStatistics.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DataStatistics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
