//
// Created by cybik on 22-03-13.
//

#include "page_env.h"
#include "../elements/ui_widget_checkbox.h"
#include "../elements/ui_widget_combo.h"
#include "../elements/ui_widget_page.h"

std::shared_ptr<widget_page> page_env::getPage() {
    return env_page;
}

page_env::page_env() {
    env_page = std::make_shared<widget_page>();
}

QString page_env::getPageName() {
    return "Environment";
}