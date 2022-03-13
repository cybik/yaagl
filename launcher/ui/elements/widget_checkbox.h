//
// Created by cybik on 22-03-06.
//

#ifndef QAGL_WCBOX_H
#define QAGL_WCBOX_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class widget_checkbox; }
QT_END_NAMESPACE

class widget_checkbox : public QWidget {
Q_OBJECT

public:
    explicit widget_checkbox(QWidget *parent = nullptr);
    void retranslate();

    ~widget_checkbox() override;

    Ui::widget_checkbox *ui;
};


#endif //QAGL_TEST_H
