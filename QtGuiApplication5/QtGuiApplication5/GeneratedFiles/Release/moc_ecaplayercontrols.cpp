/****************************************************************************
** Meta object code from reading C++ file 'ecaplayercontrols.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ecaplayercontrols.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ecaplayercontrols.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EcaPlayerControls_t {
    QByteArrayData data[9];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EcaPlayerControls_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EcaPlayerControls_t qt_meta_stringdata_EcaPlayerControls = {
    {
QT_MOC_LITERAL(0, 0, 17), // "EcaPlayerControls"
QT_MOC_LITERAL(1, 18, 4), // "play"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "pause"
QT_MOC_LITERAL(4, 30, 4), // "stop"
QT_MOC_LITERAL(5, 35, 12), // "changeVolume"
QT_MOC_LITERAL(6, 48, 6), // "volume"
QT_MOC_LITERAL(7, 55, 12), // "changeMuting"
QT_MOC_LITERAL(8, 68, 6) // "muting"

    },
    "EcaPlayerControls\0play\0\0pause\0stop\0"
    "changeVolume\0volume\0changeMuting\0"
    "muting"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EcaPlayerControls[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,
       7,    1,   45,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    8,

       0        // eod
};

void EcaPlayerControls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EcaPlayerControls *_t = static_cast<EcaPlayerControls *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->play(); break;
        case 1: _t->pause(); break;
        case 2: _t->stop(); break;
        case 3: _t->changeVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->changeMuting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (EcaPlayerControls::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EcaPlayerControls::play)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (EcaPlayerControls::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EcaPlayerControls::pause)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (EcaPlayerControls::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EcaPlayerControls::stop)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (EcaPlayerControls::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EcaPlayerControls::changeVolume)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (EcaPlayerControls::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EcaPlayerControls::changeMuting)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EcaPlayerControls::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EcaPlayerControls.data,
      qt_meta_data_EcaPlayerControls,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EcaPlayerControls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EcaPlayerControls::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EcaPlayerControls.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int EcaPlayerControls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void EcaPlayerControls::play()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void EcaPlayerControls::pause()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void EcaPlayerControls::stop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void EcaPlayerControls::changeVolume(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void EcaPlayerControls::changeMuting(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
