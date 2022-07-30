//
// Created by cybik on 22-07-24.
//

#include "SettingsCombo.h"

SettingsCombo::SettingsCombo(const QString& name) : SettingsControl(name) {
    _control = std::make_shared<Nedrysoft::Ribbon::RibbonComboBox>();
    _control->setSizePolicy(QSizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum));
    finalize();
}

void SettingsCombo::addToLayout() {
    _formLayout->addRow(_name, _control.get());
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

void SettingsCombo::setupEventHandlers() {
    // noop
    connect(
        _control.get(), SIGNAL(currentIndexChanged(int)),
        this, SLOT(onIndexChanged(int))
    );
}

void SettingsCombo::onIndexChanged(int newIndex) {

}