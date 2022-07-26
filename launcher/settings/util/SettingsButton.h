//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSBTN_H
#define QAGL_SETTINGSBTN_H

#include <RibbonButton>
#include <string>
#include <QHBoxLayout>
#include <QLabel>
#include <memory>

#include "SettingsControl.h"

class SettingsButton : public SettingsControl {
public:
    explicit SettingsButton(std::string name);
    QLayout* getLayout() override;
private:
    std::shared_ptr<Nedrysoft::Ribbon::RibbonButton> _control;
};


#endif //QAGL_SETTINGSCOMBO_H
