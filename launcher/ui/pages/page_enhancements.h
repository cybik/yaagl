//
// Created by cybik on 22-03-13.
//

#ifndef QAGL_PAGE_ENHANCEMENTS_H
#define QAGL_PAGE_ENHANCEMENTS_H

#include "IPage.h"

class page_enhancements : public IPage {
public:
    page_enhancements();

    std::shared_ptr<widget_page> getPage() override;
    QString getPageName() override;

protected:
    std::shared_ptr<widget_page> enh_page;

    std::unique_ptr<widget_combo> section_wine;
    std::unique_ptr<widget_combo> section_game;
    std::unique_ptr<widget_combo> section_launcher;

};


#endif //QAGL_PAGE_ENHANCEMENTS_H