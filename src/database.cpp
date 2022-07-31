#include "../inc/database.h"

DataBase::DataBase(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
        qDebug() << "Error: connection with database fail";
    else
        qDebug() << "Database: connection ok";
}

DataBase::~DataBase()
{
    if (m_db.isOpen())
        m_db.close();
}

bool DataBase::isOpen() const
{
    return m_db.isOpen();
}
/**
 * @brief create table for day, meters, time
 * 
 * @return true 
 * @return false 
 */
bool DataBase::createTable()
{
    QSqlQuery query;

    query.prepare("CREATE TABLE day(id INTEGER PRIMARY KEY, name TEXT, km INT, time INT);");
    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'day': one might already exist.";
        return true;
    }
    return false;
}
/**
 * @brief add element to the table of database
 * 
 * @param name 
 * @param km 
 * @param time 
 * @return true 
 * @return false 
 */
bool DataBase::addElement(const QString &name, const double &km, const int &time)
{
    QSqlQuery queryAdd;

    queryAdd.prepare("INSERT INTO day (name, km, time) VALUES (:name, :km, :time)");

    queryAdd.bindValue(":name", name);
    queryAdd.bindValue(":km", km);
    queryAdd.bindValue(":time", time);

    if (queryAdd.exec()) return true;
    else qWarning() << "ERROR: " << queryAdd.lastError().text();

    return false;
}
/**
 * @brief remove whole day row from database
 * 
 * @param name 
 * @return true 
 * @return false 
 */
bool DataBase::removeElement(const QString &name)
{
    if (dayExists(name))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM day WHERE name = (:name)");
        queryDelete.bindValue(":name", name);
        if (!queryDelete.exec())
            qDebug() << "remove person failed: " << queryDelete.lastError();
    }
    else
        qDebug() << "remove person failed: person doesnt exist";

    return false;
}
/**
 * @brief get meters and time in std::pair by using day name
 * 
 * @param name 
 * @return std::pair<int, int> 
 */
std::pair<int, int> DataBase::returnDataBaseElementByName(const QString &name)
{
    std::pair<int, int> temp;
    if (dayExists(name))
    {
        QSqlQuery queryRead;
        queryRead.prepare("SELECT * FROM day WHERE name = (:name)");
        queryRead.bindValue(":name", name);
        if (!queryRead.exec())
            qDebug() << "returnDataBaseElementByName failed: " << queryRead.lastError();
        if (queryRead.next())
        {
            QString name = queryRead.value("name").toString();
            temp.first = queryRead.value("km").toInt();
            temp.second = queryRead.value("time").toInt();
        }
    }
    else
        qDebug() << "returnDataBaseElementByName failed:  doesnt exist";

    return temp;
}

void DataBase::printAll() const
{
    qDebug() << "Objects in db:";
    QSqlQuery query("SELECT * FROM day");
    qDebug() << "\n";
    while (query.next())
    {
        qDebug() << query.value("name").toString();
        qDebug() << query.value("km").toString();
        qDebug() << query.value("time").toString();
    }
}
/**
 * @brief checking if day entry exists in database (this won't be needed due to initialization)
 * 
 * @param name 
 * @return true 
 * @return false 
 */
bool DataBase::dayExists(const QString &name) const
{
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT name FROM day WHERE name = (:name)");
    checkQuery.bindValue(":name", name);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
            return true;
    }
    else
        qDebug() << "person exists failed: " << checkQuery.lastError();

    return false;
}
/**
 * @brief deletes all data from database
 * 
 * @return true 
 * @return false 
 */
bool DataBase::clearDataBase()
{
    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM day");

    if (removeQuery.exec())
        return true;
    else
        qDebug() << "remove all data from database failed: " << removeQuery.lastError();

    return false;
}
