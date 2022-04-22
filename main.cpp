#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "database.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    qmlRegisterSingletonType(QUrl("qrc:///Style.qml"), "App", 1, 0, "Style");

    DataBase db("database9.db");
    if (db.isOpen())
    {
        db.createTable();
        db.addElement("Monday", 10.5, 1000);
        db.addElement("Tuesday", 20.5, 1500);
        db.addElement("Wednesday", 30.5, 2000);

        db.printAll();
        db.removeElement("Monday");
        db.printAll();
        db.clearDataBase();
        qDebug() << "End";
    }
    else
        qDebug() << "Database is not open!";



//Bartek dal cos takiego:

// thor::rpc::Model model(};
// engine.rootContext()->setContextProperty("DbModel", &model); i jako DbModel.costam bedzie to dostepne
//a ja zrobilem w klasie:

// class Cos : public QObject {
//     Q_OBJECT
//     Q_PROPERTY(QString cos itd); ( plik ip_manager w app other/src)
// }
// a potem w mainie dalem
//  className object;
//  object.cos 
//  i chyba tu funkcji nie bylo idk


    
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
