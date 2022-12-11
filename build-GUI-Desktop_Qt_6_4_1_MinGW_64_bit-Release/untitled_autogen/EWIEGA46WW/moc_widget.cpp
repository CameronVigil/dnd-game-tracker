/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../GUI/widget.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_Widget_t {
    uint offsetsAndSizes[32];
    char stringdata0[7];
    char stringdata1[31];
    char stringdata2[1];
    char stringdata3[32];
    char stringdata4[8];
    char stringdata5[31];
    char stringdata6[33];
    char stringdata7[31];
    char stringdata8[32];
    char stringdata9[34];
    char stringdata10[30];
    char stringdata11[29];
    char stringdata12[30];
    char stringdata13[26];
    char stringdata14[22];
    char stringdata15[27];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Widget_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
        QT_MOC_LITERAL(0, 6),  // "Widget"
        QT_MOC_LITERAL(7, 30),  // "on_AbilityCheck_Result_clicked"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 31),  // "on_TaskDifficulty_vEasy_toggled"
        QT_MOC_LITERAL(71, 7),  // "checked"
        QT_MOC_LITERAL(79, 30),  // "on_TaskDifficulty_Easy_toggled"
        QT_MOC_LITERAL(110, 32),  // "on_TaskDifficulty_Medium_toggled"
        QT_MOC_LITERAL(143, 30),  // "on_TaskDifficulty_Hard_toggled"
        QT_MOC_LITERAL(174, 31),  // "on_TaskDifficulty_vHard_toggled"
        QT_MOC_LITERAL(206, 33),  // "on_TaskDifficulty_Extreme_tog..."
        QT_MOC_LITERAL(240, 29),  // "on_Advantage_positive_toggled"
        QT_MOC_LITERAL(270, 28),  // "on_Advantage_neutral_toggled"
        QT_MOC_LITERAL(299, 29),  // "on_Advantage_negative_toggled"
        QT_MOC_LITERAL(329, 25),  // "on_Contest_Single_toggled"
        QT_MOC_LITERAL(355, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(377, 26)   // "on_addPlayerButton_clicked"
    },
    "Widget",
    "on_AbilityCheck_Result_clicked",
    "",
    "on_TaskDifficulty_vEasy_toggled",
    "checked",
    "on_TaskDifficulty_Easy_toggled",
    "on_TaskDifficulty_Medium_toggled",
    "on_TaskDifficulty_Hard_toggled",
    "on_TaskDifficulty_vHard_toggled",
    "on_TaskDifficulty_Extreme_toggled",
    "on_Advantage_positive_toggled",
    "on_Advantage_neutral_toggled",
    "on_Advantage_negative_toggled",
    "on_Contest_Single_toggled",
    "on_pushButton_clicked",
    "on_addPlayerButton_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Widget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x08,    1 /* Private */,
       3,    1,   93,    2, 0x08,    2 /* Private */,
       5,    1,   96,    2, 0x08,    4 /* Private */,
       6,    1,   99,    2, 0x08,    6 /* Private */,
       7,    1,  102,    2, 0x08,    8 /* Private */,
       8,    1,  105,    2, 0x08,   10 /* Private */,
       9,    1,  108,    2, 0x08,   12 /* Private */,
      10,    1,  111,    2, 0x08,   14 /* Private */,
      11,    1,  114,    2, 0x08,   16 /* Private */,
      12,    1,  117,    2, 0x08,   18 /* Private */,
      13,    1,  120,    2, 0x08,   20 /* Private */,
      14,    0,  123,    2, 0x08,   22 /* Private */,
      15,    0,  124,    2, 0x08,   23 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.offsetsAndSizes,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Widget_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Widget, std::true_type>,
        // method 'on_AbilityCheck_Result_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_TaskDifficulty_vEasy_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_TaskDifficulty_Easy_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_TaskDifficulty_Medium_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_TaskDifficulty_Hard_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_TaskDifficulty_vHard_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_TaskDifficulty_Extreme_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_Advantage_positive_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_Advantage_neutral_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_Advantage_negative_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_Contest_Single_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addPlayerButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_AbilityCheck_Result_clicked(); break;
        case 1: _t->on_TaskDifficulty_vEasy_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->on_TaskDifficulty_Easy_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->on_TaskDifficulty_Medium_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->on_TaskDifficulty_Hard_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->on_TaskDifficulty_vHard_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->on_TaskDifficulty_Extreme_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->on_Advantage_positive_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->on_Advantage_neutral_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->on_Advantage_negative_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->on_Contest_Single_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->on_pushButton_clicked(); break;
        case 12: _t->on_addPlayerButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
