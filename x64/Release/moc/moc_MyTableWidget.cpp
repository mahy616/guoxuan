/****************************************************************************
** Meta object code from reading C++ file 'MyTableWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../UI/MyWidget/MyTableWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyTableWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyTableWidget_t {
    QByteArrayData data[8];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyTableWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyTableWidget_t qt_meta_stringdata_MyTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MyTableWidget"
QT_MOC_LITERAL(1, 14, 17), // "GetFileImageNames"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 18), // "TableGetAlgoResult"
QT_MOC_LITERAL(4, 52, 10), // "TableIndex"
QT_MOC_LITERAL(5, 63, 3), // "bOK"
QT_MOC_LITERAL(6, 67, 4), // "Time"
QT_MOC_LITERAL(7, 72, 9) // "tableWord"

    },
    "MyTableWidget\0GetFileImageNames\0\0"
    "TableGetAlgoResult\0TableIndex\0bOK\0"
    "Time\0tableWord"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyTableWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       3,    4,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Double, QMetaType::QString,    4,    5,    6,    7,

       0        // eod
};

void MyTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyTableWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GetFileImageNames((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->TableGetAlgoResult((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyTableWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QTableWidget::staticMetaObject>(),
    qt_meta_stringdata_MyTableWidget.data,
    qt_meta_data_MyTableWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyTableWidget.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int MyTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
