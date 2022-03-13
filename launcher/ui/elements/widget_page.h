//
// Created by cybik on 22-03-06.
//

#ifndef QAGL_WPAGE_H
#define QAGL_WPAGE_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class widget_page; }
QT_END_NAMESPACE

class widget_page : public QWidget {
Q_OBJECT

public:
    explicit widget_page(QWidget *parent = nullptr);
    void retranslate();

    ~widget_page() override;

    Ui::widget_page *ui;
};


#endif //QAGL_TEST_H
