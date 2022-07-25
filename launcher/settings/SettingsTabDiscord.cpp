//
// Created by cybik on 22-07-24.
//

#include "SettingsTabDiscord.h"

SettingsTabDiscord::SettingsTabDiscord(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri) {
    _tabWidget = std::make_shared<QWidget>();
    _tabLayout = _setupRibbonPage(std::make_shared<QHBoxLayout>(_tabWidget.get()));

    _setup = std::make_shared<Nedrysoft::Ribbon::RibbonGroup>();
    _setup->setGroupName("State");

    _tabLayout->addWidget(_setup.get());

    addTab(ri, "Discord");
}