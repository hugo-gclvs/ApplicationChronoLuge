/****************************************************************************
** Meta object code from reading C++ file 'visualisertempsvitesse.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ChronoLuge/controller/visualisertempsvitesse.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visualisertempsvitesse.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VisualiserTempsVitesse_t {
    QByteArrayData data[14];
    char stringdata0[227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VisualiserTempsVitesse_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VisualiserTempsVitesse_t qt_meta_stringdata_VisualiserTempsVitesse = {
    {
QT_MOC_LITERAL(0, 0, 22), // "VisualiserTempsVitesse"
QT_MOC_LITERAL(1, 23, 12), // "listeChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 16), // "postLierDescente"
QT_MOC_LITERAL(4, 54, 4), // "etat"
QT_MOC_LITERAL(5, 59, 9), // "postNewPP"
QT_MOC_LITERAL(6, 69, 14), // "valeurReussite"
QT_MOC_LITERAL(7, 84, 9), // "valeurPdp"
QT_MOC_LITERAL(8, 94, 16), // "getEtatConnexion"
QT_MOC_LITERAL(9, 111, 18), // "getEtatInscription"
QT_MOC_LITERAL(10, 130, 37), // "getControllerVisualiserIdenti..."
QT_MOC_LITERAL(11, 168, 25), // "VisualiserIdentification*"
QT_MOC_LITERAL(12, 194, 5), // "liste"
QT_MOC_LITERAL(13, 200, 26) // "QQmlListProperty<Descente>"

    },
    "VisualiserTempsVitesse\0listeChanged\0"
    "\0postLierDescente\0etat\0postNewPP\0"
    "valeurReussite\0valeurPdp\0getEtatConnexion\0"
    "getEtatInscription\0"
    "getControllerVisualiserIdentification\0"
    "VisualiserIdentification*\0liste\0"
    "QQmlListProperty<Descente>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VisualiserTempsVitesse[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       1,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       5,    2,   48,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       8,    0,   53,    2, 0x02 /* Public */,
       9,    0,   54,    2, 0x02 /* Public */,
      10,    0,   55,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    6,    7,

 // methods: parameters
    QMetaType::QString,
    QMetaType::QString,
    0x80000000 | 11,

 // properties: name, type, flags
      12, 0x80000000 | 13, 0x00495009,

 // properties: notify_signal_id
       0,

       0        // eod
};

void VisualiserTempsVitesse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VisualiserTempsVitesse *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->listeChanged(); break;
        case 1: _t->postLierDescente((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 2: _t->postNewPP((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: { QString _r = _t->getEtatConnexion();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->getEtatInscription();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { VisualiserIdentification* _r = _t->getControllerVisualiserIdentification();
            if (_a[0]) *reinterpret_cast< VisualiserIdentification**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VisualiserTempsVitesse::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VisualiserTempsVitesse::listeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VisualiserTempsVitesse::*)(const bool & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VisualiserTempsVitesse::postLierDescente)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VisualiserTempsVitesse::*)(bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VisualiserTempsVitesse::postNewPP)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<VisualiserTempsVitesse *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QQmlListProperty<Descente>*>(_v) = _t->getDescentes(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject VisualiserTempsVitesse::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_VisualiserTempsVitesse.data,
    qt_meta_data_VisualiserTempsVitesse,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VisualiserTempsVitesse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VisualiserTempsVitesse::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VisualiserTempsVitesse.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VisualiserTempsVitesse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void VisualiserTempsVitesse::listeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VisualiserTempsVitesse::postLierDescente(const bool & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VisualiserTempsVitesse::postNewPP(bool _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
