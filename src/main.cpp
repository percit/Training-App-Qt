#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlProperty> //for reading from qml file
#include <QQuickView>
#include "DataBaseModel.h"
#include "firebase_database.h"
#include "firebase_auth.h"

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

    qmlRegisterSingletonType<FirebaseAuth>("FirebaseAuth", 1, 0, "FbAuth", [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        FirebaseAuth *fbAuth = new FirebaseAuth();
        // fbAuth->setAPIKey("firebase console,auth, api key");
        // fbAuth->setFirebaseUrl("firebaseURL from firebase auth console");
        // fbAuth->signUserIn("test", "Password123");
        return fbAuth;
    });

    qmlRegisterSingletonType<FirebaseDataBase>("FirebaseDataBase", 1, 0, "FbDatabase", [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        FirebaseDataBase *fbDatabase = new FirebaseDataBase();
        fbDatabase->setFirebaseUrl("firebaseURL from firebase database console");
        // fbDatabase->setDailyGoal(5); //testing, everything works
        // fbDatabase->putValues("test");
        // fbDatabase->readFirebaseData("test");
        
        return fbDatabase;
    });

    //we register database as singleton
    qmlRegisterSingletonType<DataBaseModel>("DataBaseModel", 1, 0, "DbModel", [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        DataBaseModel *database = new DataBaseModel();
        return database;
    });

  qmlRegisterSingletonType(QUrl("qrc:/Style.qml"), "StyleSingleton", 1, 0,
                           "Style");

    QQuickView view;
    view.connect(view.engine(), &QQmlEngine::quit, &app, &QCoreApplication::quit);
    view.setSource(QUrl("qrc:/main.qml"));
    if (view.status() == QQuickView::Error)
        return -1;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}

