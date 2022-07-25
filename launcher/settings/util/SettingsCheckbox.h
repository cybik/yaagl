//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSCHECK_H
#define QAGL_SETTINGSCHECK_H

#include <RibbonGroup>
#include <RibbonCheckBox>
#include <string>
#include <QHBoxLayout>
#include <QLabel>
#include <memory>

#include "SettingsControl.h"

class SettingsCheckbox : public SettingsControl {
public:
    QLayout* getLayout() override;
    SettingsCheckbox(std::string name);
    std::shared_ptr<QGridLayout> _layout;
    std::shared_ptr<QFormLayout> _formLayout;
    std::shared_ptr<Nedrysoft::Ribbon::RibbonCheckBox> _control;
};


#endif //QAGL_SETTINGSCOMBO_H
