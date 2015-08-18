/****************************************************************************
** Meta object code from reading C++ file 'addnewemailwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tai-tai/addnewemailwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addnewemailwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddNewEmailWindow_t {
    QByteArrayData data[17];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddNewEmailWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddNewEmailWindow_t qt_meta_stringdata_AddNewEmailWindow = {
    {
QT_MOC_LITERAL(0, 0, 17), // "AddNewEmailWindow"
QT_MOC_LITERAL(1, 18, 5), // "hide_"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "show_"
QT_MOC_LITERAL(4, 31, 20), // "addedNewEmailAccount"
QT_MOC_LITERAL(5, 52, 22), // "onSaveAndExitEBClicked"
QT_MOC_LITERAL(6, 75, 15), // "onBackEBClicked"
QT_MOC_LITERAL(7, 91, 18), // "onDefaultEBClicked"
QT_MOC_LITERAL(8, 110, 18), // "onApproveEBClicked"
QT_MOC_LITERAL(9, 129, 21), // "onCheckEmailEBClicked"
QT_MOC_LITERAL(10, 151, 17), // "setCurrentProfile"
QT_MOC_LITERAL(11, 169, 8), // "Profile*"
QT_MOC_LITERAL(12, 178, 7), // "profile"
QT_MOC_LITERAL(13, 186, 16), // "autoFillProtocol"
QT_MOC_LITERAL(14, 203, 11), // "setDefaults"
QT_MOC_LITERAL(15, 215, 17), // "setDefaultSSLogin"
QT_MOC_LITERAL(16, 233, 20) // "setDefaultSSPassword"

    },
    "AddNewEmailWindow\0hide_\0\0show_\0"
    "addedNewEmailAccount\0onSaveAndExitEBClicked\0"
    "onBackEBClicked\0onDefaultEBClicked\0"
    "onApproveEBClicked\0onCheckEmailEBClicked\0"
    "setCurrentProfile\0Profile*\0profile\0"
    "autoFillProtocol\0setDefaults\0"
    "setDefaultSSLogin\0setDefaultSSPassword"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddNewEmailWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   82,    2, 0x0a /* Public */,
       6,    0,   83,    2, 0x0a /* Public */,
       7,    0,   84,    2, 0x0a /* Public */,
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    1,   87,    2, 0x0a /* Public */,
      13,    0,   90,    2, 0x0a /* Public */,
      14,    0,   91,    2, 0x0a /* Public */,
      15,    0,   92,    2, 0x0a /* Public */,
      16,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AddNewEmailWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddNewEmailWindow *_t = static_cast<AddNewEmailWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hide_(); break;
        case 1: _t->show_(); break;
        case 2: _t->addedNewEmailAccount(); break;
        case 3: _t->onSaveAndExitEBClicked(); break;
        case 4: _t->onBackEBClicked(); break;
        case 5: _t->onDefaultEBClicked(); break;
        case 6: { bool _r = _t->onApproveEBClicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->onCheckEmailEBClicked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->setCurrentProfile((*reinterpret_cast< Profile*(*)>(_a[1]))); break;
        case 9: _t->autoFillProtocol(); break;
        case 10: _t->setDefaults(); break;
        case 11: _t->setDefaultSSLogin(); break;
        case 12: _t->setDefaultSSPassword(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AddNewEmailWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddNewEmailWindow::hide_)) {
                *result = 0;
            }
        }
        {
            typedef void (AddNewEmailWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddNewEmailWindow::show_)) {
                *result = 1;
            }
        }
        {
            typedef void (AddNewEmailWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddNewEmailWindow::addedNewEmailAccount)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject AddNewEmailWindow::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_AddNewEmailWindow.data,
      qt_meta_data_AddNewEmailWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddNewEmailWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddNewEmailWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddNewEmailWindow.stringdata0))
        return static_cast<void*>(const_cast< AddNewEmailWindow*>(this));
    return QFrame::qt_metacast(_clname);
}

int AddNewEmailWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void AddNewEmailWindow::hide_()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void AddNewEmailWindow::show_()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void AddNewEmailWindow::addedNewEmailAccount()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
