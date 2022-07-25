//
// Created by cybik on 22-07-24.
//

#include "SettingsGroup.h"

SettingsGroup::SettingsGroup(std::string name) {
    _group = std::make_shared<Nedrysoft::Ribbon::RibbonGroup>();
    _group->setGroupName(name.c_str());
    _groupLayout = std::make_shared<QVBoxLayout>();
    _group->setLayout(_groupLayout.get());
}

void SettingsGroup::addControl(std::shared_ptr<SettingsControl> cb) {
    _groupLayout->addLayout(cb->getLayout());
}

QWidget* SettingsGroup::getWidget() {
    return _group.get();
}