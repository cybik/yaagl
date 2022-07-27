//
// Created by cybik on 22-07-24.
//

#include "SettingsCheckbox.h"

SettingsCheckbox::SettingsCheckbox(const QString& name) : SettingsControl(name){
    _control = std::make_shared<Nedrysoft::Ribbon::RibbonCheckBox>();
    _control->setText(name);
    finalize();
}

void SettingsCheckbox::addToLayout() {
    _formLayout->addRow(_control.get());
}

QLayout* SettingsCheckbox::getLayout() {
    return _layout->layout();
}
