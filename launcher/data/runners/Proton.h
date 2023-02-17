//
// Created by cybik on 23-02-16.
//

#ifndef QAGL_PROTON_H
#define QAGL_PROTON_H

#include <string>
#include <memory>


class Proton {
public:
    std::shared_ptr<Proton> get_instance();
private:
    Proton();
    static const std::string _proton_url;

    static std::shared_ptr<Proton> _self;

    void setup();

};


#endif //QAGL_PROTON_H
