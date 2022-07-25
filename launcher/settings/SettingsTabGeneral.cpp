//
// Created by cybik on 22-07-24.
//

#include "SettingsTabGeneral.h"

void SettingsTabGeneral::setupGeneralGroup() {
    _general = std::make_shared<SettingsGroup>("Launcher");
    _tabLayout->addWidget(_general->getWidget());

    setupLanguage();
    setupTheme();
}

void SettingsTabGeneral::setupPatchGroup() {
    _general2 = std::make_shared<SettingsGroup>("Voice Pack");
    _tabLayout->addWidget(_general2->getWidget());
}


SettingsTabGeneral::SettingsTabGeneral(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri) : SettingsTab() {
    _tabWidget = std::make_shared<QWidget>();
    _tabLayout = _setupRibbonPage(std::make_shared<QHBoxLayout>(_tabWidget.get()));

    setupGeneralGroup();
    setupPatchGroup();

    ri->addTab(_tabWidget.get(), "General");
}

void SettingsTabGeneral::setupLanguage() {
    _cbLang = std::make_shared<SettingsCombo>("Language");
    _cbLang->addChoices(11,
                        "English (US)", "Русский", "Español",
                        "Deutsch", "Français", "Italiano", "日本語",
                        "Magyar", "Norsk", "简体中文", "Engwish"
    );
    _general->addControl(_cbLang);
}

void SettingsTabGeneral::setupTheme() {
    _cbTheme = std::make_shared<SettingsCombo>("Theme");
    _cbTheme->addChoices(3, "System", "Dark", "Light");
    _general->addControl(_cbTheme);
}
