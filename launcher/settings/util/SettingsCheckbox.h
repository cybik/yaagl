//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSCHECK_H
#define QAGL_SETTINGSCHECK_H

#include <RibbonCheckBox>
#include <string>
#include <QHBoxLayout>
#include <QLabel>
#include <memory>

#include "SettingsControl.h"

class SettingsCheckbox : public SettingsControl {
public:
    explicit SettingsCheckbox(const QString& name);
    QLayout* getLayout() override;
protected:
    void addToLayout() override;
private:
    std::shared_ptr<Nedrysoft::Ribbon::RibbonCheckBox> _control;
};


#endif //QAGL_SETTINGSCOMBO_H
