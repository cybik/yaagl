//
// Created by cybik on 22-07-22.
//

#include "qml_settings.h"

#include "Settings_QML.hpp"

Settings_QML::Settings_QML() {
    qqv = std::make_shared<QQuickView>(QUrl::fromUserInput(QMLd.c_str()));
}

void Settings_QML::show() {
    qqv->show();
}