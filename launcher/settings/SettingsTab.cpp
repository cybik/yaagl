//
// Created by cybik on 22-07-24.
//

#include "SettingsTab.h"

std::shared_ptr<QHBoxLayout> SettingsTab::_setupRibbonPage(std::shared_ptr<QHBoxLayout> layout) {
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);
    return layout;
}