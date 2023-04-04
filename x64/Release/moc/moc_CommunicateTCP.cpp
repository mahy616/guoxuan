/****************************************************************************
** Meta object code from reading C++ file 'CommunicateTCP.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Communicate/CommunicateTCP.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CommunicateTCP.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CommunicateTCP_t {
    QByteArrayData data[13];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommunicateTCP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommunicateTCP_t qt_meta_stringdata_CommunicateTCP = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CommunicateTCP"
QT_MOC_LITERAL(1, 15, 5), // "Error"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 3), // "msg"
QT_MOC_LITERAL(4, 26, 9), // "AddClient"
QT_MOC_LITERAL(5, 36, 6), // "client"
QT_MOC_LITERAL(6, 43, 12), // "RemoveClient"
QT_MOC_LITERAL(7, 56, 17), // "SendConnectStatus"
QT_MOC_LITERAL(8, 74, 6), // "status"
QT_MOC_LITERAL(9, 81, 15), // "SendReadMessage"
QT_MOC_LITERAL(10, 97, 2), // "ip"
QT_MOC_LITERAL(11, 100, 4), // "port"
QT_MOC_LITERAL(12, 105, 11) // "ReadMessage"

    },
    "CommunicateTCP\0Error\0\0msg\0AddClient\0"
    "client\0RemoveClient\0SendConnectStatus\0"
    "status\0SendReadMessage\0ip\0port\0"
    "ReadMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommunicateTCP[] = {

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
       4,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,
       7,    1,   53,    2, 0x06 /* Public */,
       9,    3,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::UShort,    3,   10,   11,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CommunicateTCP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CommunicateTCP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->AddClient((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->RemoveClient((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->SendConnectStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->SendReadMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 5: _t->ReadMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CommunicateTCP::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommunicateTCP::Error)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CommunicateTCP::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommunicateTCP::AddClient)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CommunicateTCP::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommunicateTCP::RemoveClient)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CommunicateTCP::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommunicateTCP::SendConnectStatus)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CommunicateTCP::*)(QString , QString , quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommunicateTCP::SendReadMessage)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CommunicateTCP::staticMetaObject = { {
    QMetaObject::SuperData::link<CommunicateBase::staticMetaObject>(),
    qt_meta_stringdata_CommunicateTCP.data,
    qt_meta_data_CommunicateTCP,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CommunicateTCP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommunicateTCP::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CommunicateTCP.stringdata0))
        return static_cast<void*>(this);
    return CommunicateBase::qt_metacast(_clname);
}

int CommunicateTCP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CommunicateBase::qt_metacall(_c, _id, _a);
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
void CommunicateTCP::Error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CommunicateTCP::AddClient(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CommunicateTCP::RemoveClient(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CommunicateTCP::SendConnectStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CommunicateTCP::SendReadMessage(QString _t1, QString _t2, quint16 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
