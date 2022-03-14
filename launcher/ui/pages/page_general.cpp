//
// Created by cybik on 22-03-13.
//

#include "page_general.h"

#include "../elements/ui_widget_checkbox.h"
#include "../elements/ui_widget_combo.h"
#include "../elements/ui_widget_page.h"
#include "../elements/ui_widget_set_section.h"

std::shared_ptr<widget_page> page_general::getPage() {
    return general_page;
}

page_general::page_general() {
    general_page = std::make_shared<widget_page>();

    combo_launcher_lang = std::make_unique<widget_combo>();
    combo_launcher_lang->ui->lblCombo->setText("Launcher Language");
    general_page->ui->vertThings->addWidget(combo_launcher_lang.get());

    combo_launcher_theme = std::make_unique<widget_combo>();
    combo_launcher_theme->ui->lblCombo->setText("Theme");
    general_page->ui->vertThings->addWidget(combo_launcher_theme.get());

    check_discord_go = std::make_unique<widget_checkbox>();
    check_discord_go->ui->lblCheckbox->setText("Enable Discord RPC");
    general_page->ui->vertThings->addWidget(check_discord_go.get());
    // TODO: show certain options only when this bugger is checked. like, do a subpage and hide it wholesale?


    section_patch = std::make_unique<widget_set_section>();
    section_patch->ui->lblSection->setText("Patch");
    general_page->ui->vertThings->addWidget(section_patch.get());
}

QString page_general::getPageName() {
    return "General";
}
