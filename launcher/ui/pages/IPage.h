//
// Created by cybik on 22-03-13.
//

#ifndef QAGL_IPAGE_H
#define QAGL_IPAGE_H

#include <functional>

#include "../elements/widget_page.h"
#include "../elements/widget_combo.h"
#include "../elements/widget_checkbox.h"

class IPage {
public:
    virtual std::shared_ptr<widget_page> getPage() = 0;
    virtual QString getPageName() = 0;
};

#endif //QAGL_IPAGE_H
