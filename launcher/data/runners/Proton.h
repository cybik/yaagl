//
// Created by cybik on 23-02-16.
//

#ifndef QAGL_PROTON_H
#define QAGL_PROTON_H

#include <string>
#include <memory>

#include "Common.h"

class Proton : public Common {
public:
    static std::shared_ptr<Proton> get_instance();
protected:
    void handle(QNetworkReply*) override;
private:
    Proton();
    static const std::string _proton_url;

    static std::shared_ptr<Proton> _self;

    void setups();

};


#endif //QAGL_PROTON_H
