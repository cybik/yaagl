//
// Created by cybik on 22-02-13.
//

#include "Landing.h"
#include "util/Constants.h"

#include <QVBoxLayout>
namespace QAGL {
    void Landing::quit_clicked() {
        qmw->close();
    }

    // Final method after getting background URL, load up
    void Landing::background_req(QNetworkReply *reply) {
        background = std::make_shared<QJsonDocument>(QJsonDocument::fromJson(reply->readAll()));
        QString back = background->object().find("data").value().toObject()
                                           .find("adv").value().toObject()
                                           .find("background").value().toString();
        qev->page()->runJavaScript(
            "document.body.background = ('"+back+"');",
            [this](const QVariant& var) {
                qnr.reset();
                qmw->show();
            }
        );
    }

    void Landing::runBackground() {
        if(qnam == nullptr) {
            qnam = std::make_shared<QNetworkAccessManager>();
            QObject::connect(qnam.get(), SIGNAL(finished(QNetworkReply*)),
                             this, SLOT(background_req(QNetworkReply*))
            );
        }
        qnr = std::make_shared<QNetworkRequest>(QUrl((backgroundUri+"en-us").c_str()));
        qnam->get(*qnr);
    }

    void Landing::loaded(bool is) {
        if(is) {
            qev->page()->runJavaScript(
                "document.getElementsByClassName('home')[0].clientWidth;",
                [this](const QVariant& var) {
                    qmw->setFixedWidth(var.toInt());
                    qev->page()->runJavaScript(
                        "document.getElementsByClassName('home')[0].clientHeight;",
                        [this](const QVariant& var) {
                            qmw->setFixedHeight(var.toInt() + qmw->menuBar()->height());
                            qmw->move(QGuiApplication::primaryScreen()->geometry().center() - qmw->rect().center());
                            runBackground();
                        }
                    );
                }
            );
        }
    }

    Landing::Landing(const QApplication &app) {
        qmw = std::make_shared<QMainWindow>();

        // defaults
        qmw->setFixedSize(1280,720);
        qmw->setWindowTitle("Yet Another Anime Game Launcher");

        // Menu
        qmnu = std::make_shared<QMenu>("Checks");
        qq = std::shared_ptr<QAction>(qmnu->addAction("Quit"));
        QObject::connect(qq.get(), SIGNAL(triggered()), this, SLOT(quit_clicked()));
        qmw->menuBar()->addMenu(qmnu.get());

        // Web core
        qev = std::make_shared<QWebEngineView>();
        qev->setContextMenuPolicy(Qt::NoContextMenu);
        qev->setAcceptDrops(false);
        qev->setPage(new LandingWebEnginePage());
        QObject::connect(qev.get(), SIGNAL(loadFinished(bool)), this, SLOT(loaded(bool)));

        // Add the web core to the window
        qmw->setCentralWidget(qev.get());
    }

    QString Landing::generate_url() {
        return QString("https://")
                .append(placeholders::lowercase::first.c_str()).append(".")
                .append(placeholders::lowercase::company.c_str())
                .append(".com/launcher/10/en-us?api_url=https%3A%2F%2Fapi-os-takumi.")
                .append(placeholders::lowercase::company.c_str())
                .append(".com%2Fhk4e_global&key=gcStgarh&prev=false");
    }

    void Landing::show(const QApplication &app) {
        qev->load(QUrl(generate_url()));
    }
}

QWebEnginePage * LandingWebEnginePage::createWindow(WebWindowType type) {
    return new LandingWebEnginePage();
}

bool LandingWebEnginePage::acceptNavigationRequest(const QUrl & url, QWebEnginePage::NavigationType type, bool isMainFrame) {
    if (type == QWebEnginePage::NavigationTypeLinkClicked) {
        //qDebug() << url.toString();
        QDesktopServices::openUrl(url);
        return false;
    }
    return true;
}