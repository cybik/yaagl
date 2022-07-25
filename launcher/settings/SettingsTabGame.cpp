//
// Created by cybik on 22-07-24.
//

#include "SettingsTabGame.h"

SettingsTabGame::SettingsTabGame(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri) : SettingsTab() {
    _tabWidget = std::make_shared<QWidget>();
    _tabLayout = _setupRibbonPage(std::make_shared<QHBoxLayout>(_tabWidget.get()));

    setupGeneralGroup();
    setupVoicePacksGroup();
    setupMiscGroup();

    addTab(ri, "Game Setup");
}

void SettingsTabGame::setupGeneralGroup() {
    _general = std::make_shared<SettingsGroup>("General");
    _tabLayout->addWidget(_general->getWidget());

    setupGeneral();
}

void SettingsTabGame::setupGeneral() { }

void SettingsTabGame::setupVoicePacksGroup() {
    _voicepacks = std::make_shared<SettingsGroup>("Voice Packs");
    _tabLayout->addWidget(_voicepacks->getWidget());

    setupVoicePacks();
}

void SettingsTabGame::setupVoicePacks() {
    _cbEN = std::make_shared<SettingsCheckbox>("English");
    _voicepacks->addControl(_cbEN);

    _cbJA = std::make_shared<SettingsCheckbox>("日本語");
    _voicepacks->addControl(_cbJA);

    _cbKR = std::make_shared<SettingsCheckbox>("한글");
    _voicepacks->addControl(_cbKR);

    _cbZH = std::make_shared<SettingsCheckbox>("简体中文");
    _voicepacks->addControl(_cbZH);
}

void SettingsTabGame::setupMiscGroup() {
    _misc = std::make_shared<SettingsGroup>("Miscellaneous");
    _tabLayout->addWidget(_misc->getWidget());

    setupGeneral();
}

void SettingsTabGame::setupMisc() { }