//
// Created by cybik on 22-07-24.
//

#include "SettingsTabGeneral.h"

#include <cxxlib.rs.h>

SettingsTabGeneral::SettingsTabGeneral(Nedrysoft::Ribbon::RibbonWidget* ri) : SettingsTab() {
    setupGeneralGroup();
    setupPatchGroup();
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


void SettingsTabGeneral::setupPatchGroup() {
    _patch = std::make_shared<SettingsGroup>("Patch Ops");

    setupPatchDesc();
    setupPatchInfo();
    setupPatchRevert();
    setupPatchReapply();

    _tabLayout->addWidget(_patch->getWidget());
}

void SettingsTabGeneral::setupPatchDesc() {
    _cbPatchDesc = std::make_shared<SettingsLabel>("Patch Version:");
    _patch->addControl(_cbPatchDesc);
}

void SettingsTabGeneral::setupPatchInfo() {
    _cbPatchInfo = std::make_shared<SettingsLabel>("Patch Info");
    _cbPatchInfo->getControl()
                ->setAlignment(Qt::AlignmentFlag::AlignRight);
    _cbPatchInfo->setColor(QColor::fromRgb(104,81,216));
    _patch->addControl(_cbPatchInfo);

    _cbPatchInfo->setText(QString(moe::launcher::agcli::get_upstream_patch_state().version.c_str()));
}

void SettingsTabGeneral::setupPatchRevert() {
    _cbPatchRevert = std::make_shared<SettingsButton>("Revert Patch");
    _patch->addControl(_cbPatchRevert);
}

void SettingsTabGeneral::setupPatchReapply() {
    _cbPatchReapply = std::make_shared<SettingsButton>("Reapply Patch");
    _patch->addControl(_cbPatchReapply);
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

void SettingsTabGeneral::parse(std::shared_ptr<Settings> data) {
    _cbDiscordEnabled->setChecked(data->discord.enabled);
}