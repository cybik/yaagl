//
// Created by cybik on 22-03-06.
//

// You may need to build the project (run Qt uic code generator) to get "ui_test.h" resolved

#include "widget_baseline.h"
#include "ui_widget_baseline.h"


widget_baseline::widget_baseline(QWidget *parent) :
        QWidget(parent), ui(new Ui::widget_baseline) {
    ui->setupUi(this);
}

void widget_baseline::retranslate() {
    ui->retranslateUi(this);
}

widget_baseline::~widget_baseline() {
    delete ui;
}

