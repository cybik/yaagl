//
// Created by cybik on 22-02-13.
//

#include "Settings.h"
#include <QApplication>
#include "about.h"

namespace QAGL {
    Settings::Settings() {
        settings = std::make_shared<QSettings>(new QSettings(
                QSettings::NativeFormat, QSettings::UserScope,QString(ORG_DOMAIN)
            )
        );

    }

}
