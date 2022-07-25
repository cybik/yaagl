//
// Created by cybik on 22-07-24.
//

#include "SettingsCombo.h"

SettingsCombo::SettingsCombo(std::string name) {
    _layout = std::make_shared<QGridLayout>();
    _layout->setSizeConstraint(QLayout::SetDefaultConstraint);
    _layout->setObjectName((name + "_cb_layout").c_str());

    _formLayout = std::make_shared<QFormLayout>();
    _formLayout->setSizeConstraint(QLayout::SetMinimumSize);
    _formLayout->setVerticalSpacing(8);
    _formLayout->setObjectName((name + "_cb_cf_layout").c_str());

    _control = std::make_shared<Nedrysoft::Ribbon::RibbonComboBox>();
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