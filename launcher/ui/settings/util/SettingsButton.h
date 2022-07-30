//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSBTN_H
#define QAGL_SETTINGSBTN_H

#include "3rdParty/nedrysoft/Ribbon/include/RibbonButton"
#include <string>
#include <QHBoxLayout>
#include <QLabel>
#include <memory>

#include "SettingsControl.h"

class SettingsButton : public SettingsControl {
Q_OBJECT
public:
    explicit SettingsButton(const QString& name);
    QLayout* getLayout() override;
protected:
    void addToLayout() override;
    void setupEventHandlers() override;
private:
    std::shared_ptr<Nedrysoft::Ribbon::RibbonButton> _control;
public slots:
    void onClick(bool);
};


#endif //QAGL_SETTINGSCOMBO_H
