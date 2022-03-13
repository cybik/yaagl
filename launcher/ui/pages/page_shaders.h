//
// Created by cybik on 22-03-13.
//

#ifndef QAGL_PAGE_SHADERS_H
#define QAGL_PAGE_SHADERS_H

#include "IPage.h"

class page_shaders : public IPage {
public:
    page_shaders();

    std::shared_ptr<widget_page> getPage() override;
    QString getPageName() override;

protected:
    std::shared_ptr<widget_page> shaders_page;

};


#endif //QAGL_PAGE_SHADERS_H
