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
        void devtools_clicked();
        void background_req(QNetworkReply *);
        void loaded(bool);

    private:
        void inject_stylesheet();
        void inject_settings();
        void runBackground();
        std::shared_ptr<QMainWindow> qmw;
        std::shared_ptr<QMainWindow> qdt;
        std::shared_ptr<QWebEngineView> qev;
        std::shared_ptr<QWebEngineView> qevdt;
        std::shared_ptr<QShortcut> qdk;
        QString generate_url();

        std::shared_ptr<QNetworkAccessManager> qnam;
        std::shared_ptr<QNetworkRequest> qnr;

        std::shared_ptr<QJsonDocument> background;
    };
}

class LandingWebEnginePage : public QWebEnginePage
{
Q_OBJECT

public:
    explicit LandingWebEnginePage(QObject* parent = 0) : QWebEnginePage(parent) { }
    bool acceptNavigationRequest(const QUrl & url, QWebEnginePage::NavigationType type, bool isMainFrame) override;

    QWebEnginePage *createWindow(WebWindowType type) override;
};
#endif //QAGL_LANDING_H
