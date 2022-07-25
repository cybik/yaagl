//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSTABGENERAL_H
#define QAGL_SETTINGSTABGENERAL_H

#include "SettingsTab.h"
#include <RibbonWidget>
#include <QWidget>
#include <QHBoxLayout>

#include "util/SettingsCombo.h"

#include "util/SettingsGroup.h"

class SettingsTabGeneral : public SettingsTab {
public:
    SettingsTabGeneral(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri);
private:
    void setupGeneralGroup();
    void setupPatchGroup();
    std::shared_ptr<SettingsGroup> _general;
    std::shared_ptr<SettingsGroup> _general2;

    std::shared_ptr<SettingsCombo> _cbLang;
    std::shared_ptr<SettingsCombo> _cbTheme;

    void setupLanguage();
    void setupTheme();
};


#endif //QAGL_SETTINGSTABGENERAL_H
