#include "DataBaseModel.h"
#include <QDebug>
DataBaseModel::DataBaseModel(QObject *parent) : QObject(parent),
                                              m_weeklyKmRun(1),
                                              m_longestDistance(2),
                                              m_longestDuration(3),
                                              m_bestPace(4),
                                              m_averageDuration(5),
                                              m_allDuration(6)
{
    qDebug() << "created DataBaseModel constructor";
}

qreal DataBaseModel::weeklyKmRun()
{
    if (m_weeklyKmRun != std::accumulate(kmRunInDay.begin(), kmRunInDay.end(), 0))
    {
        m_weeklyKmRun = std::accumulate(kmRunInDay.begin(), kmRunInDay.end(), 0);
        // emit weeklyKmRunChanged();
    }
    return m_weeklyKmRun;
}

qreal DataBaseModel::longestDistance()
{
    if (m_longestDistance != *(std::max_element(kmRunInDay.begin(), kmRunInDay.end())))
    {
        m_longestDistance = *(std::max_element(kmRunInDay.begin(), kmRunInDay.end()));
        // emit longestDistanceChanged();
    }
    return m_longestDistance;
}

qreal DataBaseModel::longestDuration()
{
    if (m_longestDuration != *(std::max_element(runningTime.begin(), runningTime.end())) / 60)
    { // this is in minutes
        m_longestDuration = *(std::max_element(runningTime.begin(), runningTime.end())) / 60;
        // emit longestDurationChanged();
    }
    return m_longestDuration;
}

qreal DataBaseModel::bestPace()
{
    double bestPace = 0;
    for (int i = 0; i < 7; ++i)
    {
        if (runningTime[i] > 0)
            bestPace = std::max(kmRunInDay[i] / runningTime[i], bestPace);
    }
    if (m_bestPace != bestPace)
    {
        m_bestPace = bestPace;
        // emit bestPaceChanged();
    }
    return m_bestPace;
}

qreal DataBaseModel::averageDuration()
{
    if (m_averageDuration != std::accumulate(runningTime.begin(), runningTime.end(), 0) / (7 * 60))
    { // km/h
        m_averageDuration = std::accumulate(runningTime.begin(), runningTime.end(), 0) / (7 * 60);
        // emit averageDurationChanged();
    }
    return m_averageDuration;
}

qreal DataBaseModel::allDuration()
{
    return std::accumulate(runningTime.begin(), runningTime.end(), 0) / 60; // in minutes
    if (m_allDuration != std::accumulate(runningTime.begin(), runningTime.end(), 0) / 60)
    { // km/h
        m_allDuration = std::accumulate(runningTime.begin(), runningTime.end(), 0) / 60;
        // emit allDurationChanged();
    }
    return m_allDuration;
}

void DataBaseModel::setWeeklyKmRun(qreal newWeeklyKmRun)
{
    if (qFuzzyCompare(m_weeklyKmRun, newWeeklyKmRun))
        return;
    m_weeklyKmRun = newWeeklyKmRun;
    emit weeklyKmRunChanged();
}

void DataBaseModel::setLongestDistance(qreal newLongestDistance)
{
    if (qFuzzyCompare(m_longestDistance, newLongestDistance))
        return;
    m_longestDistance = newLongestDistance;
    emit longestDistanceChanged();
}

void DataBaseModel::setLongestDuration(qreal newLongestDuration)
{
    if (qFuzzyCompare(m_longestDuration, newLongestDuration))
        return;
    m_longestDuration = newLongestDuration;
    emit longestDurationChanged();
}

void DataBaseModel::setBestPace(qreal newBestPace)
{
    if (qFuzzyCompare(m_bestPace, newBestPace))
        return;
    m_bestPace = newBestPace;
    emit bestPaceChanged();
}

void DataBaseModel::setAverageDuration(qreal newAverageDuration)
{
    if (qFuzzyCompare(m_averageDuration, newAverageDuration))
        return;
    m_averageDuration = newAverageDuration;
    emit averageDurationChanged();
}

void DataBaseModel::setAllDuration(qreal newAllDuration)
{
    if (qFuzzyCompare(m_allDuration, newAllDuration))
        return;
    m_allDuration = newAllDuration;
    emit allDurationChanged();
}

// /////////////////////////////////////////////////////////////////////
//DAYS

int DataBaseModel::monday_km() const
{
    return m_monday_km;
}

void DataBaseModel::setMonday_km(int newMonday_km)
{
    if (m_monday_km == newMonday_km)
        return;
    m_monday_km = newMonday_km;
    qDebug() << m_monday_km;
    emit monday_kmChanged();
}

int DataBaseModel::monday_time() const
{
    return m_monday_time;
}

void DataBaseModel::setMonday_time(int newMonday_time)
{
    if (m_monday_time == newMonday_time)
        return;
    m_monday_time = newMonday_time;
    qDebug() << m_monday_time;
    emit monday_timeChanged();
}

int DataBaseModel::tuesday_km() const
{
    return m_tuesday_km;
}

void DataBaseModel::setTuesday_km(int newTuesday_km)
{
    if (m_tuesday_km == newTuesday_km)
        return;
    m_tuesday_km = newTuesday_km;
    emit tuesday_kmChanged();
}

int DataBaseModel::tuesday_time() const
{
    return m_tuesday_time;
}

void DataBaseModel::setTuesday_time(int newTuesday_time)
{
    if (m_tuesday_time == newTuesday_time)
        return;
    m_tuesday_time = newTuesday_time;
    emit tuesday_timeChanged();
}

int DataBaseModel::wednesday_km() const
{
    return m_wednesday_km;
}

void DataBaseModel::setWednesday_km(int newWednesday_km)
{
    if (m_wednesday_km == newWednesday_km)
        return;
    m_wednesday_km = newWednesday_km;
    emit wednesday_kmChanged();
}

int DataBaseModel::wednesday_time() const
{
    return m_wednesday_time;
}

void DataBaseModel::setWednesday_time(int newWednesday_time)
{
    if (m_wednesday_time == newWednesday_time)
        return;
    m_wednesday_time = newWednesday_time;
    emit wednesday_timeChanged();
}

int DataBaseModel::thursday_km() const
{
    return m_thursday_km;
}

void DataBaseModel::setThursday_km(int newThursday_km)
{
    if (m_thursday_km == newThursday_km)
        return;
    m_thursday_km = newThursday_km;
    emit thursday_kmChanged();
}

int DataBaseModel::thursday_time() const
{
    return m_thursday_time;
}

void DataBaseModel::setThursday_time(int newThursday_time)
{
    if (m_thursday_time == newThursday_time)
        return;
    m_thursday_time = newThursday_time;
    emit thursday_timeChanged();
}

int DataBaseModel::friday_km() const
{
    return m_friday_km;
}

void DataBaseModel::setFriday_km(int newFriday_km)
{
    if (m_friday_km == newFriday_km)
        return;
    m_friday_km = newFriday_km;
    emit friday_kmChanged();
}

int DataBaseModel::friday_time() const
{
    return m_friday_time;
}

void DataBaseModel::setFriday_time(int newFriday_time)
{
    if (m_friday_time == newFriday_time)
        return;
    m_friday_time = newFriday_time;
    emit friday_timeChanged();
}

int DataBaseModel::saturday_km() const
{
    return m_saturday_km;
}

void DataBaseModel::setSaturday_km(int newSaturday_km)
{
    if (m_saturday_km == newSaturday_km)
        return;
    m_saturday_km = newSaturday_km;
    emit saturday_kmChanged();
}

int DataBaseModel::saturday_time() const
{
    return m_saturday_time;
}

void DataBaseModel::setSaturday_time(int newSaturday_time)
{
    if (m_saturday_time == newSaturday_time)
        return;
    m_saturday_time = newSaturday_time;
    emit saturday_timeChanged();
}

int DataBaseModel::sunday_km() const
{
    return m_sunday_km;
}

void DataBaseModel::setSunday_km(int newSunday_km)
{
    if (m_sunday_km == newSunday_km)
        return;
    m_sunday_km = newSunday_km;
    emit sunday_kmChanged();
}

int DataBaseModel::sunday_time() const
{
    return m_sunday_time;
}

void DataBaseModel::setSunday_time(int newSunday_time)
{
    if (m_sunday_time == newSunday_time)
        return;
    m_sunday_time = newSunday_time;
    emit sunday_timeChanged();
}
