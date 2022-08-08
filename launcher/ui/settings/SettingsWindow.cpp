//
// Created by cybik on 22-07-24.
//

#include "SettingsWindow.h"

#include <QEvent>
#include <iostream>

SettingsWindow::SettingsWindow(bool usedAsWidget, QWidget* parent) {
    _settingsWindow = std::make_shared<QMainWindow>(parent);
    _settingsWindow->setWindowTitle("QAGL Settings");

    _settingsWindow->setFixedSize(800,580);
    _settingsWindow->setWindowModality(Qt::ApplicationModal);

    _settingsLayout = std::make_shared<QVBoxLayout>(parent);
    _settingsLayout->setContentsMargins(0,0,0,0);
    _settingsLayout->setSpacing(0);
    _settingsLayout->addWidget(setup(usedAsWidget).get());
    _settingsLayout->addWidget(setupGol(usedAsWidget).get());
    _settingsWidget = std::make_shared<QWidget>(parent);
    _settingsWidget->setLayout(_settingsLayout.get());
    _settingsWindow->setCentralWidget(_settingsWidget.get());
}

void SettingsWindow::onTabBarClicked(int tab_index) {
    if(_tabButtonBack && _tabButtonBack->indexMatches(tab_index)) {
        exit_settings();
    }
}

std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget> SettingsWindow::setup(bool usedAsWidget) {
    if(ri == nullptr) {
        ri = std::make_shared<Nedrysoft::Ribbon::RibbonWidget>();
        if(usedAsWidget) {
            // add back arrow.
            _tabButtonBack = std::make_shared<SettingsTabButtonBack>(ri);
            //ri->tabBar()->installEventFilter(this);
            connect(
                ri->tabBar(), SIGNAL(tabBarClicked(int)),
                this, SLOT(onTabBarClicked(int))
            );
        }
        _tabGeneral = std::make_shared<SettingsTabGeneral>(ri);
        _tabGame = std::make_shared<SettingsTabGame>(ri);
        _tabRunner = std::make_shared<SettingsTabRunner>(ri);
        _tabEnhancements = std::make_shared<SettingsTabEnhancements>(ri);
        _tabMore = std::make_shared<SettingsTabMore>(ri);
        ri->setFixedHeight(ri->height() + 30);
    }
    ri->tabBar()->setCurrentIndex(_tabGeneral->getIndex());

    return ri;
}

std::shared_ptr<QWebEngineView> SettingsWindow::setupGol(bool usedAsWidget) {
    if(settings_WebEngine == nullptr) {
        settings_WebEngine = std::make_shared<QWebEngineView>();
        settings_WebEngine->setContextMenuPolicy(Qt::NoContextMenu);
        settings_WebEngine->setAcceptDrops(false);
        settings_WebEngine->load(QUrl("https://gol.launcher.moe"));
    }
    return settings_WebEngine;
}

void SettingsWindow::showing() {
    ri->tabBar()->setCurrentIndex(_tabGeneral->getIndex());
}

void SettingsWindow::show() {
    _settingsWindow->show();
}

std::shared_ptr<QWidget> SettingsWindow::getWidget() {
    return _settingsWidget;
}

void SettingsWindow::setConfig(std::shared_ptr<SettingsData> ptr) {
    _config = ptr;
    if(ptr) {
        std::cout << _config->to_string() << std::endl;
    }
}
