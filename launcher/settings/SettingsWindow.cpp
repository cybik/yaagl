//
// Created by cybik on 22-07-24.
//

#include "SettingsWindow.h"

SettingsWindow::SettingsWindow() {
    _settingsWindow = std::make_shared<QMainWindow>();
    _settingsWindow->setWindowTitle("QAGL Settings");

    ri = std::make_shared<Nedrysoft::Ribbon::RibbonWidget>();
    _settingsWindow->setFixedSize(800,580);
    _settingsWindow->setWindowModality(Qt::ApplicationModal);
    _settingsWindow->setMenuWidget(setup().get());
    _settingsWindow->setCentralWidget(setupGol().get());
}

std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> SettingsWindow::setup() {
    _tabGeneral = std::make_shared<SettingsTabGeneral>(ri);
    _tabDiscord = std::make_shared<SettingsTabDiscord>(ri);
    _tabEnhancements = std::make_shared<SettingsTabEnhancements>(ri);

    _tabGame = std::make_shared<SettingsTabGame>(ri);
    _tabRunner = std::make_shared<SettingsTabRunner>(ri);
    _tabMore = std::make_shared<SettingsTabMore>(ri);

    ri->setFixedHeight(ri->height()+30);

    return ri;
}
std::shared_ptr<QWebEngineView> SettingsWindow::setupGol() {
    settings_WebEngine = std::make_shared<QWebEngineView>();
    settings_WebEngine->setContextMenuPolicy(Qt::NoContextMenu);
    settings_WebEngine->setAcceptDrops(false);
    settings_WebEngine->load(QUrl("https://gol.launcher.moe"));
    return settings_WebEngine;
}

void SettingsWindow::show() {
    _settingsWindow->show();
}