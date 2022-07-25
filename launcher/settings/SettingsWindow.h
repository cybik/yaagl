//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSWINDOW_H
#define QAGL_SETTINGSWINDOW_H

#include <RibbonWidget>
#include <RibbonGroup>
#include <QMainWindow>
#include <memory>
#include <functional>

#include "SettingsTabs.h"
#include <QtWebEngineWidgets/QtWebEngineWidgets>

class SettingsWindow {
public:
    SettingsWindow();
    void show();
private:

    std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> setup();
    std::shared_ptr<QWebEngineView> setupGol();
    std::shared_ptr<QMainWindow> _settingsWindow;
    std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> ri;

    // meta-principle: a group is a widget hbox containing a bunch of ribbongroups?
    std::shared_ptr<SettingsTabGeneral> _tabGeneral;
    std::shared_ptr<SettingsTabGame> _tabGame;
    std::shared_ptr<SettingsTabEnhancements> _tabEnhancements;
    std::shared_ptr<SettingsTabRunner> _tabRunner;
    std::shared_ptr<SettingsTabMore> _tabMore;


    std::shared_ptr<QWebEngineView> settings_WebEngine;
};


#endif //QAGL_SETTINGSWINDOW_H
