/****************************************************************************
** Meta object code from reading C++ file 'AlgoThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Algo/AlgoThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AlgoThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CAlgoThread_t {
    QByteArrayData data[14];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAlgoThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAlgoThread_t qt_meta_stringdata_CAlgoThread = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CAlgoThread"
QT_MOC_LITERAL(1, 12, 18), // "inintSuccessSiganl"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 19), // "SendDetectionResult"
QT_MOC_LITERAL(4, 52, 8), // "cv::Mat&"
QT_MOC_LITERAL(5, 61, 13), // "OriginalImage"
QT_MOC_LITERAL(6, 75, 11), // "RenderImage"
QT_MOC_LITERAL(7, 87, 3), // "bOK"
QT_MOC_LITERAL(8, 91, 4), // "Time"
QT_MOC_LITERAL(9, 96, 17), // "SendResultToTable"
QT_MOC_LITERAL(10, 114, 10), // "TableIndex"
QT_MOC_LITERAL(11, 125, 9), // "tableText"
QT_MOC_LITERAL(12, 135, 13), // "SendToSaveImg"
QT_MOC_LITERAL(13, 149, 13) // "ImageFileName"

    },
    "CAlgoThread\0inintSuccessSiganl\0\0"
    "SendDetectionResult\0cv::Mat&\0OriginalImage\0"
    "RenderImage\0bOK\0Time\0SendResultToTable\0"
    "TableIndex\0tableText\0SendToSaveImg\0"
    "ImageFileName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAlgoThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    4,   37,    2, 0x06 /* Public */,
       9,    4,   46,    2, 0x06 /* Public */,
      12,    6,   55,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, QMetaType::Bool, QMetaType::Double,    5,    6,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Double, QMetaType::QString,   10,    7,    8,   11,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QString,    5,    6,    7,   11,   10,   13,

       0        // eod
};

void CAlgoThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CAlgoThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->inintSuccessSiganl((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->SendDetectionResult((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 2: _t->SendResultToTable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 3: _t->SendToSaveImg((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CAlgoThread::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAlgoThread::inintSuccessSiganl)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CAlgoThread::*)(cv::Mat & , cv::Mat & , bool , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAlgoThread::SendDetectionResult)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CAlgoThread::*)(int , bool , double , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAlgoThread::SendResultToTable)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CAlgoThread::*)(cv::Mat & , cv::Mat & , bool , QString , int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAlgoThread::SendToSaveImg)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CAlgoThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CAlgoThread.data,
    qt_meta_data_CAlgoThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CAlgoThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAlgoThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CAlgoThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int CAlgoThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CAlgoThread::inintSuccessSiganl(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CAlgoThread::SendDetectionResult(cv::Mat & _t1, cv::Mat & _t2, bool _t3, double _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CAlgoThread::SendResultToTable(int _t1, bool _t2, double _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CAlgoThread::SendToSaveImg(cv::Mat & _t1, cv::Mat & _t2, bool _t3, QString _t4, int _t5, QString _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
