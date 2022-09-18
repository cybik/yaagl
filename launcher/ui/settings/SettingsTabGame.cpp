//
// Created by cybik on 22-07-24.
//

#include "SettingsTabGame.h"

SettingsTabGame::SettingsTabGame(Nedrysoft::Ribbon::RibbonWidget* ri) : SettingsTab() {
    setupGeneralGroup();
    setupVoicePacksGroup();
    setupMiscGroup();

    addTab(ri, "Game Setup");
}

void SettingsTabGame::setupGeneralGroup() {
    _general = std::make_shared<SettingsGroup>("General");

    setupGeneral();
    _tabLayout->addWidget(_general->getWidget());
}

void SettingsTabGame::setupGeneral() { }

void SettingsTabGame::setupVoicePacksGroup() {
    _voicepacks = std::make_shared<SettingsGroup>("Voice Packs");

    setupVoicePacks();

    _tabLayout->addWidget(_voicepacks->getWidget());
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

    setupGeneral();

    _tabLayout->addWidget(_misc->getWidget());
}

void SettingsTabGame::setupMisc() { }

void SettingsTabGame::parse(std::shared_ptr<Settings> data) {
    _cbEN->setChecked(data->lang.lang_game_en);
    _cbJA->setChecked(data->lang.lang_game_jp);
    _cbKR->setChecked(data->lang.lang_game_kr);
    _cbZH->setChecked(data->lang.lang_game_zh);
}