//
// Created by cybik on 22-07-24.
//

#include "SettingsTabMore.h"
SettingsTabMore::SettingsTabMore(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri) {
    _tabWidget = std::make_shared<QWidget>();
    _tabLayout = _setupRibbonPage(std::make_shared<QHBoxLayout>(_tabWidget.get()));

    _moreShaders = std::make_shared<Nedrysoft::Ribbon::RibbonGroup>();
    _moreShaders->setGroupName("Shaders");
    _moreEnv = std::make_shared<Nedrysoft::Ribbon::RibbonGroup>();
    _moreEnv->setGroupName("Environment");

    _tabLayout->addWidget(_moreShaders.get());
    _tabLayout->addWidget(_moreEnv.get());

    ri->addTab(_tabWidget.get(), "More");
}