#include "database.h"

DataBase::DataBase(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open()) qDebug() << "Error: connection with database fail";
    else qDebug() << "Database: connection ok";
}

DataBase::~DataBase()
{
    if (m_db.isOpen()) m_db.close();
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
void DataBase::createTable()
{
    QSqlQuery query; 
    //TODO: add checking if table was already created
    query.prepare("CREATE TABLE day(id INTEGER PRIMARY KEY, name TEXT, km INT, time INT);");
    if (!query.exec())
    {
        qWarning() << "ERROR: " << __PRETTY_FUNCTION__ << query.lastError().text();
    }
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
    QSqlQuery query;

    query.prepare("INSERT INTO day (name, km, time) VALUES (:name, :km, :time)");

    query.bindValue(":name", name);
    query.bindValue(":km", km);
    query.bindValue(":time", time);

    if (query.exec()) return true;
    else qWarning() << "ERROR: " << __PRETTY_FUNCTION__ << query.lastError().text();

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
        QSqlQuery query;
        query.prepare("DELETE FROM day WHERE name = (:name)");
        query.bindValue(":name", name);
        if (!query.exec())
            qWarning() << "ERROR: " << __PRETTY_FUNCTION__ << query.lastError().text();
    }
    else
        qWarning() << "ERROR: " << __PRETTY_FUNCTION__ << "Person doesn't exist";

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
        QSqlQuery query;
        query.prepare("SELECT * FROM day WHERE name = (:name)");
        query.bindValue(":name", name);
        if (!query.exec())
            qWarning() << "ERROR: " << __PRETTY_FUNCTION__ << query.lastError().text();
        if (query.next())
        {
            QString name = query.value("name").toString();
            temp.first = query.value("km").toInt();
            temp.second = query.value("time").toInt();
        }
    }
    else
        qWarning() << "ERROR: " << __PRETTY_FUNCTION__ << "Person doesn't exist";

    return temp;
}

void DataBase::printAll() const
{
    QSqlQuery query("SELECT * FROM day");
    qDebug() << "Objects in db:" << "\n";
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
    QSqlQuery query;
    query.prepare("SELECT name FROM day WHERE name = (:name)");
    query.bindValue(":name", name);

    if (query.exec())
    {
        if (query.next()) return true;
    }
    else qWarning() << "ERROR: " << __PRETTY_FUNCTION__ << query.lastError().text();

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
    QSqlQuery query;
    query.prepare("DELETE FROM day");

    if (query.exec()) return true;
    else qWarning() << "ERROR: " << __PRETTY_FUNCTION__ << query.lastError().text();

    return false;
}
