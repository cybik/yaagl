//
// Created by cybik on 23-02-17.
//

#include "RunnerCommon.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <QJsonArray>
#include <QJsonObject>
#include <iostream>

void RunnerCommon::setup(QUrl _url, std::function<void(QNetworkReply *)> _func) {
    auto _nam = new QNetworkAccessManager();
    auto _req = new QNetworkRequest(_url);
    QObject::connect(
        _nam, &QNetworkAccessManager::finished, _func
    );
    auto _rep = _nam->get(*_req);
}

void RunnerCommon::parse_in(const QByteArray& array) {
    _doc = std::make_shared<QJsonDocument>(QJsonDocument::fromJson(array));

    _key = (*_doc)["id"].toString();
    _metadata = (*_doc)["metadata"].toObject();
    _name = _metadata["name"].toString();
    _url_upstream = _metadata["url"].toString();;
}

QString RunnerCommon::to_string() {
    return (getRootKey() + " - " + getRunnerName() + " - " + getRunnerURL());
}

QString RunnerCommon::getRootKey() {
    return _key;
}

QString RunnerCommon::getRunnerName() {
    return _name;
}

QString RunnerCommon::getRunnerURL() {
    return _url_upstream;
}
