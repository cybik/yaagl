#include <QApplication>

#include "launcher/Landing.h"

#include "launcher/about.h"

using namespace QAGL;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setApplicationName(APP_NAME_SHORT);
    app.setOrganizationName(ORG_DOMAIN);
    app.setOrganizationDomain(ORG_DOMAIN);
    app.setApplicationDisplayName(APP_NAME);
    std::shared_ptr<Landing> landing = std::make_shared<Landing>(app);
    landing->show(app);
    return QApplication::exec();
}
