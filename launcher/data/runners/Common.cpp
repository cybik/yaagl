//
// Created by cybik on 23-02-17.
//

#include "Common.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>

void Common::setup(QUrl _url, std::function<void(QNetworkReply *)> _func) {
    auto _nam = new QNetworkAccessManager();
    auto _req = new QNetworkRequest(_url);
    QObject::connect(
        _nam, &QNetworkAccessManager::finished, _func
    );
    auto _rep = _nam->get(*_req);
}