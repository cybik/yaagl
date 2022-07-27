//
// Created by cybik on 22-07-24.
//

#include "SettingsButton.h"

SettingsButton::SettingsButton(const QString& name) : SettingsControl(name){
    _control = std::make_shared<Nedrysoft::Ribbon::RibbonButton>();
    _control->setText(name);
    finalize();
}

void SettingsButton::addToLayout() {
    _formLayout->addRow(_control.get());
}

QLayout* SettingsButton::getLayout() {
    return _layout->layout();
}
