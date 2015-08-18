/****************************************************************************
** Meta object code from reading C++ file 'emaileditwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tai-tai/emaileditwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'emaileditwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EmailEditWindow_t {
    QByteArrayData data[22];
    char stringdata0[308];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EmailEditWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EmailEditWindow_t qt_meta_stringdata_EmailEditWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "EmailEditWindow"
QT_MOC_LITERAL(1, 16, 5), // "hide_"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "show_"
QT_MOC_LITERAL(4, 29, 15), // "clearAllContent"
QT_MOC_LITERAL(5, 45, 17), // "setCurrentProfile"
QT_MOC_LITERAL(6, 63, 8), // "Profile*"
QT_MOC_LITERAL(7, 72, 7), // "profile"
QT_MOC_LITERAL(8, 80, 20), // "setAddNewEmailWindow"
QT_MOC_LITERAL(9, 101, 18), // "AddNewEmailWindow*"
QT_MOC_LITERAL(10, 120, 6), // "window"
QT_MOC_LITERAL(11, 127, 18), // "addNewEmailAccount"
QT_MOC_LITERAL(12, 146, 4), // "name"
QT_MOC_LITERAL(13, 151, 22), // "onSaveAndExitEBClicked"
QT_MOC_LITERAL(14, 174, 15), // "onBackEBClicked"
QT_MOC_LITERAL(15, 190, 19), // "onAddEmailEBClicked"
QT_MOC_LITERAL(16, 210, 18), // "onApproveEBClicked"
QT_MOC_LITERAL(17, 229, 17), // "onDeleteEBClicked"
QT_MOC_LITERAL(18, 247, 15), // "onEditEBClicked"
QT_MOC_LITERAL(19, 263, 12), // "animatedShow"
QT_MOC_LITERAL(20, 276, 15), // "clearEmailTable"
QT_MOC_LITERAL(21, 292, 15) // "fillEmailsTable"

    },
    "EmailEditWindow\0hide_\0\0show_\0"
    "clearAllContent\0setCurrentProfile\0"
    "Profile*\0profile\0setAddNewEmailWindow\0"
    "AddNewEmailWindow*\0window\0addNewEmailAccount\0"
    "name\0onSaveAndExitEBClicked\0onBackEBClicked\0"
    "onAddEmailEBClicked\0onApproveEBClicked\0"
    "onDeleteEBClicked\0onEditEBClicked\0"
    "animatedShow\0clearEmailTable\0"
    "fillEmailsTable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EmailEditWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   91,    2, 0x0a /* Public */,
       5,    1,   92,    2, 0x0a /* Public */,
       8,    1,   95,    2, 0x0a /* Public */,
      11,    1,   98,    2, 0x0a /* Public */,
      13,    0,  101,    2, 0x0a /* Public */,
      14,    0,  102,    2, 0x0a /* Public */,
      15,    0,  103,    2, 0x0a /* Public */,
      16,    0,  104,    2, 0x0a /* Public */,
      17,    0,  105,    2, 0x0a /* Public */,
      18,    0,  106,    2, 0x0a /* Public */,
      19,    0,  107,    2, 0x0a /* Public */,
      20,    0,  108,    2, 0x0a /* Public */,
      21,    0,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString,   12,
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

void EmailEditWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EmailEditWindow *_t = static_cast<EmailEditWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hide_(); break;
        case 1: _t->show_(); break;
        case 2: _t->clearAllContent(); break;
        case 3: _t->setCurrentProfile((*reinterpret_cast< Profile*(*)>(_a[1]))); break;
        case 4: _t->setAddNewEmailWindow((*reinterpret_cast< AddNewEmailWindow*(*)>(_a[1]))); break;
        case 5: _t->addNewEmailAccount((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->onSaveAndExitEBClicked(); break;
        case 7: _t->onBackEBClicked(); break;
        case 8: _t->onAddEmailEBClicked(); break;
        case 9: _t->onApproveEBClicked(); break;
        case 10: _t->onDeleteEBClicked(); break;
        case 11: _t->onEditEBClicked(); break;
        case 12: _t->animatedShow(); break;
        case 13: _t->clearEmailTable(); break;
        case 14: _t->fillEmailsTable(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AddNewEmailWindow* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EmailEditWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EmailEditWindow::hide_)) {
                *result = 0;
            }
        }
        {
            typedef void (EmailEditWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EmailEditWindow::show_)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject EmailEditWindow::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_EmailEditWindow.data,
      qt_meta_data_EmailEditWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EmailEditWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EmailEditWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EmailEditWindow.stringdata0))
        return static_cast<void*>(const_cast< EmailEditWindow*>(this));
    return QFrame::qt_metacast(_clname);
}

int EmailEditWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void EmailEditWindow::hide_()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void EmailEditWindow::show_()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
