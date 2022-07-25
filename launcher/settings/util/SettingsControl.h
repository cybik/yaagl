//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSCONTROL_H
#define QAGL_SETTINGSCONTROL_H

#include <QLayout>

class SettingsControl {
public:
    virtual QLayout* getLayout() = 0;
};

#endif //QAGL_SETTINGSCONTROL_H
