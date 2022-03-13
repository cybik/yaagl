//
// Created by cybik on 22-03-06.
//

// You may need to build the project (run Qt uic code generator) to get "ui_test.h" resolved

#include "widget_section.h"
#include "ui_widget_section.h"


widget_section::widget_section(QWidget *parent) :
        QWidget(parent), ui(new Ui::widget_section) {
    ui->setupUi(this);
}

void widget_section::retranslate() {
    ui->retranslateUi(this);
}

widget_section::~widget_section() {
    delete ui;
}

