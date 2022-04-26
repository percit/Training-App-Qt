#include "batteryvalue.h"
#include <QDebug>
BatteryValue::BatteryValue(QObject *parent) : QObject(parent),
                                              m_timer(new QTimer(this)),
                                              m_value(0),
                                              m_timer_ON(false),
                                              m_weeklyKmRun(1),
                                              m_longestDistance(2),
                                              m_longestDuration(3),
                                              m_bestPace(4),
                                              m_averageDuration(5),
                                              m_allDuration(6)
{
    qDebug() << "created battery constructor";
    // m_timer->setInterval(10);
    // connect(m_timer, &QTimer::timeout, [=](){ //jesli skonczy sie ten czas 500ms, to sprawdza czy jest
    //     if(m_up) {++m_value;} //true czy false i dodaje lub odejmuje
    //     else {--m_value;}
    //     emit valueChanged(m_value);
    // });
}

qreal BatteryValue::weeklyKmRun()
{
    if (m_weeklyKmRun != std::accumulate(kmRunInDay.begin(), kmRunInDay.end(), 0))
    {
        m_weeklyKmRun = std::accumulate(kmRunInDay.begin(), kmRunInDay.end(), 0);
        // emit weeklyKmRunChanged();
    }
    qDebug() << " m_weeklyKmRun ";
    return m_weeklyKmRun;
}

qreal BatteryValue::longestDistance()
{
    if (m_longestDistance != *(std::max_element(kmRunInDay.begin(), kmRunInDay.end())))
    {
        m_longestDistance = *(std::max_element(kmRunInDay.begin(), kmRunInDay.end()));
        // emit longestDistanceChanged();
    }
    qDebug() << " m_longestDistance ";
    return m_longestDistance;
}

qreal BatteryValue::longestDuration()
{
    if (m_longestDuration != *(std::max_element(runningTime.begin(), runningTime.end())) / 60)
    { // this is in minutes
        m_longestDuration = *(std::max_element(runningTime.begin(), runningTime.end())) / 60;
        // emit longestDurationChanged();
    }
    qDebug() << " m_longestDuration ";
    return m_longestDuration;
}

qreal BatteryValue::bestPace()
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
    qDebug() << " m_bestPace ";
    return m_bestPace;
}

qreal BatteryValue::averageDuration()
{
    if (m_averageDuration != std::accumulate(runningTime.begin(), runningTime.end(), 0) / (7 * 60))
    { // km/h
        m_averageDuration = std::accumulate(runningTime.begin(), runningTime.end(), 0) / (7 * 60);
        // emit averageDurationChanged();
    }
    qDebug() << " m_averageDuration ";
    return m_averageDuration;
}

qreal BatteryValue::allDuration()
{
    return std::accumulate(runningTime.begin(), runningTime.end(), 0) / 60; // in minutes
    if (m_allDuration != std::accumulate(runningTime.begin(), runningTime.end(), 0) / 60)
    { // km/h
        m_allDuration = std::accumulate(runningTime.begin(), runningTime.end(), 0) / 60;
        // emit allDurationChanged();
    }
    qDebug() << " m_allDuration ";
    return m_allDuration;
}

void BatteryValue::setWeeklyKmRun(qreal newWeeklyKmRun)
{
    if (qFuzzyCompare(m_weeklyKmRun, newWeeklyKmRun))
        return;
    m_weeklyKmRun = newWeeklyKmRun;
    emit weeklyKmRunChanged();
}

void BatteryValue::setLongestDistance(qreal newLongestDistance)
{
    if (qFuzzyCompare(m_longestDistance, newLongestDistance))
        return;
    m_longestDistance = newLongestDistance;
    emit longestDistanceChanged();
}

void BatteryValue::setLongestDuration(qreal newLongestDuration)
{
    if (qFuzzyCompare(m_longestDuration, newLongestDuration))
        return;
    m_longestDuration = newLongestDuration;
    emit longestDurationChanged();
}

void BatteryValue::setBestPace(qreal newBestPace)
{
    if (qFuzzyCompare(m_bestPace, newBestPace))
        return;
    m_bestPace = newBestPace;
    emit bestPaceChanged();
}

void BatteryValue::setAverageDuration(qreal newAverageDuration)
{
    if (qFuzzyCompare(m_averageDuration, newAverageDuration))
        return;
    m_averageDuration = newAverageDuration;
    emit averageDurationChanged();
}

void BatteryValue::setAllDuration(qreal newAllDuration)
{
    if (qFuzzyCompare(m_allDuration, newAllDuration))
        return;
    m_allDuration = newAllDuration;
    emit allDurationChanged();
}

void BatteryValue::setTimer_ON(bool newTimer_ON)
{
    if (m_timer_ON == newTimer_ON)
        return;
    m_timer_ON = newTimer_ON;
    emit timer_ONChanged();
}

int BatteryValue::value() const
{
    if (m_value < 0)
        return 0;
    else if (m_value > 100)
        return 100;
    return m_value;
}

void BatteryValue::setValue(const int &newValue)
{
    if (m_value == newValue)
        return;
    m_value = newValue;
    emit valueChanged(m_value);
}

bool BatteryValue::timer_ON() const
{
    return m_timer_ON;
}
