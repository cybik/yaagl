//
// Created by cybik on 22-03-13.
//

#include "page_enhancements.h"
#include "../elements/ui_widget_checkbox.h"
#include "../elements/ui_widget_combo.h"
#include "../elements/ui_widget_page.h"

std::shared_ptr<widget_page> page_enhancements::getPage() {
    return enh_page;
}

page_enhancements::page_enhancements() {
    enh_page = std::make_shared<widget_page>();
}

QString page_enhancements::getPageName() {
    return "Enhancements";
}