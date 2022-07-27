//
// Created by cybik on 22-07-24.
//

#include "SettingsWindow.h"

SettingsWindow::SettingsWindow(bool usedAsWidget, QWidget* parent) {
    _settingsWindow = std::make_shared<QMainWindow>(parent);
    _settingsWindow->setWindowTitle("QAGL Settings");

    _settingsWindow->setFixedSize(800,580);
    _settingsWindow->setWindowModality(Qt::ApplicationModal);

    _settingsLayout = std::make_shared<QVBoxLayout>(parent);
    _settingsLayout->setContentsMargins(0,0,0,0);
    _settingsLayout->setSpacing(0);
    _settingsLayout->addWidget(setup().get());
    _settingsLayout->addWidget(setupGol().get());
    _settingsWidget = std::make_shared<QWidget>(parent);
    _settingsWidget->setLayout(_settingsLayout.get());
    _settingsWindow->setCentralWidget(_settingsWidget.get());
}

std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> SettingsWindow::setup() {
    if(ri == nullptr) {
        ri = std::make_shared<Nedrysoft::Ribbon::RibbonWidget>();
        _tabGeneral = std::make_shared<SettingsTabGeneral>(ri);
        _tabGame = std::make_shared<SettingsTabGame>(ri);
        _tabRunner = std::make_shared<SettingsTabRunner>(ri);
        _tabEnhancements = std::make_shared<SettingsTabEnhancements>(ri);
        _tabMore = std::make_shared<SettingsTabMore>(ri);
        ri->setFixedHeight(ri->height() + 30);
    }

    return ri;
}
std::shared_ptr<QWebEngineView> SettingsWindow::setupGol() {
    if(settings_WebEngine == nullptr) {
        settings_WebEngine = std::make_shared<QWebEngineView>();
        settings_WebEngine->setContextMenuPolicy(Qt::NoContextMenu);
        settings_WebEngine->setAcceptDrops(false);
        settings_WebEngine->load(QUrl("https://gol.launcher.moe"));
    }
    return settings_WebEngine;
}

void SettingsWindow::show() {
    _tabGeneral->trigger(ri);
    _settingsWindow->show();
}

std::shared_ptr<QWidget> SettingsWindow::getWidget() {
    return _settingsWidget;
}