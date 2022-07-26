//
// Created by cybik on 22-07-24.
//

#include "SettingsLabel.h"

SettingsLabel::SettingsLabel(std::string name) : SettingsControl(name){
    _control = std::make_shared<QLabel>();
    _control->setText(name.c_str());

    _formLayout->addRow(_control.get());

    _layout->addLayout(_formLayout->layout(), 0, 0);
}

QLayout* SettingsLabel::getLayout() {
    return _layout->layout();
}