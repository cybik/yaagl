//
// Created by cybik on 22-02-13.
//

#ifndef QAGL_LANDING_H
#define QAGL_LANDING_H

#include <QMainWindow>
#include <QtWebEngineWidgets/QtWebEngineWidgets>

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

    private:
        void inject_stylesheet();
        void inject_settings();
        void runBackground();

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
        QString generate_url();
        void background_set();

    };
}

class LandingWebEnginePage : public QWebEnginePage
{
Q_OBJECT

public:
    explicit LandingWebEnginePage(QObject* parent = 0) : QWebEnginePage(parent) { }
    bool acceptNavigationRequest(const QUrl & url, QWebEnginePage::NavigationType type, bool) override;

    QWebEnginePage *createWindow(WebWindowType type) override;
};
#endif //QAGL_LANDING_H
