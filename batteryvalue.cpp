#include "batteryvalue.h"
#include <QDebug>
BatteryValue::BatteryValue(QObject *parent) :
    QObject(parent),
    m_timer(new QTimer(this)),
    m_value(0),
    m_up(true),
    m_timer_ON(false)
{
    qDebug() << "created battery constructor";
    m_timer->setInterval(10);
    connect(m_timer, &QTimer::timeout, [=](){ //jesli skonczy sie ten czas 500ms, to sprawdza czy jest
        if(m_up) {++m_value;} //true czy false i dodaje lub odejmuje
        else {--m_value;}
        emit valueChanged(m_value); //to nie potrzebuje body, to signal z Q_PROPERTY
    });

}

//  achievements apge
double BatteryValue::getWeeklyKmRun()
{
    return std::accumulate(kmRunInDay.begin(), kmRunInDay.end(), 0);
}

double BatteryValue::getLongestDistance()
{
    return *(std::max_element(kmRunInDay.begin(), kmRunInDay.end()));
}

double BatteryValue::getLongestDuration()
{
    return *(std::max_element(runningTime.begin(), runningTime.end())) / 60;
}

double BatteryValue::getBestPace()
{
    // return std::max_element(runningTime.begin(), runningTime.end());
    double bestPace = 0;
    for (int i = 0; i < 7; ++i)
    {
        if (runningTime[i] > 0)
            bestPace = std::max(kmRunInDay[i] / runningTime[i], bestPace);
    }
    return bestPace;
}

// weekly stats page
double BatteryValue::getAverageDuration()
{
    return std::accumulate(runningTime.begin(), runningTime.end(), 0) / (7 * 3600); // 3600 bc it's in sec
}

double BatteryValue::getAllDuration()
{
    return std::accumulate(runningTime.begin(), runningTime.end(), 0) /  60; // 3600 bc it's in sec
}
//there have to be an update function, or like calling all functions in a viewmodel every 10 seconds or something

int BatteryValue::value() const
{
    if(m_value < 0) return 0;
    else if(m_value > 100) return 100;
    return m_value;
}

void BatteryValue::setValue(const int& newValue)
{
    if (m_value == newValue)
        return;
    m_value = newValue;
    emit valueChanged(m_value);
}

bool BatteryValue::up() const
{
    return m_up;
}

void BatteryValue::setUp(const bool& newUp)
{
    if (m_up == newUp)
        return;
    m_up = newUp;
    emit upChanged(m_up);
}

void BatteryValue::start()
{
    qDebug() << "mtimer started";
    if(m_timer_ON == false){
        m_timer->start();
        m_timer_ON = true;
    }
    else{
        m_timer->stop();
        m_timer_ON = false;
    }
}

void BatteryValue::stop()
{
    qDebug() << "mtimer stoped";
    if(m_timer_ON == true){
        m_timer->stop();
        m_timer_ON = false;
    }
    else{
        m_timer->start();
        m_timer_ON = true;
    }
}

bool BatteryValue::timer_ON() const
{
    return m_timer_ON;
}

void BatteryValue::setTimer_ON(bool newTimer_ON)
{
    if (m_timer_ON == newTimer_ON)
        return;
    m_timer_ON = newTimer_ON;
    emit timer_ONChanged();
}