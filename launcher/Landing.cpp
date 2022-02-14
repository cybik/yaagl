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
    void Landing::background_req(QNetworkReply *) {
        background = std::make_shared<QJsonDocument>(QJsonDocument::fromJson(qnre->readAll()));
        QString back = background->object().find("data").value().toObject()
                                           .find("adv").value().toObject()
                                           .find("background").value().toString();

        qev->page()->runJavaScript("document.body.background = ('"+back+"');");
        qmw->show();
    }

    void Landing::runBackground() {
        qnam = std::make_shared<QNetworkAccessManager>();
        qnr = std::make_shared<QNetworkRequest>(QUrl((backgroundUri+"en-us").c_str()));
        QObject::connect(qnam.get(), SIGNAL(finished(QNetworkReply*)),
                         this, SLOT(background_req(QNetworkReply*))
        );
        qnre = std::shared_ptr<QNetworkReply>(qnam->get(*qnr));
    }

    void Landing::load_finished(bool is) {
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
    void Landing::address_gimme() {
        qDebug() << generate_url().toStdString().c_str();
    }
    Landing::Landing(const QApplication &app) {
        qmw = std::make_shared<QMainWindow>();

        // defaults
        qmw->setFixedSize(1280,720);

        qmnu = std::make_shared<QMenu>("Checks");
        qq = std::shared_ptr<QAction>(qmnu->addAction("Quit"));
        qev = std::make_shared<QWebEngineView>();

        QObject::connect(qq.get(), SIGNAL(triggered()), this, SLOT(quit_clicked()));
        QObject::connect(qev.get(), SIGNAL(loadFinished(bool)), this, SLOT(load_finished(bool)));

        qmw->setCentralWidget(qev.get());
        qmw->menuBar()->addMenu(qmnu.get());

        qmw->setWindowTitle("Yet Another Anime Game Launcher");
    }

    QString Landing::generate_url() {
        return QString("https://").append(placeholders::lowercase::first.c_str()).append(".")
                .append(placeholders::lowercase::company.c_str())
                .append(".com/launcher/10/en-us?api_url=https%3A%2F%2Fapi-os-takumi.")
                .append(placeholders::lowercase::company.c_str())
                .append(".com%2Fhk4e_global&key=gcStgarh&prev=false");
    }

    void Landing::show(const QApplication &app) {
        qev->load(QUrl(generate_url()));
    }
}