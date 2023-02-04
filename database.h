#ifndef DATABASE_H
#define DATABASE_H
#include <array>
#include <string>
#include <utility>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

class DataBase
{
public:
  DataBase(const QString &name);
  ~DataBase();

  bool isOpen() const;
  void createTable();
  bool addElement(const QString &day, const double &km, const int &time);
  bool removeElement(const QString &name);
  std::pair<int, int> returnDataBaseElementByName(const QString &name);
  bool dayExists(const QString &name) const;
  void printAll() const;
  bool clearDataBase();

private:
  QSqlDatabase m_db;
};

#endif // DATABASE_H
