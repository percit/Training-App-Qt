#ifndef FIREBASEDATABASE_H
#define FIREBASEDATABASE_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class FirebaseDataBase : public QObject
{
    Q_OBJECT

public:
    explicit FirebaseDataBase(QObject *parent = nullptr);
    ~FirebaseDataBase();
public slots:
    void networkReplyReadyRead();
signals:

private:
    QNetworkAccessManager *m_networkManager;
    QNetworkReply *m_networkReply;
};

#endif // FIREBASEDATABASE_H
