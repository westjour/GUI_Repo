/****************************************************************************
** Meta object code from reading C++ file 'CWindowWDB.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../proj/CWindowWDB.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CWindowWDB.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CWindowWDB_t {
    QByteArrayData data[9];
    char stringdata[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CWindowWDB_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CWindowWDB_t qt_meta_stringdata_CWindowWDB = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CWindowWDB"
QT_MOC_LITERAL(1, 11, 19), // "stationIndexChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "text"
QT_MOC_LITERAL(4, 37, 16), // "yearIndexChanged"
QT_MOC_LITERAL(5, 54, 10), // "onFileSave"
QT_MOC_LITERAL(6, 65, 10), // "onFileOpen"
QT_MOC_LITERAL(7, 76, 20), // "onStationDataChanged"
QT_MOC_LITERAL(8, 97, 5) // "field"

    },
    "CWindowWDB\0stationIndexChanged\0\0text\0"
    "yearIndexChanged\0onFileSave\0onFileOpen\0"
    "onStationDataChanged\0field"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CWindowWDB[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       5,    0,   45,    2, 0x0a /* Public */,
       6,    0,   46,    2, 0x0a /* Public */,
       7,    1,   47,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void CWindowWDB::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CWindowWDB *_t = static_cast<CWindowWDB *>(_o);
        switch (_id) {
        case 0: _t->stationIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->yearIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->onFileSave(); break;
        case 3: _t->onFileOpen(); break;
        case 4: _t->onStationDataChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CWindowWDB::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CWindowWDB.data,
      qt_meta_data_CWindowWDB,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CWindowWDB::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CWindowWDB::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CWindowWDB.stringdata))
        return static_cast<void*>(const_cast< CWindowWDB*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CWindowWDB::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
