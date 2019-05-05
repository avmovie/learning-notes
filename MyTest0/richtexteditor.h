#ifndef RICHTEXTEDITOR_H
#define RICHTEXTEDITOR_H

#include <QWidget>
#include <QTextEdit>
#include <QFontComboBox>

class RichTextEditor : public QWidget
{
    Q_OBJECT
public:
    explicit RichTextEditor(QWidget *parent = nullptr,QString content = "");
    QTextEdit *textedit;//文本编辑

private:
    QAction *action_new_page;//新页
    QAction *action_undo;//撤销
    QAction *action_redo;//恢复
    QAction *action_remove_format;//格式刷
    QFontComboBox *fontcombobox_font;//字体
    QComboBox *combobox_font_size;//字体大小
    QAction *action_background_color;//背景颜色
    QAction *action_text_color;//文字颜色
    QAction *action_cut;//剪切
    QAction *action_copy;//复制
    QAction *action_paste;//粘贴
    QAction *action_bold;//加粗
    QAction *action_italic;//倾斜
    QAction *action_underline;//下划线
    QAction *action_strike_trought;//删除线
    QAction *action_superscript;//上标
    QAction *action_subscript;//下标
    QAction *action_align_left;//左对齐
    QAction *action_align_center;//居中对齐
    QAction *action_align_right;//右对齐
    QAction *action_align_justify;//两端对齐
    QAction *action_insert_image;//插入图片
    void merge_format(const QTextCharFormat &format);
    void paintEvent(QPaintEvent *event);

private slots:
    void slot_new_page();
    void slot_remove_format();
    void slot_font(const QString &f);
    void slot_font_size(const QString &p);
    void slot_background_color();
    void slot_text_color();
    void currentCharFormatChanged(const QTextCharFormat &format);
    void slot_bold();
    void slot_italic();
    void slot_underline();
    void slot_strike_trought();
    void slot_superscript();
    void slot_subscript();
    void slot_align(QAction *a);
    void cursorPositionChanged();
    void slot_insert_image();
};

#endif // RICHTEXTEDITOR_H
