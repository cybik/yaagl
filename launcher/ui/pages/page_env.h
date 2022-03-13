//
// Created by cybik on 22-03-13.
//

#ifndef QAGL_PAGE_ENV_H
#define QAGL_PAGE_ENV_H

#include "IPage.h"

class page_env : public IPage {
public:
    page_env();

    std::shared_ptr<widget_page> getPage() override;
    QString getPageName() override;

protected:
    std::shared_ptr<widget_page> env_page;

};


#endif //QAGL_PAGE_ENV_H
