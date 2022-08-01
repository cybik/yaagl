//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSWINDOW_H
#define QAGL_SETTINGSWINDOW_H

#include "3rdParty/nedrysoft/Ribbon/include/RibbonWidget"
#include "3rdParty/nedrysoft/Ribbon/include/RibbonGroup"
#include <QMainWindow>
#include <memory>
#include <functional>

#include "SettingsTabs.h"
#include <QtWebEngineWidgets/QtWebEngineWidgets>

#include "launcher/data/SettingsData.h"

class SettingsWindow {
public:
    SettingsWindow(bool usedAsWidget = false, QWidget* parent = nullptr);
    void show();
    std::shared_ptr<QWidget> getWidget();

    void setConfig(std::shared_ptr<SettingsData> ptr);
private:

    std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> setup();
    std::shared_ptr<QWebEngineView> setupGol();
    std::shared_ptr<QMainWindow> _settingsWindow;

    std::shared_ptr<QVBoxLayout> _settingsLayout;
    std::shared_ptr<QWidget> _settingsWidget;

    std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri;

    // meta-principle: a group is a widget hbox containing a bunch of ribbongroups?
    std::shared_ptr<SettingsTabGeneral> _tabGeneral;
    std::shared_ptr<SettingsTabGame> _tabGame;
    std::shared_ptr<SettingsTabEnhancements> _tabEnhancements;
    std::shared_ptr<SettingsTabRunner> _tabRunner;
    std::shared_ptr<SettingsTabMore> _tabMore;
    std::shared_ptr<QWebEngineView> settings_WebEngine;

    std::shared_ptr<SettingsData> _config;
};


#endif //QAGL_SETTINGSWINDOW_H