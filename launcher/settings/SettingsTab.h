//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSTAB_H
#define QAGL_SETTINGSTAB_H

#include <QWidget>
#include <QHBoxLayout>
#include <memory>
#include <RibbonWidget>

class SettingsTab {
public:
    SettingsTab() = default;
protected:
    void addTab(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget>, std::string);
    std::shared_ptr<QHBoxLayout> _setupRibbonPage(std::shared_ptr<QHBoxLayout> layout);
    std::shared_ptr<QWidget> _tabWidget;
    std::shared_ptr<QHBoxLayout> _tabLayout;
};


#endif //QAGL_SETTINGSTAB_H
