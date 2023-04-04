/****************************************************************************
** Meta object code from reading C++ file 'ProgrammeMannger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../SoftSetting/ProgrammeMannger/ProgrammeMannger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ProgrammeMannger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProgrammeMannger_t {
    QByteArrayData data[10];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProgrammeMannger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProgrammeMannger_t qt_meta_stringdata_ProgrammeMannger = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ProgrammeMannger"
QT_MOC_LITERAL(1, 17, 12), // "CreateNewPro"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 13), // "ChangeProSlot"
QT_MOC_LITERAL(4, 45, 10), // "NewProName"
QT_MOC_LITERAL(5, 56, 19), // "CreatePragrammeSlot"
QT_MOC_LITERAL(6, 76, 19), // "DeleteProgrammeSlot"
QT_MOC_LITERAL(7, 96, 20), // "DefaultProgrammeSlot"
QT_MOC_LITERAL(8, 117, 17), // "SaveProgrammeSlot"
QT_MOC_LITERAL(9, 135, 19) // "ChangeProgrammeSlot"

    },
    "ProgrammeMannger\0CreateNewPro\0\0"
    "ChangeProSlot\0NewProName\0CreatePragrammeSlot\0"
    "DeleteProgrammeSlot\0DefaultProgrammeSlot\0"
    "SaveProgrammeSlot\0ChangeProgrammeSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProgrammeMannger[] = {

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
       5,    0,   53,    2, 0x0a /* Public */,
       6,    0,   54,    2, 0x0a /* Public */,
       7,    0,   55,    2, 0x0a /* Public */,
       8,    0,   56,    2, 0x0a /* Public */,
       9,    0,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ProgrammeMannger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProgrammeMannger *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CreateNewPro(); break;
        case 1: _t->ChangeProSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->CreatePragrammeSlot(); break;
        case 3: _t->DeleteProgrammeSlot(); break;
        case 4: _t->DefaultProgrammeSlot(); break;
        case 5: _t->SaveProgrammeSlot(); break;
        case 6: _t->ChangeProgrammeSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ProgrammeMannger::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProgrammeMannger::CreateNewPro)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ProgrammeMannger::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProgrammeMannger::ChangeProSlot)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ProgrammeMannger::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ProgrammeMannger.data,
    qt_meta_data_ProgrammeMannger,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProgrammeMannger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProgrammeMannger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProgrammeMannger.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ProgrammeMannger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void ProgrammeMannger::CreateNewPro()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ProgrammeMannger::ChangeProSlot(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
