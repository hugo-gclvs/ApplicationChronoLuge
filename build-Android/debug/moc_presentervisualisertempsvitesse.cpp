/****************************************************************************
** Meta object code from reading C++ file 'presentervisualisertempsvitesse.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChronoLuge/boundary/presenter/presentervisualisertempsvitesse.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'presentervisualisertempsvitesse.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PresenterVisualiserTempsVitesse_t {
    QByteArrayData data[8];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PresenterVisualiserTempsVitesse_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PresenterVisualiserTempsVitesse_t qt_meta_stringdata_PresenterVisualiserTempsVitesse = {
    {
QT_MOC_LITERAL(0, 0, 31), // "PresenterVisualiserTempsVitesse"
QT_MOC_LITERAL(1, 32, 35), // "getControllerVisualiserTempsV..."
QT_MOC_LITERAL(2, 68, 23), // "VisualiserTempsVitesse*"
QT_MOC_LITERAL(3, 92, 0), // ""
QT_MOC_LITERAL(4, 93, 12), // "lierDescente"
QT_MOC_LITERAL(5, 106, 6), // "QRCode"
QT_MOC_LITERAL(6, 113, 20), // "rechercherHistorique"
QT_MOC_LITERAL(7, 134, 22) // "rechercherStatistiques"

    },
    "PresenterVisualiserTempsVitesse\0"
    "getControllerVisualiserTempsVitesse\0"
    "VisualiserTempsVitesse*\0\0lierDescente\0"
    "QRCode\0rechercherHistorique\0"
    "rechercherStatistiques"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PresenterVisualiserTempsVitesse[] = {

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
       1,    0,   34,    3, 0x02 /* Public */,
       4,    1,   35,    3, 0x02 /* Public */,
       6,    0,   38,    3, 0x02 /* Public */,
       7,    0,   39,    3, 0x02 /* Public */,

 // methods: parameters
    0x80000000 | 2,
    QMetaType::Bool, QMetaType::QString,    5,
    QMetaType::Bool,
    QMetaType::Bool,

       0        // eod
};

void PresenterVisualiserTempsVitesse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PresenterVisualiserTempsVitesse *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { VisualiserTempsVitesse* _r = _t->getControllerVisualiserTempsVitesse();
            if (_a[0]) *reinterpret_cast< VisualiserTempsVitesse**>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->lierDescente((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->rechercherHistorique();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->rechercherStatistiques();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PresenterVisualiserTempsVitesse::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_PresenterVisualiserTempsVitesse.data,
    qt_meta_data_PresenterVisualiserTempsVitesse,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PresenterVisualiserTempsVitesse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PresenterVisualiserTempsVitesse::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PresenterVisualiserTempsVitesse.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PresenterVisualiserTempsVitesse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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