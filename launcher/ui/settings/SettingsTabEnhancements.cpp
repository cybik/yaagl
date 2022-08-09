//
// Created by cybik on 22-07-24.
//

#include "SettingsTabEnhancements.h"

SettingsTabEnhancements::SettingsTabEnhancements(Nedrysoft::Ribbon::RibbonWidget* ri) : SettingsTab() {
    setupWINEGroup();
    setupGameGroup();
    setupLauncherGroup();

    addTab(ri, "Enhancements");
}

void SettingsTabEnhancements::setupWINEGroup() {
    _enhWine = std::make_shared<SettingsGroup>("WINE");
    setupHudCombo();
    setupWineSyncCombo();
    setupAmdFSRCb();
    setupVirtualDesktopCb();

    _tabLayout->addWidget(_enhWine->getWidget());
}

void SettingsTabEnhancements::setupHudCombo() {
    _cbHud = std::make_shared<SettingsCombo>("HUD");
    _cbHud->addChoices(3, "None", "DXVK", "MangoHUD");
    _enhWine->addControl(_cbHud);
}

void SettingsTabEnhancements::setupWineSyncCombo() {
    _cbWineSync = std::make_shared<SettingsCombo>("WINE Synchronization");
    _cbWineSync->addChoices(4, "None", "ESync", "FSync", "Futex2");
    _enhWine->addControl(_cbWineSync);
}

void SettingsTabEnhancements::setupAmdFSRCb() {
    _cbFSR = std::make_shared<SettingsCheckbox>("Allow AMD FSR");
    _enhWine->addControl(_cbFSR);
}

void SettingsTabEnhancements::setupVirtualDesktopCb() {
    _cbVirDesk = std::make_shared<SettingsCheckbox>("Virtual Desktop");
    _enhWine->addControl(_cbVirDesk);
}

///

void SettingsTabEnhancements::setupGameGroup() {
    _enhGame = std::make_shared<SettingsGroup>("Game");
    setupGameModeCb();
    setupBorderlessWindowCb();
    setupUnlocFPSCb();
    setupTerminalCb();
    _tabLayout->addWidget(_enhGame->getWidget());
}

void SettingsTabEnhancements::setupGameModeCb() {
    _cbGamemode = std::make_shared<SettingsCheckbox>("Use GameMode");
    _enhGame->addControl(_cbGamemode);
}

void SettingsTabEnhancements::setupBorderlessWindowCb() {
    _cbWindow = std::make_shared<SettingsCheckbox>("Allow Borderless Window");
    _enhGame->addControl(_cbWindow);
}

void SettingsTabEnhancements::setupUnlocFPSCb() {
    _cbFPS = std::make_shared<SettingsCheckbox>("Unlock FPS (DANGER)");
    _enhGame->addControl(_cbFPS);
}

void SettingsTabEnhancements::setupTerminalCb() {
    _cbTerm = std::make_shared<SettingsCheckbox>("Use Terminal");
    _enhGame->addControl(_cbTerm);
}

void SettingsTabEnhancements::setupLauncherGroup() {
    _enhLauncher = std::make_shared<SettingsGroup>("Launcher");
    setupLauncherCombo();
    _tabLayout->addWidget(_enhLauncher->getWidget());
}

void SettingsTabEnhancements::setupLauncherCombo() {
    _cbLauncherCombo = std::make_shared<SettingsCombo>("Delete launcher logs");
    _cbLauncherCombo->addChoices(3,
                       "1 day", "3 days", "5 days"
    );
    _enhLauncher->addControl(_cbLauncherCombo);
}
