/****************************************************************************
** Meta object code from reading C++ file 'directwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tai-tai/directwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'directwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DirectWindow_t {
    QByteArrayData data[19];
    char stringdata0[288];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DirectWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DirectWindow_t qt_meta_stringdata_DirectWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DirectWindow"
QT_MOC_LITERAL(1, 13, 5), // "showA"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "hideA"
QT_MOC_LITERAL(4, 26, 17), // "profileAvaClicked"
QT_MOC_LITERAL(5, 44, 21), // "profileCaptionClicked"
QT_MOC_LITERAL(6, 66, 17), // "emailIndexChanged"
QT_MOC_LITERAL(7, 84, 5), // "index"
QT_MOC_LITERAL(8, 90, 22), // "changeProfileELClicked"
QT_MOC_LITERAL(9, 113, 20), // "editProfileELClicked"
QT_MOC_LITERAL(10, 134, 12), // "animatedShow"
QT_MOC_LITERAL(11, 147, 8), // "localPos"
QT_MOC_LITERAL(12, 156, 12), // "animatedHide"
QT_MOC_LITERAL(13, 169, 19), // "onProfileAvaClicked"
QT_MOC_LITERAL(14, 189, 23), // "onProfileCaptionClicked"
QT_MOC_LITERAL(15, 213, 14), // "onEmailChanged"
QT_MOC_LITERAL(16, 228, 24), // "onChangeProfileELClicked"
QT_MOC_LITERAL(17, 253, 22), // "onEditProfileLEClicked"
QT_MOC_LITERAL(18, 276, 11) // "setDefaults"

    },
    "DirectWindow\0showA\0\0hideA\0profileAvaClicked\0"
    "profileCaptionClicked\0emailIndexChanged\0"
    "index\0changeProfileELClicked\0"
    "editProfileELClicked\0animatedShow\0"
    "localPos\0animatedHide\0onProfileAvaClicked\0"
    "onProfileCaptionClicked\0onEmailChanged\0"
    "onChangeProfileELClicked\0"
    "onEditProfileLEClicked\0setDefaults"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DirectWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,
       6,    1,   93,    2, 0x06 /* Public */,
       8,    0,   96,    2, 0x06 /* Public */,
       9,    0,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   98,    2, 0x0a /* Public */,
      12,    0,  101,    2, 0x0a /* Public */,
      13,    0,  102,    2, 0x0a /* Public */,
      14,    0,  103,    2, 0x0a /* Public */,
      15,    1,  104,    2, 0x0a /* Public */,
      16,    0,  107,    2, 0x0a /* Public */,
      17,    0,  108,    2, 0x0a /* Public */,
      18,    0,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DirectWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DirectWindow *_t = static_cast<DirectWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showA(); break;
        case 1: _t->hideA(); break;
        case 2: _t->profileAvaClicked(); break;
        case 3: _t->profileCaptionClicked(); break;
        case 4: _t->emailIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->changeProfileELClicked(); break;
        case 6: _t->editProfileELClicked(); break;
        case 7: _t->animatedShow((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 8: _t->animatedHide(); break;
        case 9: _t->onProfileAvaClicked(); break;
        case 10: _t->onProfileCaptionClicked(); break;
        case 11: _t->onEmailChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->onChangeProfileELClicked(); break;
        case 13: _t->onEditProfileLEClicked(); break;
        case 14: _t->setDefaults(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DirectWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DirectWindow::showA)) {
                *result = 0;
            }
        }
        {
            typedef void (DirectWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DirectWindow::hideA)) {
                *result = 1;
            }
        }
        {
            typedef void (DirectWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DirectWindow::profileAvaClicked)) {
                *result = 2;
            }
        }
        {
            typedef void (DirectWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DirectWindow::profileCaptionClicked)) {
                *result = 3;
            }
        }
        {
            typedef void (DirectWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DirectWindow::emailIndexChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (DirectWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DirectWindow::changeProfileELClicked)) {
                *result = 5;
            }
        }
        {
            typedef void (DirectWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DirectWindow::editProfileELClicked)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject DirectWindow::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_DirectWindow.data,
      qt_meta_data_DirectWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DirectWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DirectWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DirectWindow.stringdata0))
        return static_cast<void*>(const_cast< DirectWindow*>(this));
    return QFrame::qt_metacast(_clname);
}

int DirectWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void DirectWindow::showA()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void DirectWindow::hideA()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void DirectWindow::profileAvaClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void DirectWindow::profileCaptionClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void DirectWindow::emailIndexChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DirectWindow::changeProfileELClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void DirectWindow::editProfileELClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
