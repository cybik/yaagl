//
// Created by cybik on 22-03-13.
//

#include "page_wines.h"
#include "../elements/ui_widget_checkbox.h"
#include "../elements/ui_widget_combo.h"
#include "../elements/ui_widget_page.h"
#include "../elements/ui_widget_set_section.h"

std::shared_ptr<widget_page> page_wines::getPage() {
    return wines_page;
}

page_wines::page_wines() {
    wines_page = std::make_shared<widget_page>();
    check_show_rec = std::make_unique<widget_checkbox>();
    check_show_rec->ui->lblCheckbox->setText("Show recommended only");
    wines_page->ui->vertThings->addWidget(check_show_rec.get());
}

QString page_wines::getPageName() {
    return "Wine version";
}
