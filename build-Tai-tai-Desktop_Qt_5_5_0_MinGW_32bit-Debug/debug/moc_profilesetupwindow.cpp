/****************************************************************************
** Meta object code from reading C++ file 'profilesetupwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tai-tai/profilesetupwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'profilesetupwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ProfileSetupWindow_t {
    QByteArrayData data[18];
    char stringdata0[293];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProfileSetupWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProfileSetupWindow_t qt_meta_stringdata_ProfileSetupWindow = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ProfileSetupWindow"
QT_MOC_LITERAL(1, 19, 5), // "hide_"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "show_"
QT_MOC_LITERAL(4, 32, 12), // "profileAdded"
QT_MOC_LITERAL(5, 45, 16), // "setupLastProfile"
QT_MOC_LITERAL(6, 62, 19), // "addEmailLastProfile"
QT_MOC_LITERAL(7, 82, 12), // "animatedHide"
QT_MOC_LITERAL(8, 95, 14), // "onAvatarCliked"
QT_MOC_LITERAL(9, 110, 23), // "onCancelExButtonclicked"
QT_MOC_LITERAL(10, 134, 32), // "onSaveAndContinueExButtonClicked"
QT_MOC_LITERAL(11, 167, 30), // "onExtendedSetupExButtonClicked"
QT_MOC_LITERAL(12, 198, 25), // "onAddEmailExButtonClicked"
QT_MOC_LITERAL(13, 224, 15), // "clearAllContent"
QT_MOC_LITERAL(14, 240, 17), // "setCurrentProfile"
QT_MOC_LITERAL(15, 258, 8), // "Profile*"
QT_MOC_LITERAL(16, 267, 7), // "profile"
QT_MOC_LITERAL(17, 275, 17) // "createTempProfile"

    },
    "ProfileSetupWindow\0hide_\0\0show_\0"
    "profileAdded\0setupLastProfile\0"
    "addEmailLastProfile\0animatedHide\0"
    "onAvatarCliked\0onCancelExButtonclicked\0"
    "onSaveAndContinueExButtonClicked\0"
    "onExtendedSetupExButtonClicked\0"
    "onAddEmailExButtonClicked\0clearAllContent\0"
    "setCurrentProfile\0Profile*\0profile\0"
    "createTempProfile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProfileSetupWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    0,   87,    2, 0x06 /* Public */,
       6,    0,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x0a /* Public */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,
      14,    1,   96,    2, 0x0a /* Public */,
      17,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,

       0        // eod
};

void ProfileSetupWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProfileSetupWindow *_t = static_cast<ProfileSetupWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hide_(); break;
        case 1: _t->show_(); break;
        case 2: _t->profileAdded(); break;
        case 3: _t->setupLastProfile(); break;
        case 4: _t->addEmailLastProfile(); break;
        case 5: _t->animatedHide(); break;
        case 6: _t->onAvatarCliked(); break;
        case 7: _t->onCancelExButtonclicked(); break;
        case 8: { bool _r = _t->onSaveAndContinueExButtonClicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: _t->onExtendedSetupExButtonClicked(); break;
        case 10: _t->onAddEmailExButtonClicked(); break;
        case 11: _t->clearAllContent(); break;
        case 12: _t->setCurrentProfile((*reinterpret_cast< Profile*(*)>(_a[1]))); break;
        case 13: _t->createTempProfile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ProfileSetupWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProfileSetupWindow::hide_)) {
                *result = 0;
            }
        }
        {
            typedef void (ProfileSetupWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProfileSetupWindow::show_)) {
                *result = 1;
            }
        }
        {
            typedef void (ProfileSetupWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProfileSetupWindow::profileAdded)) {
                *result = 2;
            }
        }
        {
            typedef void (ProfileSetupWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProfileSetupWindow::setupLastProfile)) {
                *result = 3;
            }
        }
        {
            typedef void (ProfileSetupWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProfileSetupWindow::addEmailLastProfile)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject ProfileSetupWindow::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_ProfileSetupWindow.data,
      qt_meta_data_ProfileSetupWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ProfileSetupWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProfileSetupWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ProfileSetupWindow.stringdata0))
        return static_cast<void*>(const_cast< ProfileSetupWindow*>(this));
    return QFrame::qt_metacast(_clname);
}

int ProfileSetupWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
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
void ProfileSetupWindow::hide_()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ProfileSetupWindow::show_()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ProfileSetupWindow::profileAdded()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void ProfileSetupWindow::setupLastProfile()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void ProfileSetupWindow::addEmailLastProfile()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
