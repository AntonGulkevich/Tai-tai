/****************************************************************************
** Meta object code from reading C++ file 'threadimap.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tai-tai/threadimap.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadimap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ThreadImap_t {
    QByteArrayData data[14];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreadImap_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreadImap_t qt_meta_stringdata_ThreadImap = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ThreadImap"
QT_MOC_LITERAL(1, 11, 18), // "get20MessageSignal"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 16), // "getMessageSignal"
QT_MOC_LITERAL(4, 48, 6), // "number"
QT_MOC_LITERAL(5, 55, 6), // "update"
QT_MOC_LITERAL(6, 62, 13), // "deleteMessage"
QT_MOC_LITERAL(7, 76, 13), // "getMessageTop"
QT_MOC_LITERAL(8, 90, 7), // "Message"
QT_MOC_LITERAL(9, 98, 3), // "top"
QT_MOC_LITERAL(10, 102, 10), // "getMessage"
QT_MOC_LITERAL(11, 113, 3), // "msg"
QT_MOC_LITERAL(12, 117, 8), // "getError"
QT_MOC_LITERAL(13, 126, 8) // "messsage"

    },
    "ThreadImap\0get20MessageSignal\0\0"
    "getMessageSignal\0number\0update\0"
    "deleteMessage\0getMessageTop\0Message\0"
    "top\0getMessage\0msg\0getError\0messsage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadImap[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,
       5,    0,   53,    2, 0x06 /* Public */,
       6,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   57,    2, 0x0a /* Public */,
      10,    1,   60,    2, 0x0a /* Public */,
      12,    1,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,   11,
    QMetaType::Void, QMetaType::QString,   13,

       0        // eod
};

void ThreadImap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ThreadImap *_t = static_cast<ThreadImap *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->get20MessageSignal(); break;
        case 1: _t->getMessageSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->update(); break;
        case 3: _t->deleteMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->getMessageTop((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 5: _t->getMessage((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 6: _t->getError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ThreadImap::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadImap::get20MessageSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (ThreadImap::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadImap::getMessageSignal)) {
                *result = 1;
            }
        }
        {
            typedef void (ThreadImap::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadImap::update)) {
                *result = 2;
            }
        }
        {
            typedef void (ThreadImap::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadImap::deleteMessage)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject ThreadImap::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ThreadImap.data,
      qt_meta_data_ThreadImap,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ThreadImap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadImap::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadImap.stringdata0))
        return static_cast<void*>(const_cast< ThreadImap*>(this));
    return QObject::qt_metacast(_clname);
}

int ThreadImap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void ThreadImap::get20MessageSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ThreadImap::getMessageSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ThreadImap::update()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void ThreadImap::deleteMessage(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
