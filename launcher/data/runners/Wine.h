//
// Created by cybik on 23-02-16.
//

#ifndef QAGL_WINE_H
#define QAGL_WINE_H

#include <string>
#include <memory>

#include "Common.h"

class Wine : public Common {
public:
    static std::shared_ptr<Wine> get_instance();
protected:
    void handle(QNetworkReply*) override;
private:
    Wine();
    static const std::string _wine_url;

    static std::shared_ptr<Wine> _self;

    void setups();

};


#endif //QAGL_PROTON_H
