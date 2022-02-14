#include <QApplication>

#include "launcher/Landing.h"

#include "qtees/test.h"

using namespace QAGL;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    std::shared_ptr<Landing> landing = std::make_shared<Landing>(app);
    landing->show(app);
    return QApplication::exec();
}
