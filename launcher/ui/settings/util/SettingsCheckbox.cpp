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

void SettingsCheckbox::setupEventHandlers() {
    connect(
        _control.get(), SIGNAL(stateChanged(int)),
        this, SLOT(onStateChanged(int))
    );
}

void SettingsCheckbox::setChecked(bool checked) {
    _control->setChecked(checked);
}

bool SettingsCheckbox::isChecked() {
    return _control->isChecked();
}

void SettingsCheckbox::onStateChanged(int newState) {

}