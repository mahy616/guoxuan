/****************************************************************************
** Meta object code from reading C++ file 'DynamicWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../DynamicWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DynamicWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DynamicWidget_t {
    QByteArrayData data[17];
    char stringdata0[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DynamicWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DynamicWidget_t qt_meta_stringdata_DynamicWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DynamicWidget"
QT_MOC_LITERAL(1, 14, 13), // "AddWindowSlot"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 16), // "DeleteWindowSlot"
QT_MOC_LITERAL(4, 46, 15), // "ReSetWindowSlot"
QT_MOC_LITERAL(5, 62, 13), // "LoadProgramme"
QT_MOC_LITERAL(6, 76, 17), // "loadProgrammeName"
QT_MOC_LITERAL(7, 94, 20), // "TimerWatchOnAlgoStop"
QT_MOC_LITERAL(8, 115, 19), // "ActionStartWorkSlot"
QT_MOC_LITERAL(9, 135, 18), // "ActionStopWorkSlot"
QT_MOC_LITERAL(10, 154, 17), // "Action_SingleGrab"
QT_MOC_LITERAL(11, 172, 20), // "Action_SystemSetSlot"
QT_MOC_LITERAL(12, 193, 18), // "Action_SqlDataSlot"
QT_MOC_LITERAL(13, 212, 18), // "onButtonMinClicked"
QT_MOC_LITERAL(14, 231, 22), // "onButtonRestoreClicked"
QT_MOC_LITERAL(15, 254, 18), // "onButtonMaxClicked"
QT_MOC_LITERAL(16, 273, 20) // "onButtonCloseClicked"

    },
    "DynamicWidget\0AddWindowSlot\0\0"
    "DeleteWindowSlot\0ReSetWindowSlot\0"
    "LoadProgramme\0loadProgrammeName\0"
    "TimerWatchOnAlgoStop\0ActionStartWorkSlot\0"
    "ActionStopWorkSlot\0Action_SingleGrab\0"
    "Action_SystemSetSlot\0Action_SqlDataSlot\0"
    "onButtonMinClicked\0onButtonRestoreClicked\0"
    "onButtonMaxClicked\0onButtonCloseClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DynamicWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    1,   85,    2, 0x08 /* Private */,
       4,    0,   88,    2, 0x08 /* Private */,
       5,    1,   89,    2, 0x08 /* Private */,
       7,    0,   92,    2, 0x08 /* Private */,
       8,    0,   93,    2, 0x08 /* Private */,
       9,    0,   94,    2, 0x08 /* Private */,
      10,    0,   95,    2, 0x08 /* Private */,
      11,    0,   96,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DynamicWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DynamicWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AddWindowSlot(); break;
        case 1: _t->DeleteWindowSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ReSetWindowSlot(); break;
        case 3: _t->LoadProgramme((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->TimerWatchOnAlgoStop(); break;
        case 5: _t->ActionStartWorkSlot(); break;
        case 6: _t->ActionStopWorkSlot(); break;
        case 7: _t->Action_SingleGrab(); break;
        case 8: _t->Action_SystemSetSlot(); break;
        case 9: _t->Action_SqlDataSlot(); break;
        case 10: _t->onButtonMinClicked(); break;
        case 11: _t->onButtonRestoreClicked(); break;
        case 12: _t->onButtonMaxClicked(); break;
        case 13: _t->onButtonCloseClicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DynamicWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_DynamicWidget.data,
    qt_meta_data_DynamicWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DynamicWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DynamicWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DynamicWidget.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int DynamicWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
