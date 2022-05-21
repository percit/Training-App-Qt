#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "database.h"
#include "DataBaseModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    //    DataBase db("database9.db");
    //    if (db.isOpen())
    //    {
    //        db.createTable();
    //        db.addElement("Monday", 10.5, 1000);
    //        db.addElement("Tuesday", 20.5, 1500);
    //        db.addElement("Wednesday", 30.5, 2000);

    //        db.printAll();
    //        db.removeElement("Monday");
    //        db.printAll();
    //        db.clearDataBase();
    //        qDebug() << "End";
    //    }
    //    else
    //        qDebug() << "Database is not open!";

    qmlRegisterType<DataBaseModel>("DataBaseModel", 1, 0, "DbModel"); // to nasz database adapter

    qmlRegisterSingletonType(QUrl("qrc:///Style.qml"), "App", 1, 0, "Style");
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
