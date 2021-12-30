/****************************************************************************
** Meta object code from reading C++ file 'athhandler.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Authentication/athhandler.h"
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'athhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AthHandler_t {
    const uint offsetsAndSize[10];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AthHandler_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AthHandler_t qt_meta_stringdata_AthHandler = {
    {
QT_MOC_LITERAL(0, 10), // "AthHandler"
QT_MOC_LITERAL(11, 12), // "userSignedIn"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 21), // "networkReplyReadyRead"
QT_MOC_LITERAL(47, 32) // "performAuthenticatedDatabaseCall"

    },
    "AthHandler\0userSignedIn\0\0networkReplyReadyRead\0"
    "performAuthenticatedDatabaseCall"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AthHandler[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   33,    2, 0x0a,    1 /* Public */,
       4,    0,   34,    2, 0x0a,    2 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AthHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AthHandler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->userSignedIn(); break;
        case 1: _t->networkReplyReadyRead(); break;
        case 2: _t->performAuthenticatedDatabaseCall(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AthHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AthHandler::userSignedIn)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject AthHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AthHandler.offsetsAndSize,
    qt_meta_data_AthHandler,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AthHandler_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *AthHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AthHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AthHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AthHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void AthHandler::userSignedIn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
