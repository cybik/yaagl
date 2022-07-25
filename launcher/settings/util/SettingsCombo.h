//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSCOMBO_H
#define QAGL_SETTINGSCOMBO_H

#include <RibbonGroup>
#include <RibbonComboBox>
#include <string>
#include <QHBoxLayout>
#include <QLabel>
#include <memory>

#include "SettingsControl.h"

class SettingsCombo : public SettingsControl {
public:
    QLayout* getLayout() override;
    SettingsCombo(std::string name);
    void addChoice(const char* choice);
    void addChoices(int count, ...);
    std::shared_ptr<QGridLayout> _layout;
    std::shared_ptr<QFormLayout> _formLayout;
    std::shared_ptr<Nedrysoft::Ribbon::RibbonComboBox> _control;
};


#endif //QAGL_SETTINGSCOMBO_H
