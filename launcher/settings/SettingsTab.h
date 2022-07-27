//
// Created by cybik on 22-07-24.
//

#ifndef QAGL_SETTINGSTAB_H
#define QAGL_SETTINGSTAB_H

#include <QWidget>
#include <QHBoxLayout>
#include <memory>
#include <RibbonWidget>

class SettingsTab {
public:
    SettingsTab();
    void trigger(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget>);
protected:
    void addTab(std::shared_ptr<Nedrysoft::Ribbon::RibbonWidget>, const QString&);
    std::shared_ptr<QWidget> _tabWidget;
    std::shared_ptr<QHBoxLayout> _tabLayout;
private:
    void _setupRibbonPage();

    int _index = -1;
};


#endif //QAGL_SETTINGSTAB_H
