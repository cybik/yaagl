//
// Created by cybik on 22-03-06.
//

#ifndef QAGL_WSEC_H
#define QAGL_WSEC_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class widget_section; }
QT_END_NAMESPACE

class widget_section : public QWidget {
Q_OBJECT

public:
    explicit widget_section(QWidget *parent = nullptr);
    void retranslate();

    ~widget_section() override;

    Ui::widget_section *ui;
};


#endif //QAGL_TEST_H
