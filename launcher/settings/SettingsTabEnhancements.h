//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSTABENHANCEMENTS_H
#define QAGL_SETTINGSTABENHANCEMENTS_H

#include "SettingsTab.h"
#include "util/SettingsGroup.h"
#include <RibbonWidget>
#include <RibbonGroup>
#include <QWidget>
#include <QHBoxLayout>

#include "util/SettingsControls.h"

class SettingsTabEnhancements : public SettingsTab {
public:
    SettingsTabEnhancements(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri);
private:
    std::shared_ptr<SettingsGroup> _enhWine;
    std::shared_ptr<SettingsGroup> _enhGame;
    std::shared_ptr<SettingsGroup> _enhLauncher;

    void setupWINEGroup();
    void setupGameGroup();
    void setupLauncherGroup();

    void setupHudCombo();
    std::shared_ptr<SettingsCombo> _cbHud;
    void setupWineSyncCombo();
    std::shared_ptr<SettingsCombo> _cbWineSync;
    void setupAmdFSRCb();
    std::shared_ptr<SettingsCheckbox> _cbFSR;
    void setupVirtualDesktopCb();
    std::shared_ptr<SettingsCheckbox> _cbVirDesk;
    void setupGameModeCb();
    std::shared_ptr<SettingsCheckbox> _cbGamemode;
    void setupBorderlessWindowCb();
    std::shared_ptr<SettingsCheckbox> _cbWindow;
    void setupUnlocFPSCb();
    std::shared_ptr<SettingsCheckbox> _cbFPS;
    void setupTerminalCb();
    std::shared_ptr<SettingsCheckbox> _cbTerm;

    void setupLauncherCombo();
    std::shared_ptr<SettingsCombo> _cbLauncherCombo;
};


#endif //QAGL_SETTINGSTABENHANCEMENTS_H
