//
// Created by cybik on 22-02-13.
//

#ifndef QAGL_LANDING_H
#define QAGL_LANDING_H

#include "resources/gear_image.h"
#include <QMainWindow>
#include <QtWebEngineWidgets/QtWebEngineWidgets>

#include <memory>

#include <functional>
#include "settings/SettingsWindow.h"

namespace QAGL {
    class Landing : public QObject {
Q_OBJECT
    public:
        explicit Landing(const QApplication &app);
        void show(const QApplication &app);

    public slots:
        void background_req(QNetworkReply *);
        void show_dev();
        void loaded(bool);

    protected:
    private:
        Landing() = default;
        void inject_stylesheet();
        void inject_settings();
        void runBackground();

        void load_settings();
        std::shared_ptr<SettingsWindow> settings;

        // Launcher Landing
        std::shared_ptr<QMainWindow> launcher_Window;
        std::shared_ptr<QWebEngineView> launcher_WebEngine;

        // Webkit/Chromium Developer Console
        std::shared_ptr<QMainWindow> devTools_Window;
        std::shared_ptr<QWebEngineView> devTools_WebEngine;
        std::shared_ptr<QShortcut> devTools_Combo;

        // Network requests to our gaming overlords
        std::shared_ptr<QNetworkAccessManager> networkLink;
        std::shared_ptr<QNetworkRequest> networkRequest;

        // JSON - Background Image data
        std::shared_ptr<QJsonDocument> background;

        // Utilities
        static QString generate_url();
        void background_set();
    };

    class LandingWebEnginePage : public QWebEnginePage
    {
Q_OBJECT
    public:
        explicit LandingWebEnginePage(QObject* parent = 0) : QWebEnginePage(parent) { }
        LandingWebEnginePage *setSettingsLambda(std::function<void()>);
        LandingWebEnginePage *setParentWindow(std::shared_ptr<QMainWindow> ptr);
        bool acceptNavigationRequest(const QUrl & url, QWebEnginePage::NavigationType type, bool) override;

        QWebEnginePage *createWindow(WebWindowType type) override;
    private:
        std::shared_ptr<QSettings> fakesettings;
        std::shared_ptr<QMainWindow> _parent;
        std::function<void()> _parentSettings;
    };
}

#endif //QAGL_LANDING_H
