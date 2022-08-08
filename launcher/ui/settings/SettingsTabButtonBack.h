//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSTABBACK_H
#define QAGL_SETTINGSTABBACK_H

#include "SettingsTab.h"
#include "3rdParty/nedrysoft/Ribbon/include/RibbonWidget"
#include "3rdParty/nedrysoft/Ribbon/include/RibbonGroup"
#include <QWidget>
#include <QHBoxLayout>

class SettingsTabButtonBack : public SettingsTab
{
public:
    explicit SettingsTabButtonBack(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri);
};


#endif //QAGL_SETTINGSTABMORE_H
