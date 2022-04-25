#ifndef DATABASE_ADAPTER_H
#define DATABASE_ADAPTER_H
#include <QObject>
#include <iostream>
#include <array>
#include <algorithm>
#include "database.h"

class DataBaseAdapter : public QObject
{
private:
    std::array<double, 7> kmRunInDay = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    std::array<double, 7> runningTime = {1000.0, 2000.0, 3000.0, 4000.0, 5000.0, 6000.0, 7000.0}; // for now in seconds

//    DataBase db("database9.db");

public:
    //    DataBaseAdapter();
       explicit DataBaseAdapter(QObject *parent = nullptr);

       ~DataBaseAdapter();

    // achievements page
    double getWeeklyKmRun();
    double getLongestDistance();
    double getLongestDuration();
    double getBestPace();

    // weekly stats page
    double getAverageDuration();
    double getAllDuration();
};

#endif // DATABASE_ADAPTER_H
