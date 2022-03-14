//
// Created by cybik on 22-03-06.
//

#ifndef QAGL_WSETSECT_H
#define QAGL_WSETSECT_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class widget_set_section; }
QT_END_NAMESPACE

class widget_set_section : public QWidget {
Q_OBJECT

public:
    explicit widget_set_section(QWidget *parent = nullptr);
    void retranslate();

    ~widget_set_section() override;

    Ui::widget_set_section *ui;
};


#endif //QAGL_TEST_H
