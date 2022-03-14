//
// Created by cybik on 22-03-13.
//

#ifndef QAGL_PAGE_GENERAL_H
#define QAGL_PAGE_GENERAL_H

#include <QWidget>

#include "IPage.h"

class page_general : public IPage {
public:
    page_general();

    std::shared_ptr<widget_page> getPage() override;
    QString getPageName() override;

protected:
    std::shared_ptr<widget_page> general_page;
    std::unique_ptr<widget_combo> combo_launcher_lang;
    std::unique_ptr<widget_combo> combo_launcher_theme;
    std::unique_ptr<widget_checkbox> check_discord_go;

    std::unique_ptr<widget_set_section> section_patch;
    std::unique_ptr<widget_set_section> section_patch2;

};

#endif //QAGL_PAGE_GENERAL_H
