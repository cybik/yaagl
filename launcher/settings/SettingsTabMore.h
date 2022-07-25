//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSTABMORE_H
#define QAGL_SETTINGSTABMORE_H

#include "SettingsTab.h"
#include <RibbonWidget>
#include <RibbonGroup>
#include <QWidget>
#include <QHBoxLayout>


class SettingsTabMore : public SettingsTab {
public:
    SettingsTabMore(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri);
private:
    std::shared_ptr<Nedrysoft::Ribbon::RibbonGroup> _moreShaders;
    std::shared_ptr<Nedrysoft::Ribbon::RibbonGroup> _moreEnv;
};


#endif //QAGL_SETTINGSTABMORE_H