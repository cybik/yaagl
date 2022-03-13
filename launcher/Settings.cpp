//
// Created by cybik on 22-02-13.
//

#include "Settings.h"
#include <QApplication>
#include <QAction>
#include "about.h"

#include "ui/ui_widget_baseline.h"
#include "ui/ui_widget_section.h"
#include "ui/elements/ui_widget_checkbox.h"
#include "ui/elements/ui_widget_combo.h"
#include "ui/elements/ui_widget_page.h"

// use macros?
#define ADD_SETTINGS_TAB(X) \
        common_tab_creation("General");

namespace QAGL {
    void Settings::about_clicked() {
        abort();
    }
    Settings::Settings() {
        if(!settings) {
            settings = std::make_unique<QSettings>(new QSettings(
               QSettings::NativeFormat, QSettings::UserScope,QString(ORG_DOMAIN))
            );
        }
        if(!settings_Window) {
            //settings_Window = std::make_unique<WRibbon::MainWindow>(true);
            settings_Window = std::make_unique<QMainWindow>();
            settings_Window->setFixedSize(900, 600);
            settings_Window->setWindowTitle("Settings");
            //settings_Window->setApplicationButtonText("About");
            //QObject::connect(settings_Window->getApplicationButton(), SIGNAL(clicked()), this, SLOT(about_clicked()));
            //settings_Window->m_ribbon->setFixedHeight(32);
            widget_main = std::make_unique<widget_baseline>();
            settings_Window->setCentralWidget(widget_main.get());
            widget_tabs = std::make_unique<widget_section>(widget_main.get());
            widget_tabs->setGeometry(QRect(260, 0, 640, 600));

            add_general();
            add_enhancements();
            //cat_Enhancements_Wine = add_runtimes();
            add_dxvks();
            add_shaders();
            add_environment();
            add_misc();
        }
        settings_Window->show();
    }
    void Settings::add_general() {
        general_page = std::make_unique<widget_page>();
        common_tab_creation("General", general_page);
    }
    void Settings::add_enhancements() {
        enhancements_page = std::make_unique<widget_page>();
        common_tab_creation("Enhancements", enhancements_page);
    }
    void Settings::add_dxvks() {
        dxvks_page = std::make_unique<widget_page>();
        common_tab_creation("DXVK", dxvks_page);
    }
    void Settings::add_shaders() {
        shaders_page = std::make_unique<widget_page>();
        common_tab_creation("Shaders", shaders_page);
    }
    void Settings::add_environment() {
        envs_page = std::make_unique<widget_page>();
        common_tab_creation("Environment", envs_page);
    }
    void Settings::add_misc() {
        misc_page = std::make_unique<widget_page>();
        common_tab_creation("Miscelaneous", misc_page);
    }

    void Settings::common_tab_creation(QString tab_name, const std::unique_ptr<widget_page>& page) {
        widget_main->ui->listWidget->addItem(tab_name);
        widget_tabs->ui->tbxTabs->addItem(page.get(), tab_name);
    }

}
