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
private:
  QSqlDatabase m_db;

public:
  DataBase(const QString &name);
  ~DataBase();
  // Database access functions
  bool createTable(); // tutaj powinno byc sprwdzanie, czy istnieje tablica, jesli jest to nie tworzymy wiecej
  bool addElement(const QString &day, const double &km, const int &time);
  bool removeElement(const QString &name);
  std::pair<int, int> returnDataBaseElementByName(const QString &name);
  bool dayExists(const QString &name) const;
  void printAll() const;
  bool clearDataBase();
};

#endif // DATABASE_H
