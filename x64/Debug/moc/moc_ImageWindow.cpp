/****************************************************************************
** Meta object code from reading C++ file 'ImageWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../UI/ImageWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImageWindow_t {
    QByteArrayData data[25];
    char stringdata0[343];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageWindow_t qt_meta_stringdata_ImageWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ImageWindow"
QT_MOC_LITERAL(1, 12, 15), // "SendModelConfig"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "ModelChoice"
QT_MOC_LITERAL(4, 41, 13), // "SendThreshold"
QT_MOC_LITERAL(5, 55, 21), // "ChangeImageSourceBase"
QT_MOC_LITERAL(6, 77, 16), // "ImageSourceBase*"
QT_MOC_LITERAL(7, 94, 15), // "AddWindowSignal"
QT_MOC_LITERAL(8, 110, 14), // "SendCloseEvent"
QT_MOC_LITERAL(9, 125, 18), // "SetCameraStateSlot"
QT_MOC_LITERAL(10, 144, 6), // "isOpen"
QT_MOC_LITERAL(11, 151, 15), // "ImageSourceSlot"
QT_MOC_LITERAL(12, 167, 15), // "ModelChoiceSlot"
QT_MOC_LITERAL(13, 183, 16), // "ThresholdSetSlot"
QT_MOC_LITERAL(14, 200, 16), // "SetShowImageSlot"
QT_MOC_LITERAL(15, 217, 8), // "cv::Mat&"
QT_MOC_LITERAL(16, 226, 16), // "m_OriginalImages"
QT_MOC_LITERAL(17, 243, 14), // "m_RenderImages"
QT_MOC_LITERAL(18, 258, 3), // "bOK"
QT_MOC_LITERAL(19, 262, 4), // "Time"
QT_MOC_LITERAL(20, 267, 18), // "GetModelChoiceSlot"
QT_MOC_LITERAL(21, 286, 21), // "AlgoStatusChangleSlot"
QT_MOC_LITERAL(22, 308, 18), // "ShowRenderFlagSlot"
QT_MOC_LITERAL(23, 327, 11), // "MenuBtnSlot"
QT_MOC_LITERAL(24, 339, 3) // "pos"

    },
    "ImageWindow\0SendModelConfig\0\0ModelChoice\0"
    "SendThreshold\0ChangeImageSourceBase\0"
    "ImageSourceBase*\0AddWindowSignal\0"
    "SendCloseEvent\0SetCameraStateSlot\0"
    "isOpen\0ImageSourceSlot\0ModelChoiceSlot\0"
    "ThresholdSetSlot\0SetShowImageSlot\0"
    "cv::Mat&\0m_OriginalImages\0m_RenderImages\0"
    "bOK\0Time\0GetModelChoiceSlot\0"
    "AlgoStatusChangleSlot\0ShowRenderFlagSlot\0"
    "MenuBtnSlot\0pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    0,   87,    2, 0x06 /* Public */,
       5,    1,   88,    2, 0x06 /* Public */,
       7,    0,   91,    2, 0x06 /* Public */,
       8,    1,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   95,    2, 0x0a /* Public */,
      11,    0,   98,    2, 0x0a /* Public */,
      12,    0,   99,    2, 0x0a /* Public */,
      13,    0,  100,    2, 0x0a /* Public */,
      14,    4,  101,    2, 0x0a /* Public */,
      20,    1,  110,    2, 0x0a /* Public */,
      21,    1,  113,    2, 0x0a /* Public */,
      22,    0,  116,    2, 0x0a /* Public */,
      23,    1,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 15, QMetaType::Bool, QMetaType::Double,   16,   17,   18,   19,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   24,

       0        // eod
};

void ImageWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImageWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendModelConfig((*reinterpret_cast< ModelChoice(*)>(_a[1]))); break;
        case 1: _t->SendThreshold(); break;
        case 2: _t->ChangeImageSourceBase((*reinterpret_cast< ImageSourceBase*(*)>(_a[1]))); break;
        case 3: _t->AddWindowSignal(); break;
        case 4: _t->SendCloseEvent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->SetCameraStateSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->ImageSourceSlot(); break;
        case 7: _t->ModelChoiceSlot(); break;
        case 8: _t->ThresholdSetSlot(); break;
        case 9: _t->SetShowImageSlot((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 10: _t->GetModelChoiceSlot((*reinterpret_cast< ModelChoice(*)>(_a[1]))); break;
        case 11: _t->AlgoStatusChangleSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->ShowRenderFlagSlot(); break;
        case 13: _t->MenuBtnSlot((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ImageWindow::*)(ModelChoice );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageWindow::SendModelConfig)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ImageWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageWindow::SendThreshold)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ImageWindow::*)(ImageSourceBase * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageWindow::ChangeImageSourceBase)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ImageWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageWindow::AddWindowSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ImageWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageWindow::SendCloseEvent)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ImageWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ImageWindow.data,
    qt_meta_data_ImageWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ImageWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImageWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ImageWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ImageWindow::SendModelConfig(ModelChoice _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImageWindow::SendThreshold()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ImageWindow::ChangeImageSourceBase(ImageSourceBase * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ImageWindow::AddWindowSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ImageWindow::SendCloseEvent(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
