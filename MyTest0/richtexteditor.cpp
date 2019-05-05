#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "richtexteditor.h"
#include <QToolBar>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QApplication>
#include <QPainter>

RichTextEditor::RichTextEditor(QWidget *parent,QString content) : QWidget(parent)
{
    setFixedSize(527,350);
    textedit = new QTextEdit(this);
    textedit->document()->setHtml(content);
    QToolBar *tb1 = new QToolBar(tr("actions1"),this);
    action_new_page = new QAction(QIcon::fromTheme("new page", QIcon(":/textedit/new_page.png")), tr("&新页"), this);
    tb1->addAction(action_new_page);
    tb1->addSeparator();
    action_undo = new QAction(QIcon::fromTheme("undo", QIcon(":/textedit/undo.png")), tr("&撤销"), this);
    action_redo = new QAction(QIcon::fromTheme("redo", QIcon(":/textedit/redo.png")), tr("&恢复"), this);
    action_remove_format = new QAction(QIcon::fromTheme("remove format", QIcon(":/textedit/remove_format.png")), tr("&格式刷"), this);
    tb1->addAction(action_undo);
    tb1->addAction(action_redo);
    tb1->addAction(action_remove_format);
    tb1->addSeparator();
    fontcombobox_font = new QFontComboBox(this);
    fontcombobox_font->setFontFilters(QFontComboBox::ScalableFonts);
    combobox_font_size = new QComboBox(this);
    const QList<int> standardSizes = QFontDatabase::standardSizes();
    foreach(int size,standardSizes)
        combobox_font_size->addItem(QString::number(size));
    combobox_font_size->setCurrentIndex(standardSizes.indexOf(QApplication::font().pointSize()));
    action_background_color = new QAction(QIcon::fromTheme("background color", QIcon(":/textedit/background_color.png")), tr("&背景颜色"), this);
    action_text_color = new QAction(QIcon::fromTheme("text color", QIcon(":/textedit/text_color.png")), tr("&文字颜色"), this);
    tb1->addWidget(fontcombobox_font);
    tb1->addWidget(combobox_font_size);
    tb1->addAction(action_background_color);
    tb1->addAction(action_text_color);
    tb1->addSeparator();
    action_cut = new QAction(QIcon::fromTheme("cut", QIcon(":/textedit/cut.png")), tr("&剪切"), this);
    action_copy = new QAction(QIcon::fromTheme("copy", QIcon(":/textedit/copy.png")), tr("&复制"), this);
    action_paste = new QAction(QIcon::fromTheme("paste", QIcon(":/textedit/paste.png")), tr("&粘贴"), this);
    tb1->addAction(action_cut);
    tb1->addAction(action_copy);
    tb1->addAction(action_paste);
    QToolBar *tb2 = new QToolBar(tr("actions2"),this);
    action_bold = new QAction(QIcon::fromTheme("bold", QIcon(":/textedit/bold.png")), tr("&加粗"), this);
    action_italic = new QAction(QIcon::fromTheme("italic", QIcon(":/textedit/italic.png")), tr("&倾斜"), this);
    action_underline = new QAction(QIcon::fromTheme("underline", QIcon(":/textedit/underline.png")), tr("&下划线"), this);
    action_strike_trought = new QAction(QIcon::fromTheme("strike_trought", QIcon(":/textedit/strike_trought.png")), tr("&删除线"), this);
    action_superscript = new QAction(QIcon::fromTheme("superscript", QIcon(":/textedit/superscript.png")), tr("&上标"), this);
    action_subscript = new QAction(QIcon::fromTheme("subscript", QIcon(":/textedit/subscript.png")), tr("&下标"), this);
    tb2->addAction(action_bold);
    tb2->addAction(action_italic);
    tb2->addAction(action_underline);
    tb2->addAction(action_strike_trought);
    tb2->addAction(action_superscript);
    tb2->addAction(action_subscript);
    tb2->addSeparator();
    action_align_left = new QAction(QIcon::fromTheme("align left", QIcon(":/textedit/align_left.png")), tr("&左对齐"), this);
    action_align_center = new QAction(QIcon::fromTheme("align center", QIcon(":/textedit/align_center.png")), tr("&居中对齐"), this);
    action_align_right = new QAction(QIcon::fromTheme("align right", QIcon(":/textedit/align_right.png")), tr("&右对齐"), this);
    action_align_justify = new QAction(QIcon::fromTheme("align justify", QIcon(":/textedit/align_justify.png")), tr("&两端对齐"), this);
    QActionGroup *actiongroup_align = new QActionGroup(this);
    actiongroup_align->addAction(action_align_left);
    actiongroup_align->addAction(action_align_center);
    actiongroup_align->addAction(action_align_right);
    actiongroup_align->addAction(action_align_justify);
    tb2->addActions(actiongroup_align->actions());
    tb2->addSeparator();
    action_insert_image = new QAction(QIcon::fromTheme("insert image", QIcon(":/textedit/insert_image.png")), tr("&插入图片"), this);
    tb2->addAction(action_insert_image);
    QVBoxLayout *vl = new QVBoxLayout(this);
    vl->setSpacing(0);
    vl->addWidget(tb1);
    vl->addWidget(tb2);
    vl->addWidget(textedit);
    setLayout(vl);

    action_undo->setEnabled(false);
    action_redo->setEnabled(false);
    action_copy->setEnabled(false);
    action_bold->setCheckable(true);
    action_italic->setCheckable(true);
    action_underline->setCheckable(true);
    action_strike_trought->setCheckable(true);
    action_superscript->setCheckable(true);
    action_subscript->setCheckable(true);
    action_align_left->setCheckable(true);
    action_align_center->setCheckable(true);
    action_align_right->setCheckable(true);
    action_align_justify->setCheckable(true);

    connect(action_new_page,SIGNAL(triggered(bool)),this,SLOT(slot_new_page()));
    connect(textedit->document(),SIGNAL(undoAvailable(bool)),action_undo,SLOT(setEnabled(bool)));
    connect(action_undo,SIGNAL(triggered(bool)),textedit,SLOT(undo()));
    connect(textedit->document(),SIGNAL(redoAvailable(bool)),action_redo,SLOT(setEnabled(bool)));
    connect(action_redo,SIGNAL(triggered(bool)),textedit,SLOT(redo()));
    connect(action_remove_format,SIGNAL(triggered(bool)),this,SLOT(slot_remove_format()));
    connect(fontcombobox_font,SIGNAL(activated(QString)),this,SLOT(slot_font(QString)));
    connect(combobox_font_size,SIGNAL(activated(QString)),this,SLOT(slot_font_size(QString)));
    connect(action_background_color,SIGNAL(triggered(bool)),this,SLOT(slot_background_color()));
    connect(action_text_color,SIGNAL(triggered(bool)),this,SLOT(slot_text_color()));
    connect(action_cut,SIGNAL(triggered(bool)),textedit,SLOT(cut()));
    connect(textedit,SIGNAL(copyAvailable(bool)),action_copy,SLOT(setEnabled(bool)));
    connect(action_copy,SIGNAL(triggered(bool)),textedit,SLOT(copy()));
    connect(action_paste,SIGNAL(triggered(bool)),textedit,SLOT(paste()));
    connect(textedit,SIGNAL(currentCharFormatChanged(QTextCharFormat)),this,SLOT(currentCharFormatChanged(QTextCharFormat)));
    connect(action_bold,SIGNAL(triggered(bool)),this,SLOT(slot_bold()));
    connect(action_italic,SIGNAL(triggered(bool)),this,SLOT(slot_italic()));
    connect(action_underline,SIGNAL(triggered(bool)),this,SLOT(slot_underline()));
    connect(action_strike_trought,SIGNAL(triggered(bool)),this,SLOT(slot_strike_trought()));
    connect(action_superscript,SIGNAL(triggered(bool)),this,SLOT(slot_superscript()));
    connect(action_subscript,SIGNAL(triggered(bool)),this,SLOT(slot_subscript()));
    connect(actiongroup_align,SIGNAL(triggered(QAction*)),this,SLOT(slot_align(QAction*)));
    connect(textedit,SIGNAL(cursorPositionChanged()),this,SLOT(cursorPositionChanged()));
    connect(action_insert_image,SIGNAL(triggered(bool)),this,SLOT(slot_insert_image()));
}

void RichTextEditor::slot_new_page()
{
    if(textedit->document()->isModified())
        if(QMessageBox::Yes == QMessageBox::question(this,tr("提示"),tr("确定要清空文本？"),QMessageBox::Yes | QMessageBox::No))
            textedit->clear();
}

void RichTextEditor::slot_remove_format()
{
    QTextCharFormat fmt;
    fmt.setFontFamily(tr("宋体"));
    fmt.setFontPointSize(9);
    fmt.setBackground(QColor(255,255,255));
    fmt.setForeground(QColor(0,0,0));
    fmt.setFontWeight(QFont::Normal);
    fmt.setFontItalic(false);
    fmt.setFontUnderline(false);
    fmt.setFontStrikeOut(false);
    fmt.setVerticalAlignment(QTextCharFormat::AlignNormal);
    textedit->selectAll();
    textedit->setAlignment(Qt::AlignLeft);
    merge_format(fmt);
}

void RichTextEditor::merge_format(const QTextCharFormat &format)//合并格式
{
    QTextCursor cursor = textedit->textCursor();
    cursor.mergeCharFormat(format);
    textedit->mergeCurrentCharFormat(format);
}

void RichTextEditor::slot_font(const QString &f)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(f);
    merge_format(fmt);
}

void RichTextEditor::slot_font_size(const QString &p)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(p.toFloat());
    merge_format(fmt);
}

void RichTextEditor::slot_background_color()
{
    QColor col = QColorDialog::getColor(textedit->backgroundRole(), this);
    if (!col.isValid())
        return;
    QTextCharFormat fmt;
    fmt.setBackground(col);
    merge_format(fmt);
}

void RichTextEditor::slot_text_color()
{
    QColor col = QColorDialog::getColor(textedit->textColor(), this);
    if (!col.isValid())
        return;
    QTextCharFormat fmt;
    fmt.setForeground(col);
    merge_format(fmt);
}

void RichTextEditor::slot_bold()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(action_bold->isChecked() ? QFont::Bold : QFont::Normal);
    merge_format(fmt);
}

void RichTextEditor::slot_italic()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(action_italic->isChecked());
    merge_format(fmt);
}

void RichTextEditor::currentCharFormatChanged(const QTextCharFormat &format)//当前字符格式已更改
{
    QFont f = format.font();
    action_bold->setChecked(f.bold());
    action_italic->setChecked(f.italic());
    action_underline->setChecked(f.underline());
    action_strike_trought->setChecked(f.strikeOut());
    action_superscript->setChecked(format.verticalAlignment() == QTextCharFormat::AlignSuperScript ? true : false);
    action_subscript->setChecked(format.verticalAlignment() == QTextCharFormat::AlignSubScript ? true : false);
}

void RichTextEditor::slot_underline()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(action_underline->isChecked());
    merge_format(fmt);
}

void RichTextEditor::slot_strike_trought()
{
    QTextCharFormat fmt;
    fmt.setFontStrikeOut(action_strike_trought->isChecked());
    merge_format(fmt);
}

void RichTextEditor::slot_superscript()
{
    QTextCharFormat fmt;
    fmt.setVerticalAlignment(action_superscript->isChecked() ? QTextCharFormat::AlignSuperScript : QTextCharFormat::AlignNormal);
    merge_format(fmt);
}

void RichTextEditor::slot_subscript()
{
    QTextCharFormat fmt;
    fmt.setVerticalAlignment(action_subscript->isChecked() ? QTextCharFormat::AlignSubScript : QTextCharFormat::AlignNormal);
    merge_format(fmt);
}

void RichTextEditor::slot_align(QAction *a)
{
    if (a == action_align_left)
        textedit->setAlignment(Qt::AlignLeft);
    else if (a == action_align_center)
        textedit->setAlignment(Qt::AlignHCenter);
    else if (a == action_align_right)
        textedit->setAlignment(Qt::AlignRight);
    else if (a == action_align_justify)
        textedit->setAlignment(Qt::AlignJustify);
}

void RichTextEditor::cursorPositionChanged()//光标位置改变
{
    if(textedit->alignment() == Qt::AlignLeft)
        action_align_left->setChecked(true);
    else if(textedit->alignment() == Qt::AlignHCenter)
        action_align_center->setChecked(true);
    else if(textedit->alignment() == Qt::AlignRight)
        action_align_right->setChecked(true);
    else if(textedit->alignment() == Qt::AlignJustify)
        action_align_justify->setChecked(true);
}

void RichTextEditor::slot_insert_image()
{
    QString file = QFileDialog::getOpenFileName(this, tr("选择一张图片"), ".", tr("Images(*.bmp *.jpg *.jpeg *.png)"));
    QImage image(file);
    textedit->document()->addResource(QTextDocument::ImageResource,QUrl(file),QVariant(image));
    QTextImageFormat tif;
    tif.setWidth(image.width());
    tif.setHeight(image.height());
    tif.setName(file);
    textedit->textCursor().insertImage(tif);
}

void RichTextEditor::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setPen(QColor(139,139,139));
    p.drawLine(0,0,width() - 1,0);
    p.drawLine(0,0,0,height() - 1);
    p.drawLine(width() - 1,0,width() - 1,height() - 1);
    p.drawLine(0,height() - 1,width() - 1,height() - 1);
}
