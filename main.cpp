#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlProperty> //for reading from qml file
#include <QQuickView>
#include "database.h"
#include "DataBaseModel.h"
#include "firebase_database.h"
#include "firebase_auth.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // FirebaseDataBase fbDatabase; //this should be commented out until you make whole class with proper functions for it

    qmlRegisterSingletonType<FirebaseAuth>("FirebaseAuth", 1, 0, "FbAuth", [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        FirebaseAuth *fbAuth = new FirebaseAuth();
        fbAuth->setAPIKey("AIzaSyC5tR1cHCZD80oEyvJeBwVvy-Y_dXI3ODg");
        return fbAuth;
    });

    //we register database as singleton
    qmlRegisterSingletonType<DataBaseModel>("DataBaseModel", 1, 0, "DbModel", [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        DataBaseModel *database = new DataBaseModel();
        return database;
    });

    qRegisterMetaType<Day>();

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
