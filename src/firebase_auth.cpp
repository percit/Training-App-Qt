#include "firebase_auth.h"
#include <QDebug>
#include <QJsonObject>
#include <QNetworkRequest>
#include <QVariantMap>

FirebaseAuth::FirebaseAuth(QObject *parent)
    : QObject(parent), m_APIKey(QString()) {
  m_networkManager = new QNetworkAccessManager(this);
  connect(this, &FirebaseAuth::userSignedIn, this,
          &FirebaseAuth::performAuthenticatedDataBaseCall);
}

FirebaseAuth::~FirebaseAuth() { m_networkManager->deleteLater(); }

void FirebaseAuth::setFirebaseUrl(const QString &firebaseUrl) {
  m_firebaseUrl = firebaseUrl;
}

void FirebaseAuth::signUserUp(const QString &emailAddress,
                              const QString &password) {
  // QString signUpEndpoint =
  // "https://identitytoolkit.googleapis.com/v1/accounts:signUp?key=" +
  // m_APIKey; QVariantMap variantPayload; variantPayload["email"] =
  // emailAddress; variantPayload["password"] = password;
  // variantPayload["returnSecureToken"] = true;
  // qDebug() << emailAddress << ' ' << password;
  // QJsonDocument jsonPayload = QJsonDocument::fromVariant(variantPayload);

  // performPOST(signUpEndpoint, jsonPayload);
}

void FirebaseAuth::signUserIn(const QString &emailAddress,
                              const QString &password) {
  // QString signInEndpoint =
  // "https://identitytoolkit.googleapis.com/v1/accounts:signUp?key=" +
  // m_APIKey; QVariantMap variantPayload; variantPayload["email"] =
  // emailAddress; variantPayload["password"] = password;
  // variantPayload["returnSecureToken"] = true;
  // qDebug() << emailAddress << ' ' << password;
  // QJsonDocument jsonPayload = QJsonDocument::fromVariant(variantPayload);

  // performPOST(signInEndpoint, jsonPayload);
}

void FirebaseAuth::performPOST(const QString &url,
                               const QJsonDocument &payload) {
  QNetworkRequest newRequest((QUrl(url)));
  newRequest.setHeader(QNetworkRequest::ContentTypeHeader,
                       QString("application/json"));
  m_networkReply = m_networkManager->post(newRequest, payload.toJson());
  connect(m_networkReply, &QNetworkReply::readyRead, this,
          &FirebaseAuth::networkReplyReadyRead);
}

void FirebaseAuth::networkReplyReadyRead() {
  QByteArray response = m_networkReply->readAll();
  m_networkReply->deleteLater();

  parseResponse(response);
}

void FirebaseAuth::parseResponse(const QByteArray &response) {
  QJsonDocument jsonDocument = QJsonDocument::fromJson(response);
  if (jsonDocument.object().contains("error")) {
    qWarning() << "ERROR: " << __PRETTY_FUNCTION__ << response;
    setConnectSuccesful(false);
  } else if (jsonDocument.object().contains("kind")) {
    QString idToken = jsonDocument.object().value("idToken").toString();
    //        qDebug() << "id token" << idToken;
    setConnectSuccesful(true);
    m_idToken = idToken;
    emit userSignedIn();
  }
}
void FirebaseAuth::performAuthenticatedDataBaseCall() {
  QString endpoint = m_firebaseUrl + ".json" + m_idToken;
  m_networkReply = m_networkManager->get(QNetworkRequest(QUrl(endpoint)));
  connect(m_networkReply, &QNetworkReply::readyRead, this,
          &FirebaseAuth::networkReplyReadyRead);
}

void FirebaseAuth::setAPIKey(const QString &apiKey) { m_APIKey = apiKey; }

void FirebaseAuth::setConnectSuccesful(bool newConnectSuccesful) {
  m_connectSuccesful = newConnectSuccesful;
  emit connectSuccesfulChanged();
}

bool FirebaseAuth::connectSuccesful() const { return m_connectSuccesful; }
