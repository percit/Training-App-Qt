#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlProperty> //for reading from qml file
#include <QQuickView>
#include "DataBaseModel.h"
#include "firebase_database.h"
#include "firebase_auth.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;


    qmlRegisterSingletonType<FirebaseAuth>("FirebaseAuth", 1, 0, "FbAuth", [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        FirebaseAuth *fbAuth = new FirebaseAuth();
        fbAuth->setAPIKey("AIzaSyC5tR1cHCZD80oEyvJeBwVvy-Y_dXI3ODg");
        fbAuth->signUserIn("test@email.com", "Password123");
        return fbAuth;
    });

    qmlRegisterSingletonType<FirebaseDataBase>("FirebaseDataBase", 1, 0, "FbDatabase", [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        FirebaseDataBase *fbDatabase = new FirebaseDataBase();
        return fbDatabase;
    });

    //we register database as singleton
    qmlRegisterSingletonType<DataBaseModel>("DataBaseModel", 1, 0, "DbModel", [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        DataBaseModel *database = new DataBaseModel();
        return database;
    });

    qmlRegisterSingletonType(QUrl("qrc:/Style.qml"), "StyleSingleton", 1, 0, "Style");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl)
        {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

