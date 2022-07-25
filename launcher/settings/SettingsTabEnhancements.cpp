//
// Created by cybik on 22-07-24.
//

#include "SettingsTabEnhancements.h"

SettingsTabEnhancements::SettingsTabEnhancements(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri) {
    _tabWidget = std::make_shared<QWidget>();
    _tabLayout = _setupRibbonPage(std::make_shared<QHBoxLayout>(_tabWidget.get()));

    setupWINEGroup();
    setupGameGroup();
    setupLauncherGroup();

    ri->addTab(_tabWidget.get(), "Enhancements");
}

void SettingsTabEnhancements::setupWINEGroup() {
    _enhWine = std::make_shared<SettingsGroup>("WINE");
    _tabLayout->addWidget(_enhWine->getWidget());
    setupHudCombo();
    setupWineSyncCombo();
    setupAmdFSRCb();
    setupVirtualDesktopCb();
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
    _tabLayout->addWidget(_enhGame->getWidget());

    setupGameModeCb();
    setupBorderlessWindowCb();
    setupUnlocFPSCb();
    setupTerminalCb();
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
    _tabLayout->addWidget(_enhLauncher->getWidget());
    setupLauncherCombo();
}

void SettingsTabEnhancements::setupLauncherCombo() {
    _cbLauncherCombo = std::make_shared<SettingsCombo>("Delete launcher logs");
    _cbLauncherCombo->addChoices(3,
                       "1 day", "3 days", "5 days"
    );
    _enhLauncher->addControl(_cbLauncherCombo);
}
