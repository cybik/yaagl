//
// Created by cybik on 22-07-24.
//

#include "SettingsCombo.h"

SettingsCombo::SettingsCombo(std::string name) : SettingsControl(name) {
    _control = std::make_shared<Nedrysoft::Ribbon::RibbonComboBox>();
    _control->setSizePolicy(QSizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum));

    _formLayout->addRow(name.c_str(), _control.get());

    _layout->addLayout(_formLayout->layout(), 0, 0);
}

void SettingsCombo::addChoices(int count, ...) {
    va_list valist;
    va_start(valist, count);
    for(int i = 0; i < count; i++) {
        addChoice(va_arg(valist, const char*));
    }
    va_end(valist);
}

void SettingsCombo::addChoice(const char* choice) {
    _control->addItem(choice);
}

QLayout* SettingsCombo::getLayout() {
    return _layout->layout();
}