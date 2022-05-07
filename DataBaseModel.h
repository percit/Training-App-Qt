#ifndef DATABASEMODEL_H
#define DATABASEMODEL_H
#include <QTimer>
#include <QObject>
#include <QVariant>
#include <QString>
#include <QList>
#include <array>
#include <algorithm>
#include "database.h"

struct Day
{
    QString day;
    qreal km;
    qreal time;
};

class DataBaseModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(qreal weeklyKmRun READ weeklyKmRun WRITE setWeeklyKmRun NOTIFY weeklyKmRunChanged)
    Q_PROPERTY(qreal longestDistance READ longestDistance WRITE setLongestDistance NOTIFY longestDistanceChanged)
    Q_PROPERTY(qreal longestDuration READ longestDuration WRITE setLongestDuration NOTIFY longestDurationChanged)
    Q_PROPERTY(qreal bestPace READ bestPace WRITE setBestPace NOTIFY bestPaceChanged)
    Q_PROPERTY(qreal averageDuration READ averageDuration WRITE setAverageDuration NOTIFY averageDurationChanged)
    Q_PROPERTY(qreal allDuration READ allDuration WRITE setAllDuration NOTIFY allDurationChanged)

    // Q_PROPERTY(Day monday READ monday WRITE setMonday NOTIFY mondayChanged)

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

public slots:

signals:

    void weeklyKmRunChanged();
    void longestDistanceChanged();
    void longestDurationChanged();
    void bestPaceChanged();
    void averageDurationChanged();
    void allDurationChanged();
};

#endif // DATABASEMODEL_H
