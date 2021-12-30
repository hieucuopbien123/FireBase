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
    QNetworkRequest newRequest((QUrl(url)));//con mẹ nó (QUrl(url)) éo được
    newRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    m_networkReply = m_networkAccessManager->post(newRequest, payload.toJson());
    connect(m_networkReply, &QNetworkReply::readyRead, this, &AthHandler::networkReplyReadyRead);
}

void AthHandler::parseResponse(const QByteArray &response)
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(response);
    if(jsonDocument.object().contains("error")){
        //nó éo phải lỗi mà try catch mà vẫn trả lại json object nên phải bắt như này
        qDebug() << "Error occured!" << response;
    }
    else if(jsonDocument.object().contains("kind")){
        QString idToken = jsonDocument.object().value("idToken").toString();
        qDebug() << "Sign in successfully!";
        m_idToken = idToken;//biến bất cứ giá trị nào lấy ở bấy cứ đâu thành global dùng cho mọi hàm của class
        //bằng cách lưu như này
        qDebug() << m_idToken;
        emit userSignedIn();
        //thay vì xử lý nhát gừng ta cho nó phát signal=> bất cứ class nào mà muốn thay đổi gì khi user sign
        //in thì bắt sẽ tốt hơn
    }else{
        qDebug() << "The responses were " << response;
    }
}
//SignIn hay SignUp thì cũng post cái tk, mk vào database trả lại idToken. Lấy idToken nhét vào url và get nó gửi lại uesr
