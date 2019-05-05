/****************************************************************************
** Meta object code from reading C++ file 'richtexteditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../richtexteditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'richtexteditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RichTextEditor_t {
    QByteArrayData data[24];
    char stringdata0[315];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RichTextEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RichTextEditor_t qt_meta_stringdata_RichTextEditor = {
    {
QT_MOC_LITERAL(0, 0, 14), // "RichTextEditor"
QT_MOC_LITERAL(1, 15, 13), // "slot_new_page"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 18), // "slot_remove_format"
QT_MOC_LITERAL(4, 49, 9), // "slot_font"
QT_MOC_LITERAL(5, 59, 1), // "f"
QT_MOC_LITERAL(6, 61, 14), // "slot_font_size"
QT_MOC_LITERAL(7, 76, 1), // "p"
QT_MOC_LITERAL(8, 78, 21), // "slot_background_color"
QT_MOC_LITERAL(9, 100, 15), // "slot_text_color"
QT_MOC_LITERAL(10, 116, 24), // "currentCharFormatChanged"
QT_MOC_LITERAL(11, 141, 15), // "QTextCharFormat"
QT_MOC_LITERAL(12, 157, 6), // "format"
QT_MOC_LITERAL(13, 164, 9), // "slot_bold"
QT_MOC_LITERAL(14, 174, 11), // "slot_italic"
QT_MOC_LITERAL(15, 186, 14), // "slot_underline"
QT_MOC_LITERAL(16, 201, 19), // "slot_strike_trought"
QT_MOC_LITERAL(17, 221, 16), // "slot_superscript"
QT_MOC_LITERAL(18, 238, 14), // "slot_subscript"
QT_MOC_LITERAL(19, 253, 10), // "slot_align"
QT_MOC_LITERAL(20, 264, 8), // "QAction*"
QT_MOC_LITERAL(21, 273, 1), // "a"
QT_MOC_LITERAL(22, 275, 21), // "cursorPositionChanged"
QT_MOC_LITERAL(23, 297, 17) // "slot_insert_image"

    },
    "RichTextEditor\0slot_new_page\0\0"
    "slot_remove_format\0slot_font\0f\0"
    "slot_font_size\0p\0slot_background_color\0"
    "slot_text_color\0currentCharFormatChanged\0"
    "QTextCharFormat\0format\0slot_bold\0"
    "slot_italic\0slot_underline\0"
    "slot_strike_trought\0slot_superscript\0"
    "slot_subscript\0slot_align\0QAction*\0a\0"
    "cursorPositionChanged\0slot_insert_image"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RichTextEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    1,   96,    2, 0x08 /* Private */,
       6,    1,   99,    2, 0x08 /* Private */,
       8,    0,  102,    2, 0x08 /* Private */,
       9,    0,  103,    2, 0x08 /* Private */,
      10,    1,  104,    2, 0x08 /* Private */,
      13,    0,  107,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    0,  109,    2, 0x08 /* Private */,
      16,    0,  110,    2, 0x08 /* Private */,
      17,    0,  111,    2, 0x08 /* Private */,
      18,    0,  112,    2, 0x08 /* Private */,
      19,    1,  113,    2, 0x08 /* Private */,
      22,    0,  116,    2, 0x08 /* Private */,
      23,    0,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RichTextEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RichTextEditor *_t = static_cast<RichTextEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_new_page(); break;
        case 1: _t->slot_remove_format(); break;
        case 2: _t->slot_font((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->slot_font_size((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->slot_background_color(); break;
        case 5: _t->slot_text_color(); break;
        case 6: _t->currentCharFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 7: _t->slot_bold(); break;
        case 8: _t->slot_italic(); break;
        case 9: _t->slot_underline(); break;
        case 10: _t->slot_strike_trought(); break;
        case 11: _t->slot_superscript(); break;
        case 12: _t->slot_subscript(); break;
        case 13: _t->slot_align((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 14: _t->cursorPositionChanged(); break;
        case 15: _t->slot_insert_image(); break;
        default: ;
        }
    }
}

const QMetaObject RichTextEditor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RichTextEditor.data,
      qt_meta_data_RichTextEditor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RichTextEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RichTextEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RichTextEditor.stringdata0))
        return static_cast<void*>(const_cast< RichTextEditor*>(this));
    return QWidget::qt_metacast(_clname);
}

int RichTextEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
