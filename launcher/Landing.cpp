//
// Created by cybik on 22-02-13.
//

#include "Landing.h"
#include "util/Constants.h"
#include "resources/stylesheets.h"
#include "resources/SASSProcess.h"
#include "resources/gear_image.h"

#include <QVBoxLayout>
#include <QWebEngineScript>

namespace QAGL {
    void Landing::quit_clicked() {
        qmw->close();
    }
    void Landing::devtools_clicked() {
        qdt = std::make_shared<QMainWindow>();
        qdt->setFixedSize(1920,1080);
        qevdt = std::make_shared<QWebEngineView>();
        qev->page()->setInspectedPage(qev->page());
        qev->page()->setDevToolsPage(qevdt->page());
        qdt->setCentralWidget(qevdt.get());
        qdt->show();
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
                inject_settings();
                qmw->show();
                devtools_clicked();
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

    void Landing::inject_stylesheet() {
        if( qev->page()->scripts().isEmpty() ||
           qev->page()->scripts().findScript("sass").isNull()
        ) {
            QWebEngineScript script;
            QString s = QString::fromLatin1("(function() {\n" \
                                    "css = document.createElement('style');\n"\
                                    "css.type = 'text/css';\n"\
                                    "css.id = '%1';\n"\
                                    "document.head.appendChild(css);\n"\
                                    "css.textContent = `%2`;\n"\
                                    "})()")
                                        .arg("sass")
                                        .arg(SASSProcess(idx_sass.toStdString()).c_str());
            qev->page()->runJavaScript(s, QWebEngineScript::ApplicationWorld);

            script.setName("sass");
            script.setSourceCode(s);
            script.setInjectionPoint(QWebEngineScript::DocumentReady);
            script.setRunsOnSubFrames(true);
            script.setWorldId(QWebEngineScript::ApplicationWorld);
            qev->page()->scripts().insert(script);
        }
    }
    std::string Landing::get_gear_idle() {
        return std::string("data:image/png;base64,").append(gear_idle);
    }
    std::string Landing::get_gear_hovr() {
        return std::string("data:image/png;base64,").append(gear_hover);
    }

    void Landing::inject_settings() {
        if( qev->page()->scripts().isEmpty() ||
            qev->page()->scripts().findScript("setts").isNull()
        ) {
            QWebEngineScript script;
            QString s = QString::fromLatin1("(function() {\n" \
                                    "img_idle = document.createElement('img');\n"\
                                    "img_idle.src = '%1';\n"\
                                    "img_idle.alt = 'Settings';\n"\
                                    "img_idle.className = 'unactive';\n"\
                                    "img_hovr = document.createElement('img');\n"\
                                    "img_hovr.src = '%2';\n"\
                                    "img_hovr.alt = 'Settings';\n"\
                                    "img_hovr.className = 'active';\n"\
                                    "settings = document.createElement('div');\n"\
                                    "settings.className = '';\n"\
                                    "settings.id = 'settings';\n"\
                                    "settings.appendChild(img_idle);\n"\
                                    "settings.appendChild(img_hovr);\n"\
                                    "document.body.appendChild(settings);\n"\
                                    "})()")
                    .arg(get_gear_idle().c_str())
                    .arg(get_gear_hovr().c_str());
            qev->page()->runJavaScript(s, QWebEngineScript::ApplicationWorld);

            script.setName("setts");
            script.setSourceCode(s);
            script.setInjectionPoint(QWebEngineScript::DocumentReady);
            script.setRunsOnSubFrames(true);
            script.setWorldId(QWebEngineScript::ApplicationWorld);
            qev->page()->scripts().insert(script);
        }
    }

    Landing::Landing(const QApplication &app) {
        qmw = std::make_shared<QMainWindow>();

        // defaults
        qmw->setFixedSize(1280,720);
        qmw->setWindowTitle("Yet Another Anime Game Launcher");

        // Menu
        qmnu = std::make_shared<QMenu>("Checks");
        qd = std::shared_ptr<QAction>(qmnu->addAction("Devtools"));
        qq = std::shared_ptr<QAction>(qmnu->addAction("Quit"));
        QObject::connect(qd.get(), SIGNAL(triggered()), this, SLOT(devtools_clicked()));
        QObject::connect(qq.get(), SIGNAL(triggered()), this, SLOT(quit_clicked()));
        qmw->menuBar()->addMenu(qmnu.get());

        // Web core
        qev = std::make_shared<QWebEngineView>();
        qev->setContextMenuPolicy(Qt::DefaultContextMenu);
        qev->setAcceptDrops(false);
        qev->setPage(new LandingWebEnginePage());
        inject_stylesheet();
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