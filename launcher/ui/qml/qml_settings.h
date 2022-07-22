//
// Created by cybik on 22-07-22.
//

#ifndef QAGL_QML_SETTINGS_H
#define QAGL_QML_SETTINGS_H

#include <QQuickView>
#include <memory>

class Settings_QML {
public:
    Settings_QML();
    void show();
private:
    std::shared_ptr<QQuickView> qqv;
};

#endif //QAGL_QML_SETTINGS_H
