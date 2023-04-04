/****************************************************************************
** Meta object code from reading C++ file 'DialogTitleBar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../UI/MyWidget/DialogTitleBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogTitleBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogTitleBar_t {
    QByteArrayData data[5];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogTitleBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogTitleBar_t qt_meta_stringdata_DialogTitleBar = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DialogTitleBar"
QT_MOC_LITERAL(1, 15, 11), // "CloseSignal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 20), // "RestoreClickedSignal"
QT_MOC_LITERAL(4, 49, 16) // "MaxClickedSignal"

    },
    "DialogTitleBar\0CloseSignal\0\0"
    "RestoreClickedSignal\0MaxClickedSignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogTitleBar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    0,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogTitleBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogTitleBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CloseSignal(); break;
        case 1: _t->RestoreClickedSignal(); break;
        case 2: _t->MaxClickedSignal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DialogTitleBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogTitleBar::CloseSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DialogTitleBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogTitleBar::RestoreClickedSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DialogTitleBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogTitleBar::MaxClickedSignal)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DialogTitleBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DialogTitleBar.data,
    qt_meta_data_DialogTitleBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogTitleBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogTitleBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogTitleBar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DialogTitleBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void DialogTitleBar::CloseSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DialogTitleBar::RestoreClickedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DialogTitleBar::MaxClickedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
