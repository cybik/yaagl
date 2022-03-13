//
// Created by cybik on 22-03-13.
//

#ifndef QAGL_PAGE_WINES_H
#define QAGL_PAGE_WINES_H

#include "IPage.h"

class page_wines : public IPage {
public:
    page_wines();

    std::shared_ptr<widget_page> getPage() override;
    QString getPageName() override;

protected:
    std::shared_ptr<widget_page> wines_page;
    std::unique_ptr<widget_checkbox> check_show_rec;

};


#endif //QAGL_PAGE_WINES_H
