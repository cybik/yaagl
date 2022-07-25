//
// Created by cybik on 22-07-24.
//

#include "SettingsControl.h"

SettingsControl::SettingsControl(std::string name) {
    _layout = std::make_shared<QGridLayout>();
    _layout->setSizeConstraint(QLayout::SetMinimumSize);
    _layout->setObjectName((name + "_sc_cb_layout").c_str());

    _formLayout = std::make_shared<QFormLayout>();
    _formLayout->setSizeConstraint(QLayout::SetMinimumSize);
    _formLayout->setVerticalSpacing(6);
    _formLayout->setObjectName((name + "_sc_cb_cf_layout").c_str());
}