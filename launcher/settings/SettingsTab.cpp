//
// Created by cybik on 22-07-24.
//

#include "SettingsTab.h"

void SettingsTab::addTab(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri, std::string name) {
    _tabLayout->addStretch();
    ri->addTab(_tabWidget.get(), name.c_str());
}

std::shared_ptr<QHBoxLayout> SettingsTab::_setupRibbonPage(std::shared_ptr<QHBoxLayout> layout) {
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);
    return layout;
}