//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSCONTROL_H
#define QAGL_SETTINGSCONTROL_H

#include <QLayout>
#include <QFormLayout>
#include <string>
#include <RibbonGroup>
#include <memory>

class SettingsControl {
public:
    explicit SettingsControl(const QString&);
    virtual QLayout* getLayout() = 0;

    void finalize();
protected:
    virtual void addToLayout() = 0;
    std::shared_ptr<QGridLayout> _layout;
    std::shared_ptr<QFormLayout> _formLayout;

    QString _name;
};

#endif //QAGL_SETTINGSCONTROL_H
