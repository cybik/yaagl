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
};

#endif //QAGL_PAGE_GENERAL_H
