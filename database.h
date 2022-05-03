#ifndef DATABASE_H
#define DATABASE_H
#include <array>
#include <string>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

class DataBase
{
private:
  std::array<double, 7> kmRunInDay = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
  std::array<double, 7> runningTime = {1000.0, 2000.0, 3000.0, 4000.0, 5000.0, 6000.0, 7000.0}; // for now in seconds

  QSqlDatabase m_db;

public:
  DataBase(const QString &name);
  ~DataBase();
  // Database access functions
  //  ADD ALL OF THESE TO GTEST
  bool isOpen() const;
  bool createTable(); // tutaj powinno byc sprwdzanie, czy istnieje tablica, jesli jest to nie tworzymy wiecej
  bool addElement(const QString &day, const double &km, const int &time);
  bool removeElement(const QString &name);
  bool dayExists(const QString &name) const;
  void printAll() const;
  bool clearDataBase();

  // o te rzeczy powinny byc w innej klasie, ktora ma argument typu DataBase
  // achievements page
  //  double getWeeklyKmRun();
  //  double getLongestDistance();
  //  double getLongestDuration();
  //  double getBestPace();

  // //weekly stats page
  // double averageDuration();
};

#endif // DATABASE_H
