#include <QApplication>

#include "launcher/ui/Landing.h"
#include "launcher/about.h"

#include <memory>
#include <stdlib.h>

#include "launcher/data/SettingsData.h"

using namespace QAGL;

static std::shared_ptr<SettingsData> data;

int main(int argc, char *argv[]) {
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication app(argc, argv);

    data = SettingsData::getSettingsData();

    std::string tf;
    if(const char* _tf = std::getenv("SteamTenfoot")) {
        tf = _tf;
    }
    std::string tfh;
    if(const char* _tfh = std::getenv("SteamTenfootHybrid")) {
        tfh = _tfh;
    }

    QAGL::QAGL_App_Style style = QAGL::QAGL_App_Style::Normal;
    if(!tf.empty() || !tfh.empty()) {
        if((tf != tfh) && (tf == "1")) {
            // true 10ft, deck fullscreen experience (not hybrid mode).
            //  Use 10ft unique-window experimental variant
            style = QAGL::QAGL_App_Style::Unique_Window;
        }
    }

    app.setApplicationName(APP_NAME_SHORT);
    app.setOrganizationName(ORG_DOMAIN);
    app.setOrganizationDomain(ORG_DOMAIN);
    app.setApplicationDisplayName(APP_NAME);
    std::unique_ptr<Landing> landing = std::make_unique<Landing>(app, std::move(data),style);
    QPixmap pix;
    pix.loadFromData(QByteArray::fromBase64(qiqi_smol.toLocal8Bit(), QByteArray::Base64Encoding));
    app.setWindowIcon(pix);
    landing->show(app);
    return QApplication::exec();
}
