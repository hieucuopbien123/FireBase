#ifndef ATHHANDLER_H
#define ATHHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>

class AthHandler : public QObject
{
    Q_OBJECT
public:
    explicit AthHandler(QObject *parent = nullptr);
    ~AthHandler();
    void setAPIKey(const QString &apiKey);
    void signUserUp(const QString &emailAddress, const QString& password);
    void signUserIn(const QString &emailAddress, const QString& password);

signals:
    void userSignedIn();
public slots:
    void networkReplyReadyRead();
    void performAuthenticatedDatabaseCall();

private:
    void performPOST(const QString url, const QJsonDocument& payload);
    void parseResponse(const QByteArray& response);
    QString m_apiKey;
    QNetworkAccessManager* m_networkAccessManager;
    QNetworkReply* m_networkReply;
    QString m_idToken;
};

#endif // ATHHANDLER_H
