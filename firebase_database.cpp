#include "firebase_database.h"
#include <QDebug>
#include <QNetworkRequest>
#include <QVariantMap>
#include <QJsonDocument>

FirebaseDataBase::FirebaseDataBase(QObject *parent) : QObject(parent)
{
    qDebug() << "created FirebaseDataBase constructor";
    m_networkManager = new QNetworkAccessManager(this);


//GET
    //m_networkReply = m_networkManager->get(QNetworkRequest(QUrl("<>.json"))); adding url for rest api
    connect(m_networkReply, &QNetworkReply::readyRead, this, &FirebaseDataBase::networkReplyReadyRead);

//POST
    // QVariantMap newRun;
    // newRun["Km"] = 5;
    // newRun["Time"] = 12000;
    // QJsonDocument jsonDoc = QJsonDocument::fromVariant(newRun);
    // // QNetworkRequest newRunRequest(QUrl("<>.json"))
    // newRunRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    // m_networkManager->post(newRunRequest, jsonDoc.toJson());
	//if you want to use PUT (so to replace values) you just change Run.json to more specific table, and use m_networkManager->put
}

FirebaseDataBase::~FirebaseDataBase()
{
    m_networkManager->deleteLater();
}

void FirebaseDataBase::networkReplyReadyRead()
{
    qDebug() << m_networkReply->readAll();
}
