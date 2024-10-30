/****************************************************************************
** Meta object code from reading C++ file 'fops.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "fops.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fops.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_fops_t {
    QByteArrayData data[18];
    char stringdata[301];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fops_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fops_t qt_meta_stringdata_fops = {
    {
QT_MOC_LITERAL(0, 0, 4), // "fops"
QT_MOC_LITERAL(1, 5, 12), // "give_message"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "message"
QT_MOC_LITERAL(4, 27, 12), // "give_vedname"
QT_MOC_LITERAL(5, 40, 8), // "ved_name"
QT_MOC_LITERAL(6, 49, 23), // "on_back_menu_bt_clicked"
QT_MOC_LITERAL(7, 73, 20), // "on_video_btn_clicked"
QT_MOC_LITERAL(8, 94, 20), // "on_photo_btn_clicked"
QT_MOC_LITERAL(9, 115, 18), // "on_del_btn_clicked"
QT_MOC_LITERAL(10, 134, 21), // "on_rename_btn_clicked"
QT_MOC_LITERAL(11, 156, 21), // "on_search_btn_clicked"
QT_MOC_LITERAL(12, 178, 33), // "slot_onReturnToFileIndexReque..."
QT_MOC_LITERAL(13, 212, 24), // "on_vidWidget_itemClicked"
QT_MOC_LITERAL(14, 237, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(15, 254, 4), // "item"
QT_MOC_LITERAL(16, 259, 24), // "on_picWidget_itemClicked"
QT_MOC_LITERAL(17, 284, 16) // "slot_itemClicked"

    },
    "fops\0give_message\0\0message\0give_vedname\0"
    "ved_name\0on_back_menu_bt_clicked\0"
    "on_video_btn_clicked\0on_photo_btn_clicked\0"
    "on_del_btn_clicked\0on_rename_btn_clicked\0"
    "on_search_btn_clicked\0"
    "slot_onReturnToFileIndexRequested\0"
    "on_vidWidget_itemClicked\0QListWidgetItem*\0"
    "item\0on_picWidget_itemClicked\0"
    "slot_itemClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fops[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   80,    2, 0x08 /* Private */,
       7,    0,   81,    2, 0x08 /* Private */,
       8,    0,   82,    2, 0x08 /* Private */,
       9,    0,   83,    2, 0x08 /* Private */,
      10,    0,   84,    2, 0x08 /* Private */,
      11,    0,   85,    2, 0x08 /* Private */,
      12,    0,   86,    2, 0x08 /* Private */,
      13,    1,   87,    2, 0x08 /* Private */,
      16,    1,   90,    2, 0x08 /* Private */,
      17,    1,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPixmap,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void fops::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fops *_t = static_cast<fops *>(_o);
        switch (_id) {
        case 0: _t->give_message((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 1: _t->give_vedname((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_back_menu_bt_clicked(); break;
        case 3: _t->on_video_btn_clicked(); break;
        case 4: _t->on_photo_btn_clicked(); break;
        case 5: _t->on_del_btn_clicked(); break;
        case 6: _t->on_rename_btn_clicked(); break;
        case 7: _t->on_search_btn_clicked(); break;
        case 8: _t->slot_onReturnToFileIndexRequested(); break;
        case 9: _t->on_vidWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->on_picWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 11: _t->slot_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (fops::*_t)(QPixmap );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fops::give_message)) {
                *result = 0;
            }
        }
        {
            typedef void (fops::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fops::give_vedname)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject fops::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_fops.data,
      qt_meta_data_fops,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *fops::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fops::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_fops.stringdata))
        return static_cast<void*>(const_cast< fops*>(this));
    return QWidget::qt_metacast(_clname);
}

int fops::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void fops::give_message(QPixmap _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void fops::give_vedname(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
