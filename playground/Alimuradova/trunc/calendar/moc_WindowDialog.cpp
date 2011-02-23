/****************************************************************************
** Meta object code from reading C++ file 'WindowDialog.h'
**
** Created: Sun Jul 5 17:44:02 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "WindowDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WindowDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WindowDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      31,   13,   23,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_WindowDialog[] = {
    "WindowDialog\0\0verify()\0QString\0"
    "senderEvent()\0"
};

const QMetaObject WindowDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_WindowDialog,
      qt_meta_data_WindowDialog, 0 }
};

const QMetaObject *WindowDialog::metaObject() const
{
    return &staticMetaObject;
}

void *WindowDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WindowDialog))
        return static_cast<void*>(const_cast< WindowDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int WindowDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: verify(); break;
        case 1: { QString _r = senderEvent();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
