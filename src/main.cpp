#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlProperty> //for reading from qml file
#include <QQuickView>
#include "../inc/database.h"
#include "../inc/DataBaseModel.h"

//this is just for testing
#include "firebase/app.h"
#include "firebase/auth.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;



    //firebase test
    #if defined(__ANDROID__)
    firebase::App* app =
        firebase::App::Create(firebase::AppOptions(), my_jni_env, my_activity);
    #else
    firebase::App* firebase_app = firebase::App::Create(firebase::AppOptions());
    #endif  // defined(__ANDROID__)

//tu sie zakoncza
    firebase::auth::Auth* auth = firebase::auth::Auth::GetAuth(firebase_app);

    auth->SignOut();





    // we register database as singleton
    qmlRegisterSingletonType<DataBaseModel>("DataBaseModel", 1, 0, "DbModel", [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        DataBaseModel *example = new DataBaseModel();
        return example;
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
