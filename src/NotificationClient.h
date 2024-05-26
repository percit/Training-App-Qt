#ifndef NOTIFICATIONCLIENT_H
#define NOTIFICATIONCLIENT_H

#include <QObject>


class NotificationClient : public QObject
{
    Q_OBJECT
public:
    explicit NotificationClient(QObject *parent = 0);

    Q_INVOKABLE void setNotification(const QString &notification, int time);
    QString notification() const;

signals:
    void notificationChanged();

private slots:
    void updateAndroidNotification();

private:
    QString m_notification;
};

#endif // NOTIFICATIONCLIENT_H

//todo this is not tested, taken from here: https://doc.qt.io/qt-6/qtcore-platform-androidnotifier-example.html