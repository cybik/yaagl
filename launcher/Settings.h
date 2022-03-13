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
#include "ui/elements/widget_checkbox.h"
#include "ui/elements/widget_combo.h"

#include "ui/pages/page_dxvks.h"
#include "ui/pages/page_enhancements.h"
#include "ui/pages/page_env.h"
#include "ui/pages/page_general.h"
#include "ui/pages/page_shaders.h"
#include "ui/pages/page_wines.h"
#include "ui/pages/page_misc.h"

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
        void   add_wines();
        void   add_dxvks();
        void   add_shaders();
        void   add_environment();
        void   add_misc();
        void   common_tab_creation(const std::unique_ptr<IPage>& page);

        //std::unique_ptr<WRibbon::Group> cat_Enhancements_Wine;
        std::unique_ptr<QSettings> settings;
        std::unique_ptr<QMainWindow> settings_Window;
        std::unique_ptr<widget_baseline> widget_main;
        std::unique_ptr<widget_section> widget_tabs;

        std::unique_ptr<IPage> wines_page;
        std::unique_ptr<IPage> dxvks_page;
        std::unique_ptr<IPage> enhancements_page;
        std::unique_ptr<IPage> envs_page;
        std::unique_ptr<IPage> general_page;
        std::unique_ptr<IPage> shaders_page;
        std::unique_ptr<IPage> misc_page;

    };
}

#endif //QAGL_SETTINGS_H
