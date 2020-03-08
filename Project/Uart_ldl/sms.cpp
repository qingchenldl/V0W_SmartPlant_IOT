#include "sms.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QDebug>
#include <QUrlQuery>

#if 1
// 移动短信接口
QString Sms::_sdkAppId = "qingchenldl";
QString Sms::_sdkAppKey = "208732b6dcdb35dfeb998abeb8a9f9be";
#endif

Sms::Sms(QObject *parent)
    : QObject(parent),
      _random("0"),
      _type("0")
{
    connect(&_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finished(QNetworkReply*)));
    connect(&_manager, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)), this, SLOT(sslErrors(QNetworkReply*,QList<QSslError>)));
}

void Sms::singleMessage(QString mobile, QString content, int type)
{
    QString baseUrl = QString("http://api.sms.cn/sms/");
    QUrl url;
    url.setUrl(baseUrl);
    QUrlQuery urlQuery;
    urlQuery.addQueryItem("ac", "send");
    // 平台账户
    urlQuery.addQueryItem("uid", _sdkAppId);
    // 平台账户接口密码
    urlQuery.addQueryItem("pwd", _sdkAppKey);
    urlQuery.addQueryItem("template", "436689");
    urlQuery.addQueryItem("mobile", mobile);
    urlQuery.addQueryItem("content", QString("{\"name\":\"%1\"}").arg(content));
    url.setQuery(urlQuery);
    _manager.get(QNetworkRequest(url));
}

void Sms::finished(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    qDebug() << __FILE__ << __LINE__ << data;
//#if 1
//    // 移动短信收到的json可以判断是否发送成功，Demo未做这块
//    "{\"stat\":\"100\",\"message\":\"\xB7\xA2\xCB\xCD\xB3\xC9\xB9\xA6\"}"
//#endif
}

void Sms::sslErrors(QNetworkReply *reply, QList<QSslError> list)
{
    qDebug() << __FILE__ << __LINE__ << list;
}
