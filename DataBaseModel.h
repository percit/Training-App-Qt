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
    Q_PROPERTY(int tuesday_km READ tuesday_km WRITE setTuesday_km NOTIFY tuesday_kmChanged)
    Q_PROPERTY(int tuesday_time READ tuesday_time WRITE setTuesday_time NOTIFY tuesday_timeChanged)
    Q_PROPERTY(int wednesday_km READ wednesday_km WRITE setWednesday_km NOTIFY wednesday_kmChanged)
    Q_PROPERTY(int wednesday_time READ wednesday_time WRITE setWednesday_time NOTIFY wednesday_timeChanged)
    Q_PROPERTY(int thursday_km READ thursday_km WRITE setThursday_km NOTIFY thursday_kmChanged)
    Q_PROPERTY(int thursday_time READ thursday_time WRITE setThursday_time NOTIFY thursday_timeChanged)
    Q_PROPERTY(int friday_km READ friday_km WRITE setFriday_km NOTIFY friday_kmChanged)
    Q_PROPERTY(int friday_time READ friday_time WRITE setFriday_time NOTIFY friday_timeChanged)
    Q_PROPERTY(int saturday_km READ saturday_km WRITE setSaturday_km NOTIFY saturday_kmChanged)
    Q_PROPERTY(int saturday_time READ saturday_time WRITE setSaturday_time NOTIFY saturday_timeChanged)
    Q_PROPERTY(int sunday_km READ sunday_km WRITE setSunday_km NOTIFY sunday_kmChanged)
    Q_PROPERTY(int sunday_time READ sunday_time WRITE setSunday_time NOTIFY sunday_timeChanged)

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

    int m_monday_km = 0;
    int m_monday_time = 0;

    int m_tuesday_km = 0;
    int m_tuesday_time = 0;

    int m_wednesday_km = 0;
    int m_wednesday_time = 0;

    int m_thursday_km = 0;
    int m_thursday_time = 0;

    int m_friday_km = 0;
    int m_friday_time = 0;

    int m_saturday_km = 0;
    int m_saturday_time = 0;

    int m_sunday_km = 0;
    int m_sunday_time = 0;

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


    Q_INVOKABLE void setMonday_km(int newMonday_km);
    Q_INVOKABLE void setMonday_time(int newMonday_time);
    Q_INVOKABLE void setTuesday_km(int newTuesday_km);
    Q_INVOKABLE void setTuesday_time(int newTuesday_time);
    Q_INVOKABLE void setWednesday_km(int newWednesday_km);
    Q_INVOKABLE void setWednesday_time(int newWednesday_time);
    Q_INVOKABLE void setThursday_km(int newThursday_km);
    Q_INVOKABLE void setThursday_time(int newThursday_time);
    Q_INVOKABLE void setFriday_km(int newFriday_km);
    Q_INVOKABLE void setFriday_time(int newFriday_time);
    Q_INVOKABLE void setSaturday_km(int newSaturday_km);
    Q_INVOKABLE void setSaturday_time(int newSaturday_time);
    Q_INVOKABLE void setSunday_km(int newSunday_km);
    Q_INVOKABLE void setSunday_time(int newSunday_time);


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
};

#endif // DATABASEMODEL_H
