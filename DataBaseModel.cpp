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

