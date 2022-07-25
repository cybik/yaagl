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

    setupLanguage();
    setupTheme();

    _tabLayout->addWidget(_general->getWidget());
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

    setupDiscord();

    _tabLayout->addWidget(_discord->getWidget());
}

void SettingsTabGeneral::setupDiscord() {
    _cbDiscordEnabled = std::make_shared<SettingsCheckbox>("Enable Discord RPC");
    _discord->addControl(_cbDiscordEnabled);
}

void SettingsTabGeneral::setupDiscordTextOptionsGroup() {
    _discordSettings = std::make_shared<SettingsGroup>("Discord");

    setupDiscordTextOptions();
    _discordSettings->getWidget()->setVisible(false);

    _tabLayout->addWidget(_discordSettings->getWidget());
}

void SettingsTabGeneral::setupDiscordTextOptions() {

}

void SettingsTabGeneral::setupDiscordIconOptionsGroup() {
    _discordIconSettings = std::make_shared<SettingsGroup>("Discord Icons");

    setupDiscordIconOptions();
    _discordIconSettings->getWidget()->setVisible(false);

    _tabLayout->addWidget(_discordIconSettings->getWidget());
}

void SettingsTabGeneral::setupDiscordIconOptions() {

}