/**
 * Created by cybik on 22-02-13.5
 * Unused
 **/

#ifndef QAGL_SETTINGS_H
#define QAGL_SETTINGS_H

#include <QMainWindow>
#include <QSettings>

namespace QAGL {
    class Settings : public QObject  {
Q_OBJECT
    public:
        explicit Settings();
    private:
        std::shared_ptr<QSettings> settings;
    };
}

#endif //QAGL_SETTINGS_H
