/****************************************************************************
** Meta object code from reading C++ file 'exbutton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tai-tai/exbutton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'exbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ExButton_t {
    QByteArrayData data[11];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExButton_t qt_meta_stringdata_ExButton = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ExButton"
QT_MOC_LITERAL(1, 9, 12), // "rightClicked"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "leftClicked"
QT_MOC_LITERAL(4, 35, 12), // "mouseEntered"
QT_MOC_LITERAL(5, 48, 11), // "mouseLeaved"
QT_MOC_LITERAL(6, 60, 14), // "blockAnimation"
QT_MOC_LITERAL(7, 75, 16), // "unBlockAnimation"
QT_MOC_LITERAL(8, 92, 16), // "minimizeAnimated"
QT_MOC_LITERAL(9, 109, 16), // "maximizeAnimated"
QT_MOC_LITERAL(10, 126, 12) // "setDefaultSS"

    },
    "ExButton\0rightClicked\0\0leftClicked\0"
    "mouseEntered\0mouseLeaved\0blockAnimation\0"
    "unBlockAnimation\0minimizeAnimated\0"
    "maximizeAnimated\0setDefaultSS"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ExButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExButton *_t = static_cast<ExButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rightClicked(); break;
        case 1: _t->leftClicked(); break;
        case 2: _t->mouseEntered(); break;
        case 3: _t->mouseLeaved(); break;
        case 4: _t->blockAnimation(); break;
        case 5: _t->unBlockAnimation(); break;
        case 6: _t->minimizeAnimated(); break;
        case 7: _t->maximizeAnimated(); break;
        case 8: _t->setDefaultSS(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ExButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ExButton::rightClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (ExButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ExButton::leftClicked)) {
                *result = 1;
            }
        }
        {
            typedef void (ExButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ExButton::mouseEntered)) {
                *result = 2;
            }
        }
        {
            typedef void (ExButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ExButton::mouseLeaved)) {
                *result = 3;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ExButton::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_ExButton.data,
      qt_meta_data_ExButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ExButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ExButton.stringdata0))
        return static_cast<void*>(const_cast< ExButton*>(this));
    return QFrame::qt_metacast(_clname);
}

int ExButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ExButton::rightClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ExButton::leftClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ExButton::mouseEntered()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void ExButton::mouseLeaved()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
