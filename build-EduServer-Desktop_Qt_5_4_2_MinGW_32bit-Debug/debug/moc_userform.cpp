/****************************************************************************
** Meta object code from reading C++ file 'userform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EduServer/subwidgets/userform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserForm_t {
    QByteArrayData data[11];
    char stringdata[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserForm_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserForm_t qt_meta_stringdata_UserForm = {
    {
QT_MOC_LITERAL(0, 0, 8), // "UserForm"
QT_MOC_LITERAL(1, 9, 22), // "on_tableWidget_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "index"
QT_MOC_LITERAL(4, 39, 20), // "on_pb_search_clicked"
QT_MOC_LITERAL(5, 60, 35), // "on_cb_condition_currentIndexC..."
QT_MOC_LITERAL(6, 96, 20), // "on_pb_cancel_clicked"
QT_MOC_LITERAL(7, 117, 20), // "on_pb_modify_clicked"
QT_MOC_LITERAL(8, 138, 20), // "on_pb_delete_clicked"
QT_MOC_LITERAL(9, 159, 17), // "on_pb_add_clicked"
QT_MOC_LITERAL(10, 177, 18) // "on_pb_save_clicked"

    },
    "UserForm\0on_tableWidget_clicked\0\0index\0"
    "on_pb_search_clicked\0"
    "on_cb_condition_currentIndexChanged\0"
    "on_pb_cancel_clicked\0on_pb_modify_clicked\0"
    "on_pb_delete_clicked\0on_pb_add_clicked\0"
    "on_pb_save_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    0,   57,    2, 0x08 /* Private */,
       5,    1,   58,    2, 0x08 /* Private */,
       6,    0,   61,    2, 0x08 /* Private */,
       7,    0,   62,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UserForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserForm *_t = static_cast<UserForm *>(_o);
        switch (_id) {
        case 0: _t->on_tableWidget_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_pb_search_clicked(); break;
        case 2: _t->on_cb_condition_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pb_cancel_clicked(); break;
        case 4: _t->on_pb_modify_clicked(); break;
        case 5: _t->on_pb_delete_clicked(); break;
        case 6: _t->on_pb_add_clicked(); break;
        case 7: _t->on_pb_save_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject UserForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UserForm.data,
      qt_meta_data_UserForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UserForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UserForm.stringdata))
        return static_cast<void*>(const_cast< UserForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int UserForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
