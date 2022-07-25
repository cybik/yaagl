//
// Created by cybik on 22-07-24.
//

#include "SettingsTabGame.h"

SettingsTabGame::SettingsTabGame(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri) : SettingsTab() {
    _tabWidget = std::make_shared<QWidget>();
    _tabLayout = _setupRibbonPage(std::make_shared<QHBoxLayout>(_tabWidget.get()));

    _setup = std::make_shared<Nedrysoft::Ribbon::RibbonGroup>();
    _setup->setGroupName("Game Setup");
    _misc = std::make_shared<Nedrysoft::Ribbon::RibbonGroup>();
    _misc->setGroupName("Miscellaneous");

    _tabLayout->addWidget(_setup.get());
    _tabLayout->addWidget(_misc.get());

    ri->addTab(_tabWidget.get(), "Setup");
}