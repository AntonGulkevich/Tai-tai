/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tai-tai/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "someWindowOpened"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 16), // "someWindowClosed"
QT_MOC_LITERAL(4, 46, 14), // "updateProfiles"
QT_MOC_LITERAL(5, 61, 12), // "loginProfile"
QT_MOC_LITERAL(6, 74, 8), // "Profile*"
QT_MOC_LITERAL(7, 83, 7), // "profile"
QT_MOC_LITERAL(8, 91, 13), // "logoutProfile"
QT_MOC_LITERAL(9, 105, 12), // "subwindowsOn"
QT_MOC_LITERAL(10, 118, 13), // "subwindowsOff"
QT_MOC_LITERAL(11, 132, 20), // "onCloseButtonClicked"
QT_MOC_LITERAL(12, 153, 13), // "resizeOverlay"
QT_MOC_LITERAL(13, 167, 21), // "onProfileLabelClicked"
QT_MOC_LITERAL(14, 189, 14), // "accountChanged"
QT_MOC_LITERAL(15, 204, 3), // "pos"
QT_MOC_LITERAL(16, 208, 7), // "reLogin"
QT_MOC_LITERAL(17, 216, 11), // "overLayShow"
QT_MOC_LITERAL(18, 228, 12), // "overLayClose"
QT_MOC_LITERAL(19, 241, 11) // "editProfile"

    },
    "MainWindow\0someWindowOpened\0\0"
    "someWindowClosed\0updateProfiles\0"
    "loginProfile\0Profile*\0profile\0"
    "logoutProfile\0subwindowsOn\0subwindowsOff\0"
    "onCloseButtonClicked\0resizeOverlay\0"
    "onProfileLabelClicked\0accountChanged\0"
    "pos\0reLogin\0overLayShow\0overLayClose\0"
    "editProfile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       4,    0,   91,    2, 0x08 /* Private */,
       5,    1,   92,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    1,  101,    2, 0x08 /* Private */,
      16,    0,  104,    2, 0x08 /* Private */,
      17,    0,  105,    2, 0x08 /* Private */,
      18,    0,  106,    2, 0x08 /* Private */,
      19,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->someWindowOpened(); break;
        case 1: _t->someWindowClosed(); break;
        case 2: _t->updateProfiles(); break;
        case 3: _t->loginProfile((*reinterpret_cast< Profile*(*)>(_a[1]))); break;
        case 4: _t->logoutProfile(); break;
        case 5: _t->subwindowsOn(); break;
        case 6: _t->subwindowsOff(); break;
        case 7: _t->onCloseButtonClicked(); break;
        case 8: _t->resizeOverlay(); break;
        case 9: _t->onProfileLabelClicked(); break;
        case 10: _t->accountChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->reLogin(); break;
        case 12: _t->overLayShow(); break;
        case 13: _t->overLayClose(); break;
        case 14: _t->editProfile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::someWindowOpened)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::someWindowClosed)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QFrame::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::someWindowOpened()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainWindow::someWindowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
