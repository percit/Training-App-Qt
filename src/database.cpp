#include "database.h"

void DataBase::initializeDatabase() {
  std::cout << "initializeDatabase" << std::endl;
	QSqlQuery query;

	if(!query.exec("INSERT INTO weekOfRunning(_kmRunInDay) VALUES(10)"))
		qWarning() << "ERROR: " << query.lastError().text();
	if(!query.exec("INSERT INTO weekOfRunning(_runningTime) VALUES(10000)"))
		qWarning() << "ERROR: " << query.lastError().text();
}

void DataBase::quereDatabase() {
  std::cout << "quereDatabase" << std::endl;
  QSqlQuery query;
	query.prepare("SELECT _kmRunInDay FROM weekOfRunning WHERE id = ?");
	query.addBindValue(mInputText->text().toInt());

	if(!query.exec())
		qWarning() << "ERROR: " << query.lastError().text();

	if(query.first())
		mOutputText->setText(query.value(0).toString());
	else
		mOutputText->setText("person not found");
}

bool DataBase::addElement(const int& km, const int& time) {
   QSqlQuery query;
   query.prepare("INSERT INTO weekOfRunning (_kmRunInDay) VALUES (:_kmRunInDay)");
   query.prepare("INSERT INTO weekOfRunning (_runningTime) VALUES (:_runningTime)");
   query.bindValue(":_kmRunInDay", km);
   query.bindValue(":_runningTime", time);

   if(query.exec()) return true;
   else {
        qDebug() << "addPerson error:" << query.lastError();
		return false;
   }
  return true;
}
bool DataBase::deleteElement(const int& km, const int& time) {
   QSqlQuery query;
   query.prepare("DELETE FROM weekOfRunning VALUES (:_kmRunInDay) ");
   query.bindValue(":_kmRunInDay", km);
   query.bindValue(":_runningTime", time);

   if(query.exec()) return true;
   else {
        qDebug() << "addPerson error:" << query.lastError();
		return false;
   }
  return true;
}
