/**
 * Created by cybik on 22-02-13.5
 * Unused
 **/

#ifndef QAGL_SETTINGS_H
#define QAGL_SETTINGS_H

#include <QMainWindow>
#include <QSettings>

#include "ui/widget_baseline.h"
#include "ui/widget_section.h"
#include "ui/elements/widget_page.h"

namespace QAGL {
    class Settings : public QObject  {
Q_OBJECT
    public:
        explicit Settings();
    public slots:
        void about_clicked();
    private:
        void   add_general();
        void   add_enhancements();
        void   add_dxvks();
        void   add_shaders();
        void   add_environment();
        void   add_misc();
        void   common_tab_creation(QString tab_name, const std::unique_ptr<widget_page>& page);
        //std::unique_ptr<WRibbon::Group> common_group_creation(QString tab_name);

        //std::unique_ptr<WRibbon::Group> cat_Enhancements_Wine;
        std::unique_ptr<QSettings> settings;
        //std::unique_ptr<WRibbon::MainWindow> settings_Window;
        std::unique_ptr<QMainWindow> settings_Window;
        std::unique_ptr<widget_baseline> widget_main;
        std::unique_ptr<widget_section> widget_tabs;
        std::unique_ptr<widget_page> general_page;
        std::unique_ptr<widget_page> enhancements_page;
        std::unique_ptr<widget_page> dxvks_page;
        std::unique_ptr<widget_page> shaders_page;
        std::unique_ptr<widget_page> envs_page;
        std::unique_ptr<widget_page> misc_page;
    };
}

#endif //QAGL_SETTINGS_H
