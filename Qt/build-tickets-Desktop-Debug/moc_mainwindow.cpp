/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tickets/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[310];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 11), // "checkPerson"
QT_MOC_LITERAL(4, 46, 10), // "uncheckAll"
QT_MOC_LITERAL(5, 57, 23), // "on_actionQuit_triggered"
QT_MOC_LITERAL(6, 81, 19), // "on_chkAdult_clicked"
QT_MOC_LITERAL(7, 101, 23), // "on_chkPensioner_clicked"
QT_MOC_LITERAL(8, 125, 9), // "newPerson"
QT_MOC_LITERAL(9, 135, 7), // "Person*"
QT_MOC_LITERAL(10, 143, 19), // "on_chkMinor_clicked"
QT_MOC_LITERAL(11, 163, 18), // "on_btnBook_clicked"
QT_MOC_LITERAL(12, 182, 11), // "repaintView"
QT_MOC_LITERAL(13, 194, 17), // "on_btnAdd_clicked"
QT_MOC_LITERAL(14, 212, 5), // "debug"
QT_MOC_LITERAL(15, 218, 26), // "on_tableWidget_cellPressed"
QT_MOC_LITERAL(16, 245, 3), // "row"
QT_MOC_LITERAL(17, 249, 6), // "column"
QT_MOC_LITERAL(18, 256, 28), // "on_tableWidget_doubleClicked"
QT_MOC_LITERAL(19, 285, 5), // "index"
QT_MOC_LITERAL(20, 291, 18) // "on_btnUndo_clicked"

    },
    "MainWindow\0on_pushButton_clicked\0\0"
    "checkPerson\0uncheckAll\0on_actionQuit_triggered\0"
    "on_chkAdult_clicked\0on_chkPensioner_clicked\0"
    "newPerson\0Person*\0on_chkMinor_clicked\0"
    "on_btnBook_clicked\0repaintView\0"
    "on_btnAdd_clicked\0debug\0"
    "on_tableWidget_cellPressed\0row\0column\0"
    "on_tableWidget_doubleClicked\0index\0"
    "on_btnUndo_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
      10,    0,   96,    2, 0x08 /* Private */,
      11,    0,   97,    2, 0x08 /* Private */,
      12,    0,   98,    2, 0x08 /* Private */,
      13,    0,   99,    2, 0x08 /* Private */,
      14,    0,  100,    2, 0x08 /* Private */,
      15,    2,  101,    2, 0x08 /* Private */,
      18,    1,  106,    2, 0x08 /* Private */,
      20,    0,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   17,
    QMetaType::Void, QMetaType::QModelIndex,   19,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: { bool _r = _t->checkPerson();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: _t->uncheckAll(); break;
        case 3: _t->on_actionQuit_triggered(); break;
        case 4: _t->on_chkAdult_clicked(); break;
        case 5: _t->on_chkPensioner_clicked(); break;
        case 6: { Person* _r = _t->newPerson();
            if (_a[0]) *reinterpret_cast< Person**>(_a[0]) = _r; }  break;
        case 7: _t->on_chkMinor_clicked(); break;
        case 8: _t->on_btnBook_clicked(); break;
        case 9: _t->repaintView(); break;
        case 10: _t->on_btnAdd_clicked(); break;
        case 11: _t->debug(); break;
        case 12: _t->on_tableWidget_cellPressed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->on_tableWidget_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 14: _t->on_btnUndo_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
