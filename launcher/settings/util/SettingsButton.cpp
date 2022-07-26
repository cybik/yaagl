//
// Created by cybik on 22-07-24.
//

#include "SettingsButton.h"

SettingsButton::SettingsButton(std::string name) : SettingsControl(name){
    _control = std::make_shared<Nedrysoft::Ribbon::RibbonButton>();
    _control->setText(name.c_str());

    _formLayout->addRow(_control.get());

    _layout->addLayout(_formLayout->layout(), 0, 0);
}

QLayout* SettingsButton::getLayout() {
    return _layout->layout();
}
