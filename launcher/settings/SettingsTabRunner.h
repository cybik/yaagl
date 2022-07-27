//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSTABRUNNER_H
#define QAGL_SETTINGSTABRUNNER_H

#include "SettingsTab.h"
#include <RibbonWidget>
#include <RibbonGroup>
#include <QWidget>
#include <QHBoxLayout>

class SettingsTabRunner : public SettingsTab {
public:
    explicit SettingsTabRunner(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri);
private:
    std::shared_ptr<Nedrysoft::Ribbon::RibbonGroup> _runWINE;
    std::shared_ptr<Nedrysoft::Ribbon::RibbonGroup> _runDXVK;
};


#endif //QAGL_SETTINGSTABRUNNER_H
