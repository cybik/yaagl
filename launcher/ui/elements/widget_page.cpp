//
// Created by cybik on 22-03-06.
//

// You may need to build the project (run Qt uic code generator) to get "ui_test.h" resolved

#include "widget_page.h"
#include "ui_widget_page.h"


widget_page::widget_page(QWidget *parent) :
        QWidget(parent), ui(new Ui::widget_page) {
    ui->setupUi(this);
}

void widget_page::retranslate() {
    ui->retranslateUi(this);
}

widget_page::~widget_page() {
    delete ui;
}

