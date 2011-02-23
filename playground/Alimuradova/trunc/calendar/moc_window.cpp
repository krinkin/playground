/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created: Sun Jul 5 17:43:59 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "window.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Window[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      21,    7,    7,    7, 0x08,
      39,   33,    7,    7, 0x08,
      58,   33,    7,    7, 0x08,
      79,   33,    7,    7, 0x08,
     105,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Window[] = {
    "Window\0\0openDialog()\0printFile()\0index\0"
    "localeChanged(int)\0firstDayChanged(int)\0"
    "selectionModeChanged(int)\0"
    "selectedDateChanged()\0"
};

const QMetaObject Window::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Window,
      qt_meta_data_Window, 0 }
};

const QMetaObject *Window::metaObject() const
{
    return &staticMetaObject;
}

void *Window::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Window))
        return static_cast<void*>(const_cast< Window*>(this));
    return QWidget::qt_metacast(_clname);
}

int Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openDialog(); break;
        case 1: printFile(); break;
        case 2: localeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: firstDayChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: selectionModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: selectedDateChanged(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
