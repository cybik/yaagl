//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSCOMBO_H
#define QAGL_SETTINGSCOMBO_H

#include <RibbonComboBox>
#include <string>
#include <QHBoxLayout>
#include <QLabel>
#include <memory>

#include "SettingsControl.h"

class SettingsCombo : public SettingsControl {
public:
    explicit SettingsCombo(const QString& name);
    QLayout* getLayout() override;
    void addChoice(const char* choice);
    void addChoices(int count, ...);
protected:
    void addToLayout() override;
private:
    std::shared_ptr<Nedrysoft::Ribbon::RibbonComboBox> _control;
};


#endif //QAGL_SETTINGSCOMBO_H
