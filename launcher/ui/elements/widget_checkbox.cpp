//
// Created by cybik on 22-03-06.
//

// You may need to build the project (run Qt uic code generator) to get "ui_test.h" resolved

#include "widget_checkbox.h"
#include "ui_widget_checkbox.h"


widget_checkbox::widget_checkbox(QWidget *parent) :
        QWidget(parent), ui(new Ui::widget_checkbox) {
    ui->setupUi(this);
}

void widget_checkbox::retranslate() {
    ui->retranslateUi(this);
}

widget_checkbox::~widget_checkbox() {
    delete ui;
}

