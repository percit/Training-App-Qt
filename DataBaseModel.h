#ifndef DATABASEMODEL_H
#define DATABASEMODEL_H
#include <QList>
#include <QObject>
#include <QString>
#include <QTimer>
#include <QVariant>
#include <algorithm>
#include <array>
#include "database.h"

struct Day
{
    Q_GADGET
    qreal metersRun;
    qreal timeRun;
    Q_PROPERTY(qreal metersRun MEMBER metersRun)
    Q_PROPERTY(qreal timeRun MEMBER timeRun)

};
Q_DECLARE_METATYPE(Day)

class DataBaseModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(qreal weeklyKmRun READ weeklyKmRun WRITE setWeeklyKmRun NOTIFY weeklyKmRunChanged)
    Q_PROPERTY(qreal longestDistance READ longestDistance WRITE setLongestDistance NOTIFY longestDistanceChanged)
    Q_PROPERTY(qreal longestDuration READ longestDuration WRITE setLongestDuration NOTIFY longestDurationChanged)
    Q_PROPERTY(qreal bestPace READ bestPace WRITE setBestPace NOTIFY bestPaceChanged)
    Q_PROPERTY(qreal averageDuration READ averageDuration WRITE setAverageDuration NOTIFY averageDurationChanged)
    Q_PROPERTY(qreal allDuration READ allDuration WRITE setAllDuration NOTIFY allDurationChanged)


//this is a temporary solution
    Q_PROPERTY(int monday_km READ monday_km WRITE setMonday_km NOTIFY monday_kmChanged)
    Q_PROPERTY(int monday_time READ monday_time WRITE setMonday_time NOTIFY monday_timeChanged)

    //Q_PROPERTY(Day monday READ monday WRITE setMonday NOTIFY mondayChanged) // tutaj powinna byc lista


private:
    std::array<double, 7> kmRunInDay = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    std::array<double, 7> runningTime = {1000.0, 2000.0, 3000.0, 4000.0, 5000.0, 6000.0, 7000.0}; // for now in seconds

    //    DataBase db("database9.db");

    qreal m_weeklyKmRun;
    qreal m_longestDistance;
    qreal m_longestDuration;
    qreal m_bestPace;
    qreal m_averageDuration;
    qreal m_allDuration;

    Day m_monday;

    int m_monday_km = 0;
    int m_monday_time = 0;

public:
    explicit DataBaseModel(QObject *parent = nullptr);

    qreal weeklyKmRun();
    qreal longestDistance();
    qreal longestDuration();
    qreal bestPace();
    qreal averageDuration();
    qreal allDuration();

    void setWeeklyKmRun(qreal newWeeklyKmRun);
    void setLongestDistance(qreal newLongestDistance);
    void setLongestDuration(qreal newLongestDuration);
    void setBestPace(qreal newBestPace);
    void setAverageDuration(qreal newAverageDuration);
    void setAllDuration(qreal newAllDuration);

    const Day &monday() const;
    Q_INVOKABLE void setMonday(const Day &newMonday);

    int monday_km() const;
    int monday_time() const;

    Q_INVOKABLE void setMonday_km(int newMonday_km);
    Q_INVOKABLE void setMonday_time(int newMonday_time);

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
};

#endif // DATABASEMODEL_H
