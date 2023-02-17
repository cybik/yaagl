//
// Created by cybik on 23-02-16.
//

#include "Proton.h"

#include <QWebEngineHttpRequest>
#include <QWebEnginePage>


const std::string Proton::_proton_url = "https://raw.githubusercontent.com/cybik/yaagl-data/main/runners/proton.json";
std::shared_ptr<Proton> Proton::_self = nullptr;

std::shared_ptr<Proton> Proton::get_instance() {
    if(_self == nullptr) {
        _self.reset(new Proton());
    }
}

void Proton::setup() {
    auto _page = new QWebEnginePage();
    _page->load(QWebEngineHttpRequest(QUrl(_proton_url.c_str()), QWebEngineHttpRequest::Get));
}

Proton::Proton() {
    setup();
}