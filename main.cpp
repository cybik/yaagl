#include <QApplication>

#include "launcher/Landing.h"

#include "launcher/about.h"

using namespace QAGL;

int main(int argc, char *argv[]) {
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication app(argc, argv);

    app.setApplicationName(APP_NAME_SHORT);
    app.setOrganizationName(ORG_DOMAIN);
    app.setOrganizationDomain(ORG_DOMAIN);
    app.setApplicationDisplayName(APP_NAME);
    std::unique_ptr<Landing> landing = std::make_unique<Landing>(app, QAGL::QAGL_App_Style::Normal);
    QPixmap pix;
    pix.loadFromData(QByteArray::fromBase64(qiqi_smol.toLocal8Bit(), QByteArray::Base64Encoding));
    app.setWindowIcon(pix);
    landing->show(app);
    return QApplication::exec();
}
