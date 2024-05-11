#ifndef DATABASEMODEL_H
#define DATABASEMODEL_H
#include <QList>
#include <QObject>
#include <QTimer>
#include <QVariant>
#include <utility>
#include <algorithm>
#include <array>
#include "database.h"

class DataBaseModel : public QObject
{
    Q_OBJECT

    // all of these are in meters, seconds, meters/seconds despite names
    Q_PROPERTY(qreal weeklyKmRun READ weeklyKmRun WRITE setWeeklyKmRun NOTIFY weeklyKmRunChanged)
    Q_PROPERTY(qreal longestDistance READ longestDistance WRITE setLongestDistance NOTIFY longestDistanceChanged)
    Q_PROPERTY(qreal longestDuration READ longestDuration WRITE setLongestDuration NOTIFY longestDurationChanged)
    Q_PROPERTY(qreal bestPace READ bestPace WRITE setBestPace NOTIFY bestPaceChanged)
    Q_PROPERTY(qreal averageDuration READ averageDuration WRITE setAverageDuration NOTIFY averageDurationChanged)
    Q_PROPERTY(qreal allDuration READ allDuration WRITE setAllDuration NOTIFY allDurationChanged)
    Q_PROPERTY(int weeklyGoal READ weeklyGoal WRITE setWeeklyGoal NOTIFY weeklyGoalChanged) // how many meters we want to run in a week
    Q_PROPERTY(int dailyGoal READ dailyGoal WRITE setDailyGoal NOTIFY dailyGoalChanged)    // or day
    Q_PROPERTY(QString mail READ mail WRITE setMail NOTIFY mailChanged)

    Q_PROPERTY(int monday_km READ monday_km NOTIFY monday_kmChanged)
    Q_PROPERTY(int monday_time READ monday_time NOTIFY monday_timeChanged)
    Q_PROPERTY(int tuesday_km READ tuesday_km NOTIFY tuesday_kmChanged)
    Q_PROPERTY(int tuesday_time READ tuesday_time NOTIFY tuesday_timeChanged)
    Q_PROPERTY(int wednesday_km READ wednesday_km NOTIFY wednesday_kmChanged)
    Q_PROPERTY(int wednesday_time READ wednesday_time NOTIFY wednesday_timeChanged)
    Q_PROPERTY(int thursday_km READ thursday_km NOTIFY thursday_kmChanged)
    Q_PROPERTY(int thursday_time READ thursday_time NOTIFY thursday_timeChanged)
    Q_PROPERTY(int friday_km READ friday_km NOTIFY friday_kmChanged)
    Q_PROPERTY(int friday_time READ friday_time NOTIFY friday_timeChanged)
    Q_PROPERTY(int saturday_km READ saturday_km NOTIFY saturday_kmChanged)
    Q_PROPERTY(int saturday_time READ saturday_time NOTIFY saturday_timeChanged)
    Q_PROPERTY(int sunday_km READ sunday_km NOTIFY sunday_kmChanged)
    Q_PROPERTY(int sunday_time READ sunday_time NOTIFY sunday_timeChanged)

private:
    std::array<double, 7> kmRunInDay = {0, 0, 0, 0, 0, 0, 0};  // in meters actually TODO: change naming everywhere to metersRunInDay
    std::array<double, 7> runningTime = {0, 0, 0, 0, 0, 0, 0}; // for now in seconds TODO: runningTimeSec

    qreal m_weeklyKmRun = 0;
    qreal m_longestDistance = 0;
    qreal m_longestDuration = 0;
    qreal m_bestPace = 0;
    qreal m_averageDuration = 0;
    qreal m_allDuration = 0;
    int m_weeklyGoal = 0;
    int m_dailyGoal = 0;
    QString m_mail;

public:
    explicit DataBaseModel(QObject *parent = nullptr);

    // database functions
    std::pair<int, int> returnDataBaseElementByName(const QString &name) const;
    QString returnMail(const QString &name);
    void initializeDataBase();
    void printDataBase();
    void emitDayChanges();

    Q_INVOKABLE void clearAllData();
    Q_INVOKABLE void updateAllMaxes();
    Q_INVOKABLE void setWeeklyKmRun(qreal newWeeklyKmRun);
    Q_INVOKABLE void setLongestDistance(qreal newLongestDistance);
    Q_INVOKABLE void setLongestDuration(qreal newLongestDuration);
    Q_INVOKABLE void setBestPace(qreal newBestPace);
    Q_INVOKABLE void setAverageDuration(qreal newAverageDuration);
    Q_INVOKABLE void setAllDuration(qreal newAllDuration);
    Q_INVOKABLE void setWeeklyGoal(int newWeeklyGoal);
    Q_INVOKABLE void setDailyGoal(int newDailyGoal);
    Q_INVOKABLE void setMail(QString newMail);

    Q_INVOKABLE void setMonday(int new_km, int new_time);
    Q_INVOKABLE void setTuesday(int new_km, int new_time);
    Q_INVOKABLE void setWednesday(int new_km, int new_time);
    Q_INVOKABLE void setThursday(int new_km, int new_time);
    Q_INVOKABLE void setFriday(int new_km, int new_time);
    Q_INVOKABLE void setSaturday(int new_km, int new_time);
    Q_INVOKABLE void setSunday(int new_km, int new_time);

    // qproperty functions
    qreal weeklyKmRun();
    qreal longestDistance();
    qreal longestDuration();
    qreal bestPace();
    qreal averageDuration();
    qreal allDuration();
    int weeklyGoal() const;
    int dailyGoal() const;
    QString mail();

    int monday_km() const;
    int monday_time() const;
    int tuesday_km() const;
    int tuesday_time() const;
    int wednesday_km() const;
    int wednesday_time() const;
    int thursday_km() const;
    int thursday_time() const;
    int friday_km() const;
    int friday_time() const;
    int saturday_km() const;
    int saturday_time() const;
    int sunday_km() const;
    int sunday_time() const;

public slots:

signals:
    void weeklyKmRunChanged();
    void longestDistanceChanged();
    void longestDurationChanged();
    void bestPaceChanged();
    void averageDurationChanged();
    void allDurationChanged();
    void mondayChanged();
    void monday_kmChanged();
    void monday_timeChanged();
    void tuesday_kmChanged();
    void tuesday_timeChanged();
    void wednesday_kmChanged();
    void wednesday_timeChanged();
    void thursday_kmChanged();
    void thursday_timeChanged();
    void friday_kmChanged();
    void friday_timeChanged();
    void saturday_kmChanged();
    void saturday_timeChanged();
    void sunday_kmChanged();
    void sunday_timeChanged();
    void weeklyGoalChanged();
    void dailyGoalChanged();
    void mailChanged();
};

#endif // DATABASEMODEL_H