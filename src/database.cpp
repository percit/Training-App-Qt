#include "database.h"

// void DataBase::initializeDatabase() {
//   std::cout << "initializeDatabase" << std::endl;
// 	QSqlQuery query;

// 	if(!query.exec("INSERT INTO weekOfRunning(_kmRunInDay) VALUES(10)"))
// 		qWarning() << "ERROR: " << query.lastError().text();
// 	if(!query.exec("INSERT INTO weekOfRunning(_runningTime) VALUES(10000)"))
// 		qWarning() << "ERROR: " << query.lastError().text();
// }

// void DataBase::quereDatabase() {
//   std::cout << "quereDatabase" << std::endl;
//   QSqlQuery query;
// 	query.prepare("SELECT _kmRunInDay FROM weekOfRunning WHERE id = ?");
// 	query.addBindValue(mInputText->text().toInt());

// 	if(!query.exec())
// 		qWarning() << "ERROR: " << query.lastError().text();

// 	if(query.first())
// 		mOutputText->setText(query.value(0).toString());
// 	else
// 		mOutputText->setText("person not found");
// }

// bool DataBase::addElement(const int& km, const int& time) {
//    QSqlQuery query;
//    query.prepare("INSERT INTO weekOfRunning (_kmRunInDay) VALUES (:_kmRunInDay)");
//    query.prepare("INSERT INTO weekOfRunning (_runningTime) VALUES (:_runningTime)");
//    query.bindValue(":_kmRunInDay", km);
//    query.bindValue(":_runningTime", time);

//    if(query.exec()) return true;
//    else {
//         qDebug() << "addPerson error:" << query.lastError();
// 		return false;
//    }
//   return true;
// }
// bool DataBase::deleteElement(const int& km, const int& time) {
//    QSqlQuery query;
//    query.prepare("DELETE FROM weekOfRunning VALUES (:_kmRunInDay) ");
//    query.bindValue(":_kmRunInDay", km);
//    query.bindValue(":_runningTime", time);

//    if(query.exec()) return true;
//    else {
//         qDebug() << "addPerson error:" << query.lastError();
// 		return false;
//    }
//   return true;
// }
///////////////////////////////////////////
DataBase::DataBase(const std::string &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

DataBase::~DataBase()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

bool DataVase::isOpen() const
{
    return m_db.isOpen();
}

bool DataVase::createTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE people(id INTEGER PRIMARY KEY, name TEXT);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'people': one might already exist.";
        success = false;
    }

    return success;
}

bool DataBase::addPerson(const QString& name)
{
    bool success = false;

    if (!name.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO people (name) VALUES (:name)");
        queryAdd.bindValue(":name", name);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add person failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add person failed: name cannot be empty";
    }

    return success;
}

bool DataBase::removePerson(const QString& name)
{
    bool success = false;

    if (personExists(name))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM people WHERE name = (:name)");
        queryDelete.bindValue(":name", name);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove person failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove person failed: person doesnt exist";
    }

    return success;
}

void DataBase::printAllPersons() const
{
    qDebug() << "Persons in db:";
    QSqlQuery query("SELECT * FROM people");
    int idName = query.record().indexOf("name");
    while (query.next())
    {
        QString name = query.value(idName).toString();
        qDebug() << "===" << name;
    }
}

bool DataBase::personExists(const QString& name) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT name FROM people WHERE name = (:name)");
    checkQuery.bindValue(":name", name);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "person exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool DataBase::removeAllPersons()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM people");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all persons failed: " << removeQuery.lastError();
    }

    return success;
}
