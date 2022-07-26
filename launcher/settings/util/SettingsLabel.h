//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSLABEL_H
#define QAGL_SETTINGSLABEL_H

#include <RibbonCheckBox>
#include <string>
#include <QHBoxLayout>
#include <QLabel>
#include <memory>

#include "SettingsControl.h"

class SettingsLabel : public SettingsControl {
public:
    explicit SettingsLabel(std::string name);
    QLayout* getLayout() override;
    std::shared_ptr<QLabel> getControl() { return _control; }
private:
    std::shared_ptr<QLabel> _control;
};


#endif //QAGL_SETTINGSCOMBO_H