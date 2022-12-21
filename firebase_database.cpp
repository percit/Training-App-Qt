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


//POST
    // QVariantMap newRun;
    // newRun["Km"] = 5;
    // newRun["Time"] = 12000;
    // QJsonDocument jsonDoc = QJsonDocument::fromVariant(newRun);
    // // QNetworkRequest newRunRequest(QUrl("<>"))
    // QNetworkRequest newRunRequest(QUrl("https://running-app-fd699-default-rtdb.europe-west1.firebasedatabase.app/Run.json"));
    // newRunRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    // m_networkManager->post(newRunRequest, jsonDoc.toJson());
	// // if you want to use PUT (so to replace values) you just change Run.json to more specific table, and use m_networkManager->put
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
    m_weeklyKmRun = map["weeklyKmRun"].toInt();
    m_longestDistance = map["longestDistance"].toInt();
    m_longestDuration = map["longestDuration"].toInt();
    m_bestPace = map["bestPace"].toInt();
    m_averageDuration = map["averageDuration"].toInt();
    m_allDuration = map["allDuration"].toInt();
    m_weeklyGoal = map["weeklyGoal"].toInt();
    m_dailyGoal = map["dailyGoal"].toInt();
    qDebug() << weeklyKmRun();
    qDebug() << longestDistance();
    qDebug() << longestDuration();
    qDebug() << bestPace();
    qDebug() << averageDuration();
    qDebug() << allDuration();
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
        qDebug() << "Failure" <<m_networkReply->errorString();
    }
}

void FirebaseDataBase::testFirebaseFuncWithMail(const QString& mailName)
{
    m_networkReply = m_networkManager->get(QNetworkRequest(QUrl("https://running-app-fd699-default-rtdb.europe-west1.firebasedatabase.app/" + mailName +".json")));
    if (m_networkReply->error() == QNetworkReply::NoError) {
        connect(m_networkReply, &QNetworkReply::readyRead, this, &FirebaseDataBase::networkReplyReadyRead);
    }
    else {
        qDebug() << "Failure" <<m_networkReply->errorString();
    }
}

int FirebaseDataBase::weeklyKmRun()
{
    return m_weeklyKmRun;
}

void FirebaseDataBase::setWeeklyKmRun(int newWeeklyKmRun) {
    m_weeklyKmRun = newWeeklyKmRun;
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

int FirebaseDataBase::averageDuration()
{
    return m_averageDuration;
}

int FirebaseDataBase::allDuration()
{
    return m_allDuration;
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

void FirebaseDataBase::setAverageDuration(int newAverageDuration)
{
    m_averageDuration = newAverageDuration;
    emit averageDurationChanged();
}

void FirebaseDataBase::setAllDuration(int newAllDuration)
{
    m_allDuration = newAllDuration;
    emit allDurationChanged();
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

//to networkReply->readAll() to chyba jest to cos, co mozna wyciagnac info jakies


//mam pare pomyslow
//na firebase sa tylko rekordy, daily i weekly
//update tych wartosci zachodzi raz dziennie, o polnocy


//co do kont to moge dac maila jako argument funkcji
//a potem na bazie tego robic url 
//a nazwe konta przetrzymywac w sql
//zamiast run.json bedzie np nazwa_maila.json, ale ucinam tylko to az to @

