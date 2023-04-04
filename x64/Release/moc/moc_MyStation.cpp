/****************************************************************************
** Meta object code from reading C++ file 'MyStation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MyStation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyStation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyStation_t {
    QByteArrayData data[21];
    char stringdata0[258];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyStation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyStation_t qt_meta_stringdata_MyStation = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MyStation"
QT_MOC_LITERAL(1, 10, 19), // "AddOneWindowSignals"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 7), // "sendLog"
QT_MOC_LITERAL(4, 39, 22), // "TableWidgetClickedSlot"
QT_MOC_LITERAL(5, 62, 11), // "QModelIndex"
QT_MOC_LITERAL(6, 74, 5), // "index"
QT_MOC_LITERAL(7, 80, 14), // "GetCameraIamge"
QT_MOC_LITERAL(8, 95, 7), // "cv::Mat"
QT_MOC_LITERAL(9, 103, 20), // "GetThresholdAllParam"
QT_MOC_LITERAL(10, 124, 13), // "SaveImageSlot"
QT_MOC_LITERAL(11, 138, 8), // "cv::Mat&"
QT_MOC_LITERAL(12, 147, 13), // "OriginalImage"
QT_MOC_LITERAL(13, 161, 11), // "RenderImage"
QT_MOC_LITERAL(14, 173, 3), // "bOK"
QT_MOC_LITERAL(15, 177, 9), // "tableText"
QT_MOC_LITERAL(16, 187, 10), // "TableIndex"
QT_MOC_LITERAL(17, 198, 13), // "ImageFileName"
QT_MOC_LITERAL(18, 212, 18), // "GetModelChangeSlot"
QT_MOC_LITERAL(19, 231, 11), // "ModelChoice"
QT_MOC_LITERAL(20, 243, 14) // "ConfigParamter"

    },
    "MyStation\0AddOneWindowSignals\0\0sendLog\0"
    "TableWidgetClickedSlot\0QModelIndex\0"
    "index\0GetCameraIamge\0cv::Mat\0"
    "GetThresholdAllParam\0SaveImageSlot\0"
    "cv::Mat&\0OriginalImage\0RenderImage\0"
    "bOK\0tableText\0TableIndex\0ImageFileName\0"
    "GetModelChangeSlot\0ModelChoice\0"
    "ConfigParamter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyStation[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   53,    2, 0x0a /* Public */,
       7,    1,   56,    2, 0x0a /* Public */,
       9,    0,   59,    2, 0x0a /* Public */,
      10,    6,   60,    2, 0x0a /* Public */,
      18,    1,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 11, QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QString,   12,   13,   14,   15,   16,   17,
    QMetaType::Void, 0x80000000 | 19,   20,

       0        // eod
};

void MyStation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyStation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AddOneWindowSignals(); break;
        case 1: _t->sendLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->TableWidgetClickedSlot((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 3: _t->GetCameraIamge((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 4: _t->GetThresholdAllParam(); break;
        case 5: _t->SaveImageSlot((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 6: _t->GetModelChangeSlot((*reinterpret_cast< ModelChoice(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyStation::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyStation::AddOneWindowSignals)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyStation::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyStation::sendLog)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyStation::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MyStation.data,
    qt_meta_data_MyStation,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyStation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyStation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyStation.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MyStation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MyStation::AddOneWindowSignals()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyStation::sendLog(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
