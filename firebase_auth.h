#ifndef FIREBASEAUTH_H
#define FIREBASEAUTH_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>

class FirebaseAuth : public QObject
{
    Q_OBJECT

public:
    explicit FirebaseAuth(QObject *parent = nullptr);
    ~FirebaseAuth();

    void setAPIKey(const QString &apiKey);
    void signUserUp(const QString &emailAddress, const QString &password);
    void signUserIn(const QString &emailAddress, const QString &password);

public slots:
    void networkReplyReadyRead();

    void performAuthenticatedDataBaseCall(); // this should be preferably in another class
signals:
    void userSignedIn();

private:
    void performPOST(const QString &url, const QJsonDocument &payload);
    void parseResponse(const QByteArray &response);

    QString m_APIKey;
    QString m_idToken;
    QNetworkAccessManager *m_networkManager;
    QNetworkReply *m_networkReply;
};

#endif // FIREBASEAUTH_H
