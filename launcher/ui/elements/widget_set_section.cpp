//
// Created by cybik on 22-03-06.
//

// You may need to build the project (run Qt uic code generator) to get "ui_test.h" resolved

#include "widget_set_section.h"
#include "ui_widget_set_section.h"


widget_set_section::widget_set_section(QWidget *parent) :
        QWidget(parent), ui(new Ui::widget_set_section) {
    ui->setupUi(this);
}

void widget_set_section::retranslate() {
    ui->retranslateUi(this);
}

widget_set_section::~widget_set_section() {
    delete ui;
}

