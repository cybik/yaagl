//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSTABGENERAL_H
#define QAGL_SETTINGSTABGENERAL_H

#include "SettingsTab.h"
#include <RibbonWidget>
#include <QWidget>
#include <QHBoxLayout>

#include "util/SettingsControls.h"
#include "util/SettingsGroup.h"

class SettingsTabGeneral : public SettingsTab {
public:
    SettingsTabGeneral(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri);
private:
    void setupGeneralGroup();
    std::shared_ptr<SettingsGroup> _general;
    void setupLanguage();
    std::shared_ptr<SettingsCombo> _cbLang;
    void setupTheme();
    std::shared_ptr<SettingsCombo> _cbTheme;

    void setupPatchGroup();
    std::shared_ptr<SettingsGroup> _patch;
    void setupPatchDesc();
    std::shared_ptr<SettingsLabel> _cbPatchDesc;
    void setupPatchInfo();
    std::shared_ptr<SettingsLabel> _cbPatchInfo;
    void setupPatchRevert();
    std::shared_ptr<SettingsButton> _cbPatchRevert;
    void setupPatchReapply();
    std::shared_ptr<SettingsButton> _cbPatchReapply;

    void setupDiscordGroup();
    std::shared_ptr<SettingsGroup> _discord;
    void setupDiscord();
    std::shared_ptr<SettingsCheckbox> _cbDiscordEnabled;

    void setupDiscordTextOptionsGroup();
    std::shared_ptr<SettingsGroup> _discordSettings;
    void setupDiscordTextOptions();

    void setupDiscordIconOptionsGroup();
    std::shared_ptr<SettingsGroup> _discordIconSettings;
    void setupDiscordIconOptions();
};


#endif //QAGL_SETTINGSTABGENERAL_H
