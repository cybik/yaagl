//
// Created by cybik on 22-03-13.
//

#ifndef QAGL_PAGE_MISC_H
#define QAGL_PAGE_MISC_H

#include "IPage.h"


class page_misc : public IPage {
public:
    page_misc();

    std::shared_ptr<widget_page> getPage() override;
    QString getPageName() override;

protected:
    std::shared_ptr<widget_page> misc_page;
};


#endif //QAGL_PAGE_MISC_H
