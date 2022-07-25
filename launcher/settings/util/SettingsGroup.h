//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSGROUP_H
#define QAGL_SETTINGSGROUP_H

#include <RibbonGroup>
#include <string>
#include <QVBoxLayout>

#include "SettingsControls.h"

class SettingsGroup {
public:
    explicit SettingsGroup(std::string);
    QWidget* getWidget();
    void addControl(std::shared_ptr<SettingsControl>);
private:
    std::shared_ptr<Nedrysoft::Ribbon::RibbonGroup> _group;
    std::shared_ptr<QVBoxLayout> _groupLayout;
};


#endif //QAGL_SETTINGSGROUP_H
