//
// Created by cybik on 22-07-24.
//

#include "SettingsTabRunner.h"

SettingsTabRunner::SettingsTabRunner(Nedrysoft::Ribbon::RibbonWidget* ri) : SettingsTab() {
    _runWINE = std::make_shared<Nedrysoft::Ribbon::RibbonGroup>();
    _runWINE->setGroupName("Runner Setup");
    _runDXVK = std::make_shared<Nedrysoft::Ribbon::RibbonGroup>();
    _runDXVK->setGroupName("DXVK Setup");

    _tabLayout->addWidget(_runWINE.get());
    _tabLayout->addWidget(_runDXVK.get());

    addTab(ri, "Runner");
}