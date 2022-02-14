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
        void quit_clicked();
        void address_gimme();
        void background_req(QNetworkReply *);
        void load_finished(bool);

    private:
        void runBackground();
        std::shared_ptr<QMainWindow> qmw;
        std::shared_ptr<QWebEngineView> qev;
        std::shared_ptr<QMenu> qmnu;
        std::shared_ptr<QAction> qac;
        std::shared_ptr<QAction> qq;
        QString generate_url();

        std::shared_ptr<QNetworkAccessManager> qnam;
        std::shared_ptr<QNetworkRequest> qnr;
        std::shared_ptr<QNetworkReply> qnre;

        std::shared_ptr<QJsonDocument> background;
    };
}

#endif //QAGL_LANDING_H
