//
// Created by cybik on 22-07-24.
//

#include "SettingsTabMore.h"
SettingsTabMore::SettingsTabMore(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri) : SettingsTab() {
    _moreShaders = std::make_shared<Nedrysoft::Ribbon::RibbonGroup>();
    _moreShaders->setGroupName("Shaders");
    _moreEnv = std::make_shared<Nedrysoft::Ribbon::RibbonGroup>();
    _moreEnv->setGroupName("Environment");

    _tabLayout->addWidget(_moreShaders.get());
    _tabLayout->addWidget(_moreEnv.get());

    addTab(ri, "Advanced");
}