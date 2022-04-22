#include "DataBaseAdapter.h"

//  achievements apge
double DataBaseAdapter::getWeeklyKmRun()
{
    return std::accumulate(kmRunInDay.begin(), kmRunInDay.end(), 0);
}

double DataBaseAdapter::getLongestDistance()
{
    return *(std::max_element(kmRunInDay.begin(), kmRunInDay.end()));
}

double DataBaseAdapter::getLongestDuration()
{
    return *(std::max_element(runningTime.begin(), runningTime.end())) / 60;
}

double DataBaseAdapter::getBestPace()
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
double DataBaseAdapter::averageDuration()
{
    return std::accumulate(runningTime.begin(), runningTime.end(), 0) / (7 * 3600); // 3600 bc it's in sec
}
