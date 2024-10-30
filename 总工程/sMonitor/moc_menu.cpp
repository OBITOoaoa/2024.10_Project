/****************************************************************************
** Meta object code from reading C++ file 'menu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "menu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_menu_t {
    QByteArrayData data[26];
    char stringdata[509];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_menu_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_menu_t qt_meta_stringdata_menu = {
    {
QT_MOC_LITERAL(0, 0, 4), // "menu"
QT_MOC_LITERAL(1, 5, 25), // "on_swt_Control_bt_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 25), // "on_file_Manage_bt_clicked"
QT_MOC_LITERAL(4, 58, 21), // "on_turn_up_bt_pressed"
QT_MOC_LITERAL(5, 80, 23), // "on_turn_left_bt_pressed"
QT_MOC_LITERAL(6, 104, 23), // "on_turn_down_bt_pressed"
QT_MOC_LITERAL(7, 128, 24), // "on_turn_right_bt_pressed"
QT_MOC_LITERAL(8, 153, 24), // "on_turn_reset_bt_clicked"
QT_MOC_LITERAL(9, 178, 19), // "on_auto_btn_clicked"
QT_MOC_LITERAL(10, 198, 22), // "slot_autoTimer_timeout"
QT_MOC_LITERAL(11, 221, 28), // "on_angle_slider_valueChanged"
QT_MOC_LITERAL(12, 250, 5), // "value"
QT_MOC_LITERAL(13, 256, 28), // "on_speed_slider_valueChanged"
QT_MOC_LITERAL(14, 285, 23), // "on_get_video_bt_clicked"
QT_MOC_LITERAL(15, 309, 23), // "on_get_photo_bt_clicked"
QT_MOC_LITERAL(16, 333, 21), // "on_capture_bt_clicked"
QT_MOC_LITERAL(17, 355, 11), // "CaptureOpen"
QT_MOC_LITERAL(18, 367, 13), // "slot_fpsTimer"
QT_MOC_LITERAL(19, 381, 22), // "slot_updateCurrentTime"
QT_MOC_LITERAL(20, 404, 17), // "Subclient_Hanlder"
QT_MOC_LITERAL(21, 422, 13), // "DataRecvParse"
QT_MOC_LITERAL(22, 436, 14), // "QMQTT::Message"
QT_MOC_LITERAL(23, 451, 27), // "on_mqtt_transfer_bt_clicked"
QT_MOC_LITERAL(24, 479, 20), // "onThumbnailGenerated"
QT_MOC_LITERAL(25, 500, 8) // "exitCode"

    },
    "menu\0on_swt_Control_bt_clicked\0\0"
    "on_file_Manage_bt_clicked\0"
    "on_turn_up_bt_pressed\0on_turn_left_bt_pressed\0"
    "on_turn_down_bt_pressed\0"
    "on_turn_right_bt_pressed\0"
    "on_turn_reset_bt_clicked\0on_auto_btn_clicked\0"
    "slot_autoTimer_timeout\0"
    "on_angle_slider_valueChanged\0value\0"
    "on_speed_slider_valueChanged\0"
    "on_get_video_bt_clicked\0on_get_photo_bt_clicked\0"
    "on_capture_bt_clicked\0CaptureOpen\0"
    "slot_fpsTimer\0slot_updateCurrentTime\0"
    "Subclient_Hanlder\0DataRecvParse\0"
    "QMQTT::Message\0on_mqtt_transfer_bt_clicked\0"
    "onThumbnailGenerated\0exitCode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_menu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x08 /* Private */,
       3,    0,  120,    2, 0x08 /* Private */,
       4,    0,  121,    2, 0x08 /* Private */,
       5,    0,  122,    2, 0x08 /* Private */,
       6,    0,  123,    2, 0x08 /* Private */,
       7,    0,  124,    2, 0x08 /* Private */,
       8,    0,  125,    2, 0x08 /* Private */,
       9,    0,  126,    2, 0x08 /* Private */,
      10,    0,  127,    2, 0x08 /* Private */,
      11,    1,  128,    2, 0x08 /* Private */,
      13,    1,  131,    2, 0x08 /* Private */,
      14,    0,  134,    2, 0x08 /* Private */,
      15,    0,  135,    2, 0x08 /* Private */,
      16,    0,  136,    2, 0x08 /* Private */,
      17,    0,  137,    2, 0x08 /* Private */,
      18,    0,  138,    2, 0x08 /* Private */,
      19,    0,  139,    2, 0x08 /* Private */,
      20,    0,  140,    2, 0x08 /* Private */,
      21,    1,  141,    2, 0x08 /* Private */,
      23,    0,  144,    2, 0x08 /* Private */,
      24,    1,  145,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,

       0        // eod
};

void menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        menu *_t = static_cast<menu *>(_o);
        switch (_id) {
        case 0: _t->on_swt_Control_bt_clicked(); break;
        case 1: _t->on_file_Manage_bt_clicked(); break;
        case 2: _t->on_turn_up_bt_pressed(); break;
        case 3: _t->on_turn_left_bt_pressed(); break;
        case 4: _t->on_turn_down_bt_pressed(); break;
        case 5: _t->on_turn_right_bt_pressed(); break;
        case 6: _t->on_turn_reset_bt_clicked(); break;
        case 7: _t->on_auto_btn_clicked(); break;
        case 8: _t->slot_autoTimer_timeout(); break;
        case 9: _t->on_angle_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_speed_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_get_video_bt_clicked(); break;
        case 12: _t->on_get_photo_bt_clicked(); break;
        case 13: _t->on_capture_bt_clicked(); break;
        case 14: _t->CaptureOpen(); break;
        case 15: _t->slot_fpsTimer(); break;
        case 16: _t->slot_updateCurrentTime(); break;
        case 17: _t->Subclient_Hanlder(); break;
        case 18: _t->DataRecvParse((*reinterpret_cast< QMQTT::Message(*)>(_a[1]))); break;
        case 19: _t->on_mqtt_transfer_bt_clicked(); break;
        case 20: _t->onThumbnailGenerated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMQTT::Message >(); break;
            }
            break;
        }
    }
}

const QMetaObject menu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_menu.data,
      qt_meta_data_menu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *menu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_menu.stringdata))
        return static_cast<void*>(const_cast< menu*>(this));
    return QWidget::qt_metacast(_clname);
}

int menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
