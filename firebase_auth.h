#ifndef FIREBASEAUTH_H
#define FIREBASEAUTH_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>

class FirebaseAuth : public QObject
{
    Q_OBJECT


    Q_PROPERTY(bool connectSuccesful READ connectSuccesful WRITE setConnectSuccesful NOTIFY connectSuccesfulChanged)
public:
    explicit FirebaseAuth(QObject *parent = nullptr);
    ~FirebaseAuth();

    void setAPIKey(const QString &apiKey);
    bool connectSuccesful() const;
    void setConnectSuccesful(const bool newConnectSuccesful);

    Q_INVOKABLE void signUserUp(const QString &emailAddress, const QString &password);
    Q_INVOKABLE void signUserIn(const QString &emailAddress, const QString &password);

public slots:
    void networkReplyReadyRead();
    void performAuthenticatedDataBaseCall(); // this should be preferably in another class

signals:
    void userSignedIn();
    void connectSuccesfulChanged();

private:
    void performPOST(const QString &url, const QJsonDocument &payload);
    void parseResponse(const QByteArray &response);

    QString m_APIKey;
    QString m_idToken;
    bool m_connectSuccesful = false;
    QNetworkAccessManager *m_networkManager;
    QNetworkReply *m_networkReply;
};

#endif // FIREBASEAUTH_H
