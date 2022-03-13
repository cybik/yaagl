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
            settings_Window = std::make_unique<QMainWindow>();
            settings_Window->setFixedSize(900, 600);
            settings_Window->setWindowTitle("Settings");
            widget_main = std::make_unique<widget_baseline>();
            settings_Window->setCentralWidget(widget_main.get());
            widget_tabs = std::make_unique<widget_section>(widget_main.get());
            widget_tabs->setGeometry(QRect(260, 0, 640, 600));

            add_general();
            add_enhancements();
            add_wines();
            add_dxvks();
            add_shaders();
            add_environment();
            add_misc();
        }
        settings_Window->show();
    }
    void Settings::add_general() {
        common_tab_creation(general_page = std::make_unique<page_general>());
    }
    void Settings::add_enhancements() {
        common_tab_creation(enhancements_page = std::make_unique<page_enhancements>());
    }
    void Settings::add_wines() {
        common_tab_creation(wines_page = std::make_unique<page_wines>());
    }
    void Settings::add_dxvks() {
        common_tab_creation(dxvks_page = std::make_unique<page_dxvks>());
    }
    void Settings::add_shaders() {
        common_tab_creation(shaders_page = std::make_unique<page_shaders>());
    }
    void Settings::add_environment() {
        common_tab_creation(envs_page = std::make_unique<page_env>());
    }
    void Settings::add_misc() {
        common_tab_creation(misc_page = std::make_unique<page_misc>());
    }

    void Settings::common_tab_creation(const std::unique_ptr<IPage>& page) {
        widget_main->ui->listWidget->addItem(page->getPageName());
        widget_tabs->ui->tbxTabs->addItem(page->getPage().get(), page->getPageName());
    }

}
