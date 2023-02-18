//
// Created by cybik on 23-02-17.
//

#ifndef QAGL_COMMON_H
#define QAGL_COMMON_H


#include <QNetworkReply>

class Common {
protected:
    void setup(QUrl, std::function<void(QNetworkReply *)>);
    virtual void handle(QNetworkReply*) = 0; // pure virtual
};


#endif //QAGL_COMMON_H
