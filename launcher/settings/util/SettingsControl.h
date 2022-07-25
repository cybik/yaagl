//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSCONTROL_H
#define QAGL_SETTINGSCONTROL_H

#include <QLayout>
#include <QFormLayout>
#include <string>
#include <RibbonGroup>
#include <memory>

class SettingsControl {
public:
    explicit SettingsControl(std::string);
    virtual QLayout* getLayout() = 0;
protected:
    std::shared_ptr<QGridLayout> _layout;
    std::shared_ptr<QFormLayout> _formLayout;
};

#endif //QAGL_SETTINGSCONTROL_H
