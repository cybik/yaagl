//
// Created by cybik on 22-07-24.
//

#include "SettingsCheckbox.h"

SettingsCheckbox::SettingsCheckbox(std::string name) {
    _layout = std::make_shared<QGridLayout>();
    _layout->setSizeConstraint(QLayout::SetDefaultConstraint);
    _layout->setObjectName((name+"_cbx_layout").c_str());

    _formLayout = std::make_shared<QFormLayout>();
    _formLayout->setSizeConstraint(QLayout::SetMinimumSize);
    _formLayout->setVerticalSpacing(8);
    _formLayout->setObjectName((name+"_cbx_cf_layout").c_str());

    _control = std::make_shared<Nedrysoft::Ribbon::RibbonCheckBox>();
    _control->setText(name.c_str());

    _formLayout->addRow(_control.get());

    _layout->addLayout(_formLayout->layout(), 0, 0);
}

QLayout* SettingsCheckbox::getLayout() {
    return _layout->layout();
}