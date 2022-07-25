//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSTABDISCORD_H
#define QAGL_SETTINGSTABDISCORD_H


#include "SettingsTab.h"
#include <RibbonWidget>
#include <RibbonGroup>
#include <QWidget>
#include <QHBoxLayout>

class SettingsTabDiscord : public SettingsTab {
public:
    SettingsTabDiscord(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri);
private:
    std::shared_ptr<Nedrysoft::Ribbon::RibbonGroup> _setup;
};

#endif //QAGL_SETTINGSTABDISCORD_H
