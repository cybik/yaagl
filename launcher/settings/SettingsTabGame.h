//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSTABGAME_H
#define QAGL_SETTINGSTABGAME_H


#include "SettingsTab.h"
#include <RibbonWidget>
#include <RibbonGroup>
#include <QWidget>
#include <QHBoxLayout>

#include "util/SettingsControls.h"
#include "util/SettingsGroup.h"


class SettingsTabGame : public SettingsTab {
public:
    explicit SettingsTabGame(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri);
private:
    std::shared_ptr<Nedrysoft::Ribbon::RibbonGroup> _setup;

    void setupGeneralGroup();
    std::shared_ptr<SettingsGroup> _general;
    void setupGeneral();

    void setupVoicePacksGroup();
    std::shared_ptr<SettingsGroup> _voicepacks;
    void setupVoicePacks();
    std::shared_ptr<SettingsCheckbox> _cbEN;
    std::shared_ptr<SettingsCheckbox> _cbJA;
    std::shared_ptr<SettingsCheckbox> _cbKR;
    std::shared_ptr<SettingsCheckbox> _cbZH;

    void setupMiscGroup();
    std::shared_ptr<SettingsGroup> _misc;
    void setupMisc();
};

#endif //QAGL_SETTINGSTABGAME_H
