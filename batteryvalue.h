#ifndef BATTERYVALUE_H
#define BATTERYVALUE_H
#include <QTimer>
#include <QObject>
#include <array>
#include <algorithm>
#include "database.h"

class BatteryValue : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(bool up READ up WRITE setUp NOTIFY upChanged)
    Q_PROPERTY(bool timer_ON READ timer_ON WRITE setTimer_ON NOTIFY timer_ONChanged)

private:
    QTimer *m_timer;
    int m_value;
    bool m_up;
    bool m_timer_ON;

    std::array<double, 7> kmRunInDay = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    std::array<double, 7> runningTime = {1000.0, 2000.0, 3000.0, 4000.0, 5000.0, 6000.0, 7000.0}; // for now in seconds

    //    DataBase db("database9.db");

public:
    explicit BatteryValue(QObject *parent = nullptr);

    int value() const;
    void setValue(const int &newValue);
    bool up() const;
    void setUp(const bool &newUp);
    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();
    bool timer_ON() const;
    void setTimer_ON(bool newTimer_ON);

    //////////////////////////////////////////////////////
    // achievements page
    double getWeeklyKmRun();
    double getLongestDistance();
    double getLongestDuration();
    double getBestPace();

    // weekly stats page
    double getAverageDuration();
    double getAllDuration();

public slots:

signals:
    void valueChanged(const int &);
    void upChanged(const bool &);

    void timer_ONChanged();
};

#endif // BATTERYVALUE_H