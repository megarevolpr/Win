/****************************************************************************
** Meta object code from reading C++ file 'win.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../win.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'win.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MEGAWin_t {
    QByteArrayData data[14];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MEGAWin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MEGAWin_t qt_meta_stringdata_MEGAWin = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MEGAWin"
QT_MOC_LITERAL(1, 8, 10), // "onTimerOut"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 13), // "My_menuAction"
QT_MOC_LITERAL(4, 34, 5), // "Index"
QT_MOC_LITERAL(5, 40, 11), // "WordingMode"
QT_MOC_LITERAL(6, 52, 6), // "Return"
QT_MOC_LITERAL(7, 59, 21), // "on_UI_MenuBtn_clicked"
QT_MOC_LITERAL(8, 81, 26), // "on_Bypass_Batt_btn_clicked"
QT_MOC_LITERAL(9, 108, 29), // "on_Bypass_Running_btn_clicked"
QT_MOC_LITERAL(10, 138, 26), // "on_Bypass_Grid_btn_clicked"
QT_MOC_LITERAL(11, 165, 26), // "on_Bypass_Load_Btn_clicked"
QT_MOC_LITERAL(12, 192, 21), // "on_SetNext_bt_clicked"
QT_MOC_LITERAL(13, 214, 25) // "on_SetPrevious_bt_clicked"

    },
    "MEGAWin\0onTimerOut\0\0My_menuAction\0"
    "Index\0WordingMode\0Return\0on_UI_MenuBtn_clicked\0"
    "on_Bypass_Batt_btn_clicked\0"
    "on_Bypass_Running_btn_clicked\0"
    "on_Bypass_Grid_btn_clicked\0"
    "on_Bypass_Load_Btn_clicked\0"
    "on_SetNext_bt_clicked\0on_SetPrevious_bt_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MEGAWin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    1,   70,    2, 0x08 /* Private */,
       5,    1,   73,    2, 0x08 /* Private */,
       6,    1,   76,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MEGAWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MEGAWin *_t = static_cast<MEGAWin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTimerOut(); break;
        case 1: _t->My_menuAction((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->WordingMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->Return((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_UI_MenuBtn_clicked(); break;
        case 5: _t->on_Bypass_Batt_btn_clicked(); break;
        case 6: _t->on_Bypass_Running_btn_clicked(); break;
        case 7: _t->on_Bypass_Grid_btn_clicked(); break;
        case 8: _t->on_Bypass_Load_Btn_clicked(); break;
        case 9: _t->on_SetNext_bt_clicked(); break;
        case 10: _t->on_SetPrevious_bt_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MEGAWin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MEGAWin.data,
      qt_meta_data_MEGAWin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MEGAWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MEGAWin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MEGAWin.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MEGAWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
