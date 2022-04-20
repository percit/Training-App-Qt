#include <QGuiApplication>
#include <QQmlApplicationEngine>

//database additions
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
	qmlRegisterSingletonType(QUrl("qrc:///Style.qml"), "App", 1, 0, "Style");


	//DATABASE 	CONNECT
	const QString DRIVER("QSQLITE");
	if(QSqlDatabase::isDriverAvailable(DRIVER))
	{
		QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
		db.setDatabaseName(":memory:");//change into actual database name
		if(!db.open())
			qWarning() << "Database error: " << db.lastError().text();
	}
	else
		qWarning() << "ERROR: no driver " << DRIVER << " available";


	//CREATING TABLE, ja bede tworzyl kilometry, czas, dzien tygodnia i przechowywal tylko caly tydzien
	QSqlQuery query("CREATE TABLE people (id INTEGER PRIMARY KEY, name TEXT)");
	if(!query.isActive())//checking if making a table was succesful
		qWarning() << "ERROR: " << query.lastError().text();

  //kolejna funkcja btw
	QSqlQuery query; //tutaj dodajemy elementy do tablicy, ten query on dodal w dodatkowej funcji
	if(!query.exec("INSERT INTO people(name) VALUES('Eddie Guerrero')"))
		qWarning() << "ERROR: " << query.lastError().text();
	if(!query.exec("INSERT INTO people(name) VALUES('Gordon Ramsay')"))
		qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
  //nie musimy dodawac id, bo to jest stale dodawane przez PRIMATY KEY

	//czytanie z bazy danych

	QSqlQuery query;
	query.prepare("SELECT name FROM people WHERE id = ?");
	query.addBindValue(mInputText->text().toInt());

	if(!query.exec())
		qWarning() << "ERROR: " << query.lastError().text();

	if(query.first())
		mOutputText->setText(query.value(0).toString());
	else
		mOutputText->setText("person not found");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
