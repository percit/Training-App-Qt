#ifndef DATABASE_H
#define DATABASE_H
#include <array>
#include <string>
#include <utility>

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

class DataBase {
public:
  DataBase(const QString &name);
  ~DataBase();

  bool isOpen() const;
  static void createTable();
  void addElement(const QString &day, const double &meters, const int &time);
  void updateElement(const QString &day, double meters, int time, int id);
  bool removeElement(const QString &name);
  std::pair<int, int> returnDataBaseElementByName(const QString &name);
  bool dayExists(const QString &name) const;
  void printAll() const;
  bool clearDataBase();
  void addMail(const QString &day, const QString &mail);
  void updateMail(const QString &day, const QString &mail, int id);
  QString returnMail(const QString &name);

private:
  QSqlDatabase m_db;
};

#endif // DATABASE_H
