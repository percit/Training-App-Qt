#ifndef NOTIFICATIONCLIENT_H
#define NOTIFICATIONCLIENT_H
#include <QObject>
#include <QTimer>
#include <QDateTime>
#include <QDebug>

class NotificationClient : public QObject
{
    Q_OBJECT
public:
    explicit NotificationClient(QObject *parent = 0);

    Q_INVOKABLE void setNotification(const QString &notification, int time);
    Q_INVOKABLE void runTest();
    QString notification() const;
    void scheduleNextNotification();

signals:
    void notificationChanged();

private slots:
    void updateAndroidNotification();

private:
    QString m_notification;
    int m_time;
};

#endif // NOTIFICATIONCLIENT_H