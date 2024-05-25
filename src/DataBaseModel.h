#ifndef DATABASEMODEL_H
#define DATABASEMODEL_H
#include "database.h"
#include <QList>
#include <QObject>
#include <QTimer>
#include <QVariant>
#include <algorithm>
#include <array>
#include <utility>

class DataBaseModel : public QObject {
  Q_OBJECT

  // all of these are in meters, seconds, meters/seconds
  Q_PROPERTY(int weeklyMetersRun READ weeklyMetersRun WRITE setweeklyMetersRun
                 NOTIFY weeklyMetersRunChanged)
  Q_PROPERTY(int longestDistance READ longestDistance WRITE setLongestDistance
                 NOTIFY longestDistanceChanged)
  Q_PROPERTY(int longestDuration READ longestDuration WRITE setLongestDuration
                 NOTIFY longestDurationChanged)
  Q_PROPERTY(
      int bestPace READ bestPace WRITE setBestPace NOTIFY bestPaceChanged)
  Q_PROPERTY(int averageDuration READ averageDuration WRITE setAverageDuration
                 NOTIFY averageDurationChanged)
  Q_PROPERTY(int allDuration READ allDuration WRITE setAllDuration NOTIFY
                 allDurationChanged)
  Q_PROPERTY(int weeklyGoal READ weeklyGoal WRITE setWeeklyGoal NOTIFY
                 weeklyGoalChanged)
  Q_PROPERTY(
      int dailyGoal READ dailyGoal WRITE setDailyGoal NOTIFY dailyGoalChanged)
  Q_PROPERTY(QString mail READ mail WRITE setMail NOTIFY mailChanged)
  Q_PROPERTY(QVector<int> weekMeters READ weekMeters NOTIFY weekMetersChanged)
  Q_PROPERTY(QVector<int> weekTime READ weekTime NOTIFY weekTimeChanged)

public:
  explicit DataBaseModel(QObject *parent = nullptr);

  // database functions
  std::pair<int, int> returnDataBaseElementByName(const QString &name) const;
  QString returnMail(const QString &name);
  void initializeDataBase();
  void printDataBase();
  void emitDayChanges();
  int returnNumberFromDay(QString day);
  void setDatabaseName(QString name);

  Q_INVOKABLE void clearAllData();
  Q_INVOKABLE void updateAllMaxes();
  Q_INVOKABLE void setweeklyMetersRun(int newweeklyMetersRun);
  Q_INVOKABLE void setLongestDistance(int newLongestDistance);
  Q_INVOKABLE void setLongestDuration(int newLongestDuration);
  Q_INVOKABLE void setBestPace(int newBestPace);
  Q_INVOKABLE void setAverageDuration(int newAverageDuration);
  Q_INVOKABLE void setAllDuration(int newAllDuration);
  Q_INVOKABLE void setWeeklyGoal(int newWeeklyGoal);
  Q_INVOKABLE void setDailyGoal(int newDailyGoal);
  Q_INVOKABLE void setMail(QString newMail);
  Q_INVOKABLE void setWeek(QString day, int new_meters, int new_time);

  // qproperty functions
  int weeklyMetersRun();
  int longestDistance();
  int longestDuration();
  int bestPace();        // m/s
  int averageDuration(); // s
  int allDuration();
  int weeklyGoal() const;
  int dailyGoal() const;
  QString mail();
  QVector<int> weekMeters() const;
  QVector<int> weekTime() const;
public slots:

signals:
  void weeklyMetersRunChanged();
  void longestDistanceChanged();
  void longestDurationChanged();
  void bestPaceChanged();
  void averageDurationChanged();
  void allDurationChanged();
  void weekMetersChanged();
  void weekTimeChanged();
  void weeklyGoalChanged();
  void dailyGoalChanged();
  void mailChanged();

private:
  void insertDataToDatabase(QString name, int firstValue, int secondValue,
                            int id);
  int m_weeklyMetersRun = 0;
  int m_longestDistance = 0;
  int m_longestDuration = 0;
  int m_bestPace = 0;
  int m_averageDuration = 0;
  int m_allDuration = 0;
  int m_weeklyGoal = 0;
  int m_dailyGoal = 0;
  QString m_mail;
  QString m_databaseName;
  QVector<int> m_weekMeters;
  QVector<int> m_weekTime;
};

#endif // DATABASEMODEL_H