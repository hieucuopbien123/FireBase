#include "athhandler.h"
#include <QDebug>
#include <QVariantMap>
#include <QNetworkRequest>
#include <QJsonObject>

AthHandler::AthHandler(QObject *parent) : QObject(parent), m_apiKey(QString())
{
    m_networkAccessManager = new QNetworkAccessManager(this);
    connect(this, &AthHandler::userSignedIn, this, &AthHandler::performAuthenticatedDatabaseCall);
}

AthHandler::~AthHandler()
{
    m_networkAccessManager->deleteLater();
}

void AthHandler::setAPIKey(const QString &apiKey)
{
    m_apiKey = apiKey;
}

void AthHandler::signUserUp(const QString &emailAddress, const QString &password)
{
    QString signupEndpoint = "https://identitytoolkit.googleapis.com/v1/accounts:signUp?key=" + m_apiKey;
    QVariantMap variantPayload;
    variantPayload[ "email" ] = emailAddress;
    variantPayload[ "password" ] = password;
    variantPayload[ "returnSecureToken" ] = true;
    QJsonDocument jsonPayload = QJsonDocument::fromVariant(variantPayload);
    performPOST(signupEndpoint, jsonPayload);
}

void AthHandler::signUserIn(const QString &emailAddress, const QString &password)
{
    QString signInEndpoint = "https://identitytoolkit.googleapis.com/v1/accounts:signInWithPassword?key=" + m_apiKey;
    QVariantMap variantPayload;
    variantPayload[ "email" ] = emailAddress;
    variantPayload[ "password" ] = password;
    variantPayload[ "returnSecureToken" ] = true;
    QJsonDocument jsonPayload = QJsonDocument::fromVariant(variantPayload);
    performPOST(signInEndpoint, jsonPayload);
}

void AthHandler::networkReplyReadyRead()
{
    QByteArray response = m_networkReply->readAll();
    m_networkReply->deleteLater();

    parseResponse(response);
}

void AthHandler::performAuthenticatedDatabaseCall()
{
    QString endPoint = "https://hypnotic-surge-324514-default-rtdb.firebaseio.com/Pets.json?auth=" + m_idToken;
    m_networkReply = m_networkAccessManager->get(QNetworkRequest(QUrl(endPoint)));
    connect(m_networkReply, &QNetworkReply::readyRead, this, &AthHandler::networkReplyReadyRead);
}

void AthHandler::performPOST(const QString url, const QJsonDocument &payload)
{
    QNetworkRequest newRequest((QUrl(url)));//con m??? n?? (QUrl(url)) ??o ???????c
    newRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    m_networkReply = m_networkAccessManager->post(newRequest, payload.toJson());
    connect(m_networkReply, &QNetworkReply::readyRead, this, &AthHandler::networkReplyReadyRead);
}

void AthHandler::parseResponse(const QByteArray &response)
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(response);
    if(jsonDocument.object().contains("error")){
        //n?? ??o ph???i l???i m?? try catch m?? v???n tr??? l???i json object n??n ph???i b???t nh?? n??y
        qDebug() << "Error occured!" << response;
    }
    else if(jsonDocument.object().contains("kind")){
        QString idToken = jsonDocument.object().value("idToken").toString();
        qDebug() << "Sign in successfully!";
        m_idToken = idToken;//bi???n b???t c??? gi?? tr??? n??o l???y ??? b???y c??? ????u th??nh global d??ng cho m???i h??m c???a class
        //b???ng c??ch l??u nh?? n??y
        qDebug() << m_idToken;
        emit userSignedIn();
        //thay v?? x??? l?? nh??t g???ng ta cho n?? ph??t signal=> b???t c??? class n??o m?? mu???n thay ?????i g?? khi user sign
        //in th?? b???t s??? t???t h??n
    }else{
        qDebug() << "The responses were " << response;
    }
}
//SignIn hay SignUp th?? c??ng post c??i tk, mk v??o database tr??? l???i idToken. L???y idToken nh??t v??o url v?? get n?? g???i l???i uesr
