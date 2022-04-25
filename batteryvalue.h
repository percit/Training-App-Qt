#ifndef BATTERYVALUE_H
#define BATTERYVALUE_H
#include <QTimer>
#include <QObject>
#include <QVariant>
#include <QString>
#include <array>
#include <algorithm>
#include "database.h"
#include <QList>

struct Day
{
    QString day;
    qreal km;
    qreal time;
};

class BatteryValue : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(bool timer_ON READ timer_ON WRITE setTimer_ON NOTIFY timer_ONChanged)

    Q_PROPERTY(qreal weeklyKmRun READ weeklyKmRun WRITE setWeeklyKmRun NOTIFY weeklyKmRunChanged)
    Q_PROPERTY(qreal longestDistance READ longestDistance WRITE setLongestDistance NOTIFY longestDistanceChanged)
    Q_PROPERTY(qreal longestDuration READ longestDuration WRITE setLongestDuration NOTIFY longestDurationChanged)
    Q_PROPERTY(qreal bestPace READ bestPace WRITE setBestPace NOTIFY bestPaceChanged)
    Q_PROPERTY(qreal averageDuration READ averageDuration WRITE setAverageDuration NOTIFY averageDurationChanged)
    Q_PROPERTY(qreal allDuration READ allDuration WRITE setAllDuration NOTIFY allDurationChanged)

    // Q_PROPERTY(Day monday READ monday WRITE setMonday NOTIFY mondayChanged)

private:
    QTimer *m_timer;
    int m_value;
    bool m_up;
    bool m_timer_ON;
    std::array<double, 7> kmRunInDay = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    std::array<double, 7> runningTime = {1000.0, 2000.0, 3000.0, 4000.0, 5000.0, 6000.0, 7000.0}; // for now in seconds
    // m_day{"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"},
    // m_km{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0},
    // m_time{1000.0, 2000.0, 3000.0, 4000.0, 5000.0, 6000.0, 7000.0}

    //    DataBase db("database9.db");

    qreal m_weeklyKmRun;
    qreal m_longestDistance;
    qreal m_longestDuration;
    qreal m_bestPace;
    qreal m_averageDuration;
    qreal m_allDuration;

public:
    explicit BatteryValue(QObject *parent = nullptr);

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

    int value() const;
    void setValue(const int &newValue);
    bool timer_ON() const;
    void setTimer_ON(bool newTimer_ON);

public slots:

signals:

    void valueChanged(const int &);
    void timer_ONChanged();

    void weeklyKmRunChanged();
    void longestDistanceChanged();
    void longestDurationChanged();
    void bestPaceChanged();
    void averageDurationChanged();
    void allDurationChanged();
};

#endif // BATTERYVALUE_H
