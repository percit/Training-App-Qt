#include "NotificationClient.h"
#ifdef Q_OS_ANDROID
#include <QtCore/qjniobject.h>
#include <QtCore/qcoreapplication.h>
#include <QtCore/private/qandroidextras_p.h>
#endif
#include <QTimer>
#include <QDateTime>
#include <QDebug>

using namespace Qt::StringLiterals;

NotificationClient::NotificationClient(QObject *parent)
    : QObject(parent)
{
#ifdef Q_OS_ANDROID
    if (QNativeInterface::QAndroidApplication::sdkVersion() >= __ANDROID_API_T__) {
        const auto notificationPermission = "android.permission.POST_NOTIFICATIONS"_L1;
        auto requestResult = QtAndroidPrivate::requestPermission(notificationPermission);
        if (requestResult.result() != QtAndroidPrivate::Authorized) {
            qWarning() << "Failed to acquire permission to post notifications "
                          "(required for Android 13+)";
        }
    }
#endif
}

void NotificationClient::setNotification(const QString &notification, int time)
{
    if (m_notification == notification)
        return;

    m_notification = notification;

    QDateTime currentTime = QDateTime::currentDateTime();
    QDateTime targetTime = QDateTime(currentTime.date(), QTime(time, 0));
    if (currentTime > targetTime) {
        targetTime = targetTime.addDays(1);
    }
    qint64 delay = currentTime.msecsTo(targetTime);
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    QObject::connect(timer, &QTimer::timeout, this, &NotificationClient::updateAndroidNotification);
    timer->start(delay);
    emit notificationChanged();
}

QString NotificationClient::notification() const
{
    return m_notification;
}

void NotificationClient::updateAndroidNotification()
{
#ifdef Q_OS_ANDROID
    QJniObject javaNotification = QJniObject::fromString(m_notification);
    QJniObject::callStaticMethod<void>(
                    "org/qtproject/example/androidnotifier/NotificationClient",
                    "notify",
                    "(Landroid/content/Context;Ljava/lang/String;)V",
                    QNativeInterface::QAndroidApplication::context(),
                    javaNotification.object<jstring>());
#endif
}