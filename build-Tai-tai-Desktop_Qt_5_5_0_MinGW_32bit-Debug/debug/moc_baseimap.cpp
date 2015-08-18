/****************************************************************************
** Meta object code from reading C++ file 'baseimap.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tai-tai/baseimap.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'baseimap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BaseImap_t {
    QByteArrayData data[15];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaseImap_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaseImap_t qt_meta_stringdata_BaseImap = {
    {
QT_MOC_LITERAL(0, 0, 8), // "BaseImap"
QT_MOC_LITERAL(1, 9, 5), // "Error"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 7), // "Message"
QT_MOC_LITERAL(4, 24, 9), // "MessageOK"
QT_MOC_LITERAL(5, 34, 7), // "message"
QT_MOC_LITERAL(6, 42, 12), // "MessageTopOK"
QT_MOC_LITERAL(7, 55, 3), // "top"
QT_MOC_LITERAL(8, 59, 3), // "run"
QT_MOC_LITERAL(9, 63, 9), // "updateTCP"
QT_MOC_LITERAL(10, 73, 10), // "getMessage"
QT_MOC_LITERAL(11, 84, 6), // "number"
QT_MOC_LITERAL(12, 91, 13), // "deleteMessage"
QT_MOC_LITERAL(13, 105, 12), // "get20Message"
QT_MOC_LITERAL(14, 118, 6) // "update"

    },
    "BaseImap\0Error\0\0Message\0MessageOK\0"
    "message\0MessageTopOK\0top\0run\0updateTCP\0"
    "getMessage\0number\0deleteMessage\0"
    "get20Message\0update"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaseImap[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   68,    2, 0x0a /* Public */,
       9,    0,   69,    2, 0x0a /* Public */,
      10,    1,   70,    2, 0x0a /* Public */,
      12,    1,   73,    2, 0x0a /* Public */,
      13,    0,   76,    2, 0x0a /* Public */,
      14,    0,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 3,    5,
    QMetaType::Void, 0x80000000 | 3,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BaseImap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BaseImap *_t = static_cast<BaseImap *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->MessageOK((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 2: _t->MessageTopOK((*reinterpret_cast< Message(*)>(_a[1]))); break;
        case 3: _t->run(); break;
        case 4: _t->updateTCP(); break;
        case 5: _t->getMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->deleteMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->get20Message(); break;
        case 8: _t->update(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BaseImap::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BaseImap::Error)) {
                *result = 0;
            }
        }
        {
            typedef void (BaseImap::*_t)(Message );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BaseImap::MessageOK)) {
                *result = 1;
            }
        }
        {
            typedef void (BaseImap::*_t)(Message );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BaseImap::MessageTopOK)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject BaseImap::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BaseImap.data,
      qt_meta_data_BaseImap,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BaseImap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaseImap::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BaseImap.stringdata0))
        return static_cast<void*>(const_cast< BaseImap*>(this));
    return QObject::qt_metacast(_clname);
}

int BaseImap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void BaseImap::Error(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BaseImap::MessageOK(Message _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BaseImap::MessageTopOK(Message _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
