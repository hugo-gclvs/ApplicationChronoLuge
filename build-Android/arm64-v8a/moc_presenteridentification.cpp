/****************************************************************************
** Meta object code from reading C++ file 'presenteridentification.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ChronoLuge/boundary/presenter/presenteridentification.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'presenteridentification.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PresenterIdentification_t {
    QByteArrayData data[13];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PresenterIdentification_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PresenterIdentification_t qt_meta_stringdata_PresenterIdentification = {
    {
QT_MOC_LITERAL(0, 0, 23), // "PresenterIdentification"
QT_MOC_LITERAL(1, 24, 11), // "creerCompte"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 6), // "pseudo"
QT_MOC_LITERAL(4, 44, 3), // "mdp"
QT_MOC_LITERAL(5, 48, 4), // "mail"
QT_MOC_LITERAL(6, 53, 3), // "nom"
QT_MOC_LITERAL(7, 57, 6), // "prenom"
QT_MOC_LITERAL(8, 64, 3), // "age"
QT_MOC_LITERAL(9, 68, 16), // "rechercherCompte"
QT_MOC_LITERAL(10, 85, 16), // "getMonController"
QT_MOC_LITERAL(11, 102, 25), // "VisualiserIdentification*"
QT_MOC_LITERAL(12, 128, 18) // "setEtatInscription"

    },
    "PresenterIdentification\0creerCompte\0"
    "\0pseudo\0mdp\0mail\0nom\0prenom\0age\0"
    "rechercherCompte\0getMonController\0"
    "VisualiserIdentification*\0setEtatInscription"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PresenterIdentification[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    6,   34,    2, 0x02 /* Public */,
       9,    2,   47,    2, 0x02 /* Public */,
      10,    0,   52,    2, 0x02 /* Public */,
      12,    0,   53,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,    8,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,    3,    4,
    0x80000000 | 11,
    QMetaType::Void,

       0        // eod
};

void PresenterIdentification::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PresenterIdentification *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->creerCompte((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->rechercherCompte((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { VisualiserIdentification* _r = _t->getMonController();
            if (_a[0]) *reinterpret_cast< VisualiserIdentification**>(_a[0]) = std::move(_r); }  break;
        case 3: _t->setEtatInscription(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PresenterIdentification::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_PresenterIdentification.data,
    qt_meta_data_PresenterIdentification,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PresenterIdentification::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PresenterIdentification::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PresenterIdentification.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PresenterIdentification::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
