//
// Created by cybik on 22-03-06.
//

// You may need to build the project (run Qt uic code generator) to get "ui_test.h" resolved

#include "widget_combo.h"
#include "ui_widget_combo.h"


widget_combo::widget_combo(QWidget *parent) :
        QWidget(parent), ui(new Ui::widget_combo) {
    ui->setupUi(this);
}

void widget_combo::retranslate() {
    ui->retranslateUi(this);
}

widget_combo::~widget_combo() {
    delete ui;
}

