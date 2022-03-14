//
// Created by cybik on 22-03-13.
//

#include "page_shaders.h"
#include "../elements/ui_widget_checkbox.h"
#include "../elements/ui_widget_combo.h"
#include "../elements/ui_widget_page.h"
#include "../elements/ui_widget_set_section.h"

std::shared_ptr<widget_page> page_shaders::getPage() {
    return shaders_page;
}

page_shaders::page_shaders() {
    shaders_page = std::make_shared<widget_page>();
}

QString page_shaders::getPageName() {
    return "Shaders";
}