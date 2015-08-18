/****************************************************************************
** Meta object code from reading C++ file 'profileeditwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tai-tai/profileeditwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'profileeditwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ProfileEditWindow_t {
    QByteArrayData data[13];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProfileEditWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProfileEditWindow_t qt_meta_stringdata_ProfileEditWindow = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ProfileEditWindow"
QT_MOC_LITERAL(1, 18, 5), // "hide_"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "show_"
QT_MOC_LITERAL(4, 31, 15), // "clearAllContent"
QT_MOC_LITERAL(5, 47, 22), // "onSaveAndExitEBClicked"
QT_MOC_LITERAL(6, 70, 15), // "onBackEBClicked"
QT_MOC_LITERAL(7, 86, 18), // "onDefaultEBClicked"
QT_MOC_LITERAL(8, 105, 18), // "onApproveEBClicked"
QT_MOC_LITERAL(9, 124, 16), // "onEmailELClicked"
QT_MOC_LITERAL(10, 141, 17), // "setCurrentProfile"
QT_MOC_LITERAL(11, 159, 8), // "Profile*"
QT_MOC_LITERAL(12, 168, 7) // "profile"

    },
    "ProfileEditWindow\0hide_\0\0show_\0"
    "clearAllContent\0onSaveAndExitEBClicked\0"
    "onBackEBClicked\0onDefaultEBClicked\0"
    "onApproveEBClicked\0onEmailELClicked\0"
    "setCurrentProfile\0Profile*\0profile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProfileEditWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    1,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void ProfileEditWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProfileEditWindow *_t = static_cast<ProfileEditWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hide_(); break;
        case 1: _t->show_(); break;
        case 2: _t->clearAllContent(); break;
        case 3: _t->onSaveAndExitEBClicked(); break;
        case 4: _t->onBackEBClicked(); break;
        case 5: _t->onDefaultEBClicked(); break;
        case 6: _t->onApproveEBClicked(); break;
        case 7: _t->onEmailELClicked(); break;
        case 8: _t->setCurrentProfile((*reinterpret_cast< Profile*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ProfileEditWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProfileEditWindow::hide_)) {
                *result = 0;
            }
        }
        {
            typedef void (ProfileEditWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProfileEditWindow::show_)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ProfileEditWindow::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_ProfileEditWindow.data,
      qt_meta_data_ProfileEditWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ProfileEditWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProfileEditWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ProfileEditWindow.stringdata0))
        return static_cast<void*>(const_cast< ProfileEditWindow*>(this));
    return QFrame::qt_metacast(_clname);
}

int ProfileEditWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ProfileEditWindow::hide_()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ProfileEditWindow::show_()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
