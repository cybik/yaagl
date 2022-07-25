//
// Created by cybik on 22-07-24.
//

#include "SettingsTabGeneral.h"

SettingsTabGeneral::SettingsTabGeneral(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri) : SettingsTab() {
    _tabWidget = std::make_shared<QWidget>();
    _tabLayout = _setupRibbonPage(std::make_shared<QHBoxLayout>(_tabWidget.get()));

    setupGeneralGroup();
    setupDiscordGroup();
    setupDiscordTextOptionsGroup();
    setupDiscordIconOptionsGroup();

    addTab(ri, "General");
}

void SettingsTabGeneral::setupGeneralGroup() {
    _general = std::make_shared<SettingsGroup>("Launcher");
    _tabLayout->addWidget(_general->getWidget());

    setupLanguage();
    setupTheme();
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


void SettingsTabGeneral::setupDiscordGroup() {
    _discord = std::make_shared<SettingsGroup>("Discord");
    _tabLayout->addWidget(_discord->getWidget());

    setupDiscord();
}

void SettingsTabGeneral::setupDiscord() {
    _cbDiscordEnabled = std::make_shared<SettingsCheckbox>("Enable Discord RPC");
    _discord->addControl(_cbDiscordEnabled);
}

void SettingsTabGeneral::setupDiscordTextOptionsGroup() {
    _discordSettings = std::make_shared<SettingsGroup>("Discord");
    _tabLayout->addWidget(_discordSettings->getWidget());
    _discordSettings->getWidget()->setVisible(false);

    setupDiscordTextOptions();
}

void SettingsTabGeneral::setupDiscordTextOptions() {

}

void SettingsTabGeneral::setupDiscordIconOptionsGroup() {
    _discordIconSettings = std::make_shared<SettingsGroup>("Discord Icons");
    _tabLayout->addWidget(_discordIconSettings->getWidget());
    _discordIconSettings->getWidget()->setVisible(false);

    setupDiscordIconOptions();
}

void SettingsTabGeneral::setupDiscordIconOptions() {

}