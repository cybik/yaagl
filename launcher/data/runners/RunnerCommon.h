//
// Created by cybik on 23-02-17.
//

#ifndef QAGL_RUNNERCOMMON_H
#define QAGL_RUNNERCOMMON_H

#include <string>
#include <QNetworkReply>

#include <QJsonDocument>
#include <QJsonObject>

#include <functional>
#include <memory>

class RunnerCommon {
    virtual std::string get_identifier() = 0;
protected:
    void setup(QUrl, std::function<void(QNetworkReply *)>);
    virtual void handle(QNetworkReply*) = 0; // pure virtual
    void parse_in(const QByteArray&);
    std::shared_ptr<QJsonDocument> _doc;

    QString getRootKey();

    QString getRunnerName();

    QString getRunnerURL();

    QString to_string();
private:
    QString _key;
    QJsonObject _metadata;
    QString _name;
    QString _url_upstream;
};


#endif //QAGL_RUNNERCOMMON_H
