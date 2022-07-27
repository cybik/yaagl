//
// Created by cybik on 22-07-24.
//

#include "SettingsLabel.h"

SettingsLabel::SettingsLabel(const QString& name) : SettingsControl(name){
    _control = std::make_shared<QLabel>();
    _control->setText(name);
    finalize();
}

void SettingsLabel::addToLayout() {
    _formLayout->addRow(_control.get());
}


QLayout* SettingsLabel::getLayout() {
    return _layout->layout();
}