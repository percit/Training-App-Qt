#pragma once
#include <array>
#include <string>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

class DataBase {//I think this should be a singleton
  private:
	std::array<int, 7> kmRunInDay;
	std::array<int, 7> runningTime;//for now in seconds
	//std::array<int, 7> kmRunInDay;

  public: 
	DataBase(const std::string& databasePath) {
	const QString DRIVER("QSQLITE");//making database

	if(QSqlDatabase::isDriverAvailable(DRIVER))
	{
		QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
		db.setDatabaseName(databasePath);
		if(!db.open()) qWarning() << "ERROR: " << db.lastError().text();
	}
	else qWarning() << "ERROR: no driver " << DRIVER << " available";

	//making table
	QSqlQuery query("CREATE TABLE weekOfRunning (id INTEGER PRIMARY KEY, _kmRunInDay INTEGER, _runningTime INTEGER)");
	if(!query.isActive())
		qWarning() << "ERROR: " << query.lastError().text();
	}
	~DataBase {}

	void initializeDatabase();//won't be needed in the end, but this can be for testing in gtest
	void quereDatabase(); //what does that do?
	bool addElement(const int& km, const int& time);//add to gtest
};

