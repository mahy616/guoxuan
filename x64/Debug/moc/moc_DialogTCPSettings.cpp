/****************************************************************************
** Meta object code from reading C++ file 'DialogTCPSettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Communicate/DialogTCPSettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogTCPSettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogTCPSettings_t {
    QByteArrayData data[16];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogTCPSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogTCPSettings_t qt_meta_stringdata_DialogTCPSettings = {
    {
QT_MOC_LITERAL(0, 0, 17), // "DialogTCPSettings"
QT_MOC_LITERAL(1, 18, 21), // "on_btnConnect_clicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 24), // "on_btnDisConnect_clicked"
QT_MOC_LITERAL(4, 66, 18), // "on_btnSend_clicked"
QT_MOC_LITERAL(5, 85, 9), // "ErrorSlot"
QT_MOC_LITERAL(6, 95, 3), // "msg"
QT_MOC_LITERAL(7, 99, 13), // "AddClientSlot"
QT_MOC_LITERAL(8, 113, 6), // "client"
QT_MOC_LITERAL(9, 120, 16), // "RemoveClientSlot"
QT_MOC_LITERAL(10, 137, 21), // "SendConnectStatusSlot"
QT_MOC_LITERAL(11, 159, 6), // "status"
QT_MOC_LITERAL(12, 166, 19), // "SendReadMessageSlot"
QT_MOC_LITERAL(13, 186, 2), // "ip"
QT_MOC_LITERAL(14, 189, 4), // "port"
QT_MOC_LITERAL(15, 194, 17) // "ConfigChangeEvent"

    },
    "DialogTCPSettings\0on_btnConnect_clicked\0"
    "\0on_btnDisConnect_clicked\0on_btnSend_clicked\0"
    "ErrorSlot\0msg\0AddClientSlot\0client\0"
    "RemoveClientSlot\0SendConnectStatusSlot\0"
    "status\0SendReadMessageSlot\0ip\0port\0"
    "ConfigChangeEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogTCPSettings[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    1,   62,    2, 0x08 /* Private */,
       7,    1,   65,    2, 0x08 /* Private */,
       9,    1,   68,    2, 0x08 /* Private */,
      10,    1,   71,    2, 0x08 /* Private */,
      12,    3,   74,    2, 0x08 /* Private */,
      15,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::UShort,    6,   13,   14,
    QMetaType::Void,

       0        // eod
};

void DialogTCPSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogTCPSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnConnect_clicked(); break;
        case 1: _t->on_btnDisConnect_clicked(); break;
        case 2: _t->on_btnSend_clicked(); break;
        case 3: _t->ErrorSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->AddClientSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->RemoveClientSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->SendConnectStatusSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->SendReadMessageSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 8: _t->ConfigChangeEvent(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DialogTCPSettings::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DialogTCPSettings.data,
    qt_meta_data_DialogTCPSettings,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogTCPSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogTCPSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogTCPSettings.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DialogTCPSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
