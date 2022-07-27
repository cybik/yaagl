//
// Created by cybik on 22-02-13.
//

#include "Landing.h"
#include "util/Constants.h"
#include "resources/stylesheets.h"
#include "resources/SASSProcess.h"

#include <QVBoxLayout>
#include <QWebEngineScript>
#include <QShortcut>

#define YAAGL_SETTINGS "#yaagl-settings"

namespace QAGL {
    void Landing::show_dev() {
        if(!devTools_Window) {
            devTools_Window = std::make_shared<QMainWindow>();
            devTools_Window->setFixedSize(1920, 1080);
            devTools_WebEngine = std::make_shared<QWebEngineView>();
            launcher_WebEngine->page()->setInspectedPage(launcher_WebEngine->page());
            launcher_WebEngine->page()->setDevToolsPage(devTools_WebEngine->page());
            devTools_Window->setCentralWidget(devTools_WebEngine.get());
        }
        devTools_Window->show();
    }

    void Landing::background_set() {
        QString back = background->object().find("data").value().toObject()
                .find("adv").value().toObject()
                .find("background").value().toString();
        launcher_WebEngine->page()->runJavaScript(
            "document.body.background = ('"+back+"');",
            [this](const QVariant& var) {
                networkRequest.reset();
                launcher_Window->show();
            }
        );
    }

    // Final method after getting background URL, load up
    void Landing::background_req(QNetworkReply *reply) {
        background = std::make_shared<QJsonDocument>(QJsonDocument::fromJson(reply->readAll()));
        background_set();
    }

    void Landing::runBackground() {
        if(!background) {
            if(networkLink == nullptr) {
                networkLink = std::make_shared<QNetworkAccessManager>();
                QObject::connect(networkLink.get(), SIGNAL(finished(QNetworkReply *)),
                                 this, SLOT(background_req(QNetworkReply*))
                );
            }
            networkRequest = std::make_shared<QNetworkRequest>(QUrl((backgroundUri + "en-us").c_str()));
            networkLink->get(*networkRequest);
            return;
        }
        background_set();
    }

    void Landing::loaded(bool is) {
        if(is) {
            launcher_WebEngine->page()->runJavaScript(
                "document.getElementsByClassName('home')[0].clientWidth;",
                [this](const QVariant& var) {
                    launcher_Window->setFixedWidth(var.toInt());
                    launcher_WebEngine->page()->runJavaScript(
                        "document.getElementsByClassName('home')[0].clientHeight;",
                        [this](const QVariant& var) {
                            launcher_Window->setFixedHeight(var.toInt());
                            launcher_Window->move(
                                QGuiApplication::primaryScreen()->geometry().center() - launcher_Window->rect().center()
                            );
                            runBackground();
                        }
                    );
                }
            );
        }
    }

    void Landing::inject_stylesheet() {
        if(launcher_WebEngine->page()->scripts().isEmpty() ||
           launcher_WebEngine->page()->scripts().findScript("cpp-sends-their-regards").isNull()
        ) {
            QWebEngineScript script;
            QString s = QString::fromLatin1(
                "(function() {\n" \
                    "css = document.createElement('style'); css.type = 'text/css'; css.id = '%1';\n"\
                    "css.textContent = `%2`;\n"\
                    "document.head.appendChild(css);\n"\
                "})()")
                .arg("cpp-sends-their-regards").arg(SASSProcess(idx_sass.toStdString()).c_str());
            launcher_WebEngine->page()->runJavaScript(s, QWebEngineScript::ApplicationWorld);

            script.setName("cpp-sends-their-regards");
            script.setSourceCode(s);
            script.setInjectionPoint(QWebEngineScript::DocumentReady);
            script.setRunsOnSubFrames(true);
            script.setWorldId(QWebEngineScript::ApplicationWorld);
            launcher_WebEngine->page()->scripts().insert(script);
        }
    }

    void Landing::inject_settings() {
        if(launcher_WebEngine->page()->scripts().isEmpty() ||
           launcher_WebEngine->page()->scripts().findScript("setts").isNull()
        ) {
            QWebEngineScript script;
            QString s = QString::fromLatin1(
                "(function() {\n" \
                    "img_idle = document.createElement('img'); img_idle.src = '%1';\n"\
                    "img_idle.className = 'unactive'; img_idle.alt = 'icon';\n"\
                    "img_hovr = document.createElement('img'); img_hovr.src = '%2';\n"\
                    "img_hovr.className = 'active'; img_hovr.alt = 'icon';\n"\
                    "settings = document.createElement('div'); settings.id = 'settings';\n"\
                    "settings.appendChild(img_idle); settings.appendChild(img_hovr);\n"\
                    "document.body.appendChild(settings);\n"\
                    "const t = document.getElementById(\"settings\");\n"\
                    "t.onclick = () => { t == null || location.assign('%3'); },\n"\
                    "t.onmouseenter = () => { t == null || t.classList.add(\"hovered\"); },\n"\
                    "t.onmouseleave = () => { t == null || t.classList.remove(\"hovered\"); }"\
                "})()").arg(gear_idle.c_str()).arg(gear_hover.c_str()).arg(YAAGL_SETTINGS);
            launcher_WebEngine->page()->runJavaScript(s, QWebEngineScript::ApplicationWorld);

            script.setName("setts");
            script.setSourceCode(s);
            script.setInjectionPoint(QWebEngineScript::DocumentReady);
            script.setRunsOnSubFrames(true);
            script.setWorldId(QWebEngineScript::ApplicationWorld);
            launcher_WebEngine->page()->scripts().insert(script);
        }
    }

    Landing::Landing(const QApplication &app) {
        launcher_Window = std::make_shared<QMainWindow>();

        // defaults
        launcher_Window->setFixedSize(1280, 720 - QApplication::style()->pixelMetric(QStyle::PM_TitleBarHeight));
        launcher_Window->setWindowTitle("Yet Another Anime Game Launcher");

        // Menu
        devTools_Combo = std::make_shared<QShortcut>(QKeySequence(Qt::Key_F12), launcher_Window.get());
        QObject::connect(devTools_Combo.get(), SIGNAL(activated()),
                         this, SLOT(show_dev())
        );

        // Web core
        launcher_WebEngine = std::make_shared<QWebEngineView>();
        launcher_WebEngine->setContextMenuPolicy(Qt::NoContextMenu);
        launcher_WebEngine->setAcceptDrops(false);
        launcher_WebEngine->setPage(
            (new LandingWebEnginePage())
                ->setSettingsLambda([this]() {
                    this->load_settings();
                })
                ->setParentWindow(launcher_Window)
        );
        inject_stylesheet();
        inject_settings();
        QObject::connect(launcher_WebEngine.get(), SIGNAL(loadFinished(bool)),
                         this, SLOT(loaded(bool))
        );

        // Add the web core to the window
        launcher_WidgetStack = std::make_shared<QStackedWidget>(launcher_Window.get());
        launcher_WidgetStack->addWidget(launcher_WebEngine.get());
        /*
        if(settings == nullptr) {
            settings = std::make_shared<SettingsWindow>(launcher_Window.get());
        }
        launcher_WidgetStack->addWidget(settings->getWidget().get());*/
        launcher_Window->setCentralWidget(launcher_WidgetStack.get());
    }

    void Landing::load_settings() {
        if(settings == nullptr) {
            settings = std::make_shared<SettingsWindow>(launcher_Window.get());
        }
        settings->show();
        //launcher_WidgetStack->setCurrentIndex(1);
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
        launcher_WebEngine->load(QUrl(generate_url()));
    }

    QWebEnginePage * LandingWebEnginePage::createWindow(WebWindowType type) {
        return new LandingWebEnginePage();
    }

    bool LandingWebEnginePage::acceptNavigationRequest(const QUrl & url, QWebEnginePage::NavigationType type, bool) {
        if (type == QWebEnginePage::NavigationTypeLinkClicked) {
            QDesktopServices::openUrl(url);
            return false;
        } else if(type == QWebEnginePage::NavigationTypeRedirect && (url.toString().contains(YAAGL_SETTINGS))) {
            qDebug() << "WIP: Settings";
            _parentSettings();
            return false;
        }
        return true;
    }

    LandingWebEnginePage* LandingWebEnginePage::setSettingsLambda(std::function<void()> lambda) {
        _parentSettings = std::move(lambda);
        return this;
    }

    LandingWebEnginePage* LandingWebEnginePage::setParentWindow(std::shared_ptr<QMainWindow> ptr) {
        _parent = ptr;
        return this;
    }
}
