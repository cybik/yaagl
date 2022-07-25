//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSTABGAME_H
#define QAGL_SETTINGSTABGAME_H


#include "SettingsTab.h"
#include <RibbonWidget>
#include <RibbonGroup>
#include <QWidget>
#include <QHBoxLayout>

class SettingsTabGame : public SettingsTab {
public:
    SettingsTabGame(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri);
private:
    std::shared_ptr<Nedrysoft::Ribbon::RibbonGroup> _setup;
    std::shared_ptr<Nedrysoft::Ribbon::RibbonGroup> _misc;
};

#endif //QAGL_SETTINGSTABGAME_H
