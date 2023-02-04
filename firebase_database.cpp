#include "firebase_database.h"
#include <QDebug>
#include <QNetworkRequest>
#include <QVariantMap>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

FirebaseDataBase::FirebaseDataBase(QObject *parent) : QObject(parent)
{
    qDebug() << "created FirebaseDataBase constructor";
    m_networkManager = new QNetworkAccessManager(this);
}

FirebaseDataBase::~FirebaseDataBase()
{
    m_networkManager->deleteLater();
}

void FirebaseDataBase::networkReplyReadyRead()
{
    QString strReply = (QString)m_networkReply->readAll();
    qDebug() << "strreply" << strReply;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
    QJsonObject jsonObj = jsonResponse.object();
    QVariantMap map = jsonObj.toVariantMap();
    m_longestDistance = map["longestDistance"].toInt();
    m_longestDuration = map["longestDuration"].toInt();
    m_bestPace = map["bestPace"].toInt();
    m_weeklyGoal = map["weeklyGoal"].toInt();
    m_dailyGoal = map["dailyGoal"].toInt();
    qDebug() << longestDistance();
    qDebug() << longestDuration();
    qDebug() << bestPace();
    qDebug() << weeklyGoal();
    qDebug() << dailyGoal();

    m_networkReply->deleteLater();
}

void FirebaseDataBase::testFirebaseFunc()
{
    m_networkReply = m_networkManager->get(QNetworkRequest(QUrl("https://running-app-fd699-default-rtdb.europe-west1.firebasedatabase.app/Run.json")));
    if (m_networkReply->error() == QNetworkReply::NoError) {
        connect(m_networkReply, &QNetworkReply::readyRead, this, &FirebaseDataBase::networkReplyReadyRead);
    }
    else {
        qWarning() << "ERROR: " << __PRETTY_FUNCTION__ << m_networkReply->errorString();
    }
}

void FirebaseDataBase::readFirebaseData(const QString& mailName)
{
    m_networkReply = m_networkManager->get(QNetworkRequest(QUrl("https://running-app-fd699-default-rtdb.europe-west1.firebasedatabase.app/" + mailName +".json")));
    if (m_networkReply->error() == QNetworkReply::NoError) {
        connect(m_networkReply, &QNetworkReply::readyRead, this, &FirebaseDataBase::networkReplyReadyRead);
    }
    else {
        qWarning() << "ERROR: " << __PRETTY_FUNCTION__ << m_networkReply->errorString();
    }
}

void FirebaseDataBase::postValues(const QString& mailName)
{
    QVariantMap newRun;
    newRun["longestDistance"] = m_longestDistance;
    newRun["longestDuration"] = m_longestDuration;
    newRun["bestPace"] = m_bestPace;
    newRun["weeklyGoal"] = m_weeklyGoal;
    newRun["dailyGoal"] = m_dailyGoal;
    QJsonDocument jsonDoc = QJsonDocument::fromVariant(newRun);
    QNetworkRequest newRunRequest(QUrl("https://running-app-fd699-default-rtdb.europe-west1.firebasedatabase.app/"+mailName+".json"));
    newRunRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    m_networkManager->post(newRunRequest, jsonDoc.toJson());
    putValues(mailName); //this is a bit of a hack, bc firebase produces some weird string, that I don't want rn TODO: find solution when free time
}

void FirebaseDataBase::putValues(const QString& mailName)
{
    QVariantMap newRun;
    newRun["longestDistance"] = m_longestDistance;
    newRun["longestDuration"] = m_longestDuration;
    newRun["bestPace"] = m_bestPace;
    newRun["weeklyGoal"] = m_weeklyGoal;
    newRun["dailyGoal"] = m_dailyGoal;
    QJsonDocument jsonDoc = QJsonDocument::fromVariant(newRun);
    QNetworkRequest newRunRequest(QUrl("https://running-app-fd699-default-rtdb.europe-west1.firebasedatabase.app/"+mailName+".json"));
    newRunRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    m_networkManager->put(newRunRequest, jsonDoc.toJson());
}

int FirebaseDataBase::longestDistance()
{
    return m_longestDistance;
}

int FirebaseDataBase::longestDuration()
{
    return m_longestDuration;
}

int FirebaseDataBase::bestPace()
{
    return m_bestPace;
}

int FirebaseDataBase::weeklyGoal()
{
    return m_weeklyGoal;
}

int FirebaseDataBase::dailyGoal()
{
    return m_dailyGoal;
}

void FirebaseDataBase::setLongestDistance(int newLongestDistance)
{
    m_longestDistance = newLongestDistance;
    emit longestDistanceChanged();
}

void FirebaseDataBase::setLongestDuration(int newLongestDuration)
{
    m_longestDuration = newLongestDuration;
    emit longestDurationChanged();
}

void FirebaseDataBase::setBestPace(int newBestPace)
{
    m_bestPace = newBestPace;
    emit bestPaceChanged();
}

void FirebaseDataBase::setWeeklyGoal(int newWeeklyGoal)
{
    m_weeklyGoal = newWeeklyGoal;
    emit weeklyGoalChanged();
}

void FirebaseDataBase::setDailyGoal(int newDailyGoal)
{
    m_dailyGoal = newDailyGoal;
    emit dailyGoalChanged();
}
