//
// Created by cybik on 22-03-06.
//

#ifndef QAGL_WBASE_H
#define QAGL_WBASE_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class widget_baseline; }
QT_END_NAMESPACE

class widget_baseline : public QWidget {
Q_OBJECT

public:
    explicit widget_baseline(QWidget *parent = nullptr);
    void retranslate();

    ~widget_baseline() override;

    Ui::widget_baseline *ui;
};


#endif //QAGL_TEST_H
