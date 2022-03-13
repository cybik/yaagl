//
// Created by cybik on 22-03-06.
//

#ifndef QAGL_WCOMB_H
#define QAGL_WCOMB_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class widget_combo; }
QT_END_NAMESPACE

class widget_combo : public QWidget {
Q_OBJECT

public:
    explicit widget_combo(QWidget *parent = nullptr);
    void retranslate();

    ~widget_combo() override;

    Ui::widget_combo *ui;
};


#endif //QAGL_TEST_H
