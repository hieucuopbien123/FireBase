#include "databasehandler.h"
#include <QDebug>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QVariantMap>

DatabaseHandler::DatabaseHandler(QObject* parent): QObject(parent)
{
    m_networkManager = new QNetworkAccessManager(this);
    //cái openssl vào chạy ngon
    //get
    m_networkReply = m_networkManager->get(
                    QNetworkRequest(QUrl("https://hypnotic-surge-324514-default-rtdb.firebaseio.com/Pets/One/Name.json"))
                );
    connect(m_networkReply, &QNetworkReply::readyRead, this, &DatabaseHandler::networkReplyReadyRead);
    //post
//    QVariantMap newPet;
//    newPet[ "Type" ] = "Dog";
//    newPet[ "Name" ] = "Mercy";
//    newPet[ "Food" ] = "Pate";
//    QJsonDocument jsonDoc = QJsonDocument::fromVariant(newPet);

//    QNetworkRequest newPetRequest(QUrl("https://hypnotic-surge-324514-default-rtdb.firebaseio.com/Pets/One/Name.json"));
//    newPetRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
//    m_networkManager->post(newPetRequest, jsonDoc.toJson());
    //put
//    QVariantMap newPet;
//    newPet[ "Type" ] = "What";
//    newPet[ "Name" ] = "Mercy";
//    newPet[ "Food" ] = "Pate";
//    QJsonDocument jsonDoc = QJsonDocument::fromVariant(newPet);

//    QNetworkRequest newPetRequest(QUrl("https://hypnotic-surge-324514-default-rtdb.firebaseio.com/Pets/One.json"));
//    newPetRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
//    m_networkManager->put(newPetRequest, jsonDoc.toJson());
}

DatabaseHandler::~DatabaseHandler()
{
    m_networkManager->deleteLater();
}

void DatabaseHandler::networkReplyReadyRead()
{
    qDebug() << m_networkReply->readAll();
}
