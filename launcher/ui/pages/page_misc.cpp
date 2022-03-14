//
// Created by cybik on 22-03-13.
//

#include "page_misc.h"
#include "../elements/ui_widget_checkbox.h"
#include "../elements/ui_widget_combo.h"
#include "../elements/ui_widget_page.h"
#include "../elements/ui_widget_set_section.h"

std::shared_ptr<widget_page> page_misc::getPage() {
    return misc_page;
}

page_misc::page_misc() {
    misc_page = std::make_shared<widget_page>();
}

QString page_misc::getPageName() {
    return "Miscellaneous";
}