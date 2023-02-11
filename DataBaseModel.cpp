#include "DataBaseModel.h"
#include <QDebug>
DataBaseModel::DataBaseModel(QObject *parent) : QObject(parent),
                                                m_weeklyKmRun(0),
                                                m_longestDistance(0),
                                                m_longestDuration(0),
                                                m_bestPace(0),
                                                m_averageDuration(0),
                                                m_allDuration(0)
{
    // initializeDataBase();
}

/**
 * @brief checks how many meters run in a current week, checks from vector in local data
 * @return qreal
 */
qreal DataBaseModel::weeklyKmRun()
{
    return m_weeklyKmRun;//returnDataBaseElementByName("WeeklyKmRun").first;
}

void DataBaseModel::setWeeklyKmRun(qreal newWeeklyKmRun)
{

    // qreal databaseValue = returnDataBaseElementByName("WeeklyKmRun").first;
    // qreal stdValue = std::accumulate(kmRunInDay.begin(), kmRunInDay.end(), 0);

    // m_weeklyKmRun = 0;//std::max_element({databaseValue, stdValue, newWeeklyKmRun, m_weeklyKmRun});

    // DataBase db("database_file.db");
    // if (db.isOpen())
    // {
    //     db.updateElement("WeeklyKmRun", m_weeklyKmRun, 0, 7); // day, meters, time
    //     qDebug() << "Updating database complete";
    // }
    // else qDebug() << "Database is not open!";

    // emit weeklyKmRunChanged();
}
/**
 * @brief gets most meters run in a day
 * @return qreal
 */
qreal DataBaseModel::longestDistance()
{
    if (m_longestDistance < *(std::max_element(kmRunInDay.begin(), kmRunInDay.end())))
    {
        m_longestDistance = *(std::max_element(kmRunInDay.begin(), kmRunInDay.end()));
    }
    return m_longestDistance;
}

void DataBaseModel::setLongestDistance(qreal newLongestDistance)
{
    if (qFuzzyCompare(m_longestDistance, newLongestDistance))
        return;
    m_longestDistance = newLongestDistance;
    emit longestDistanceChanged();
}
/**
 * @brief gets longest time in seconds
 *
 * @return qreal
 */
qreal DataBaseModel::longestDuration()
{
    if (m_longestDuration < *(std::max_element(runningTime.begin(), runningTime.end())))
    {
        m_longestDuration = *(std::max_element(runningTime.begin(), runningTime.end()));
    }
    return m_longestDuration;
}

void DataBaseModel::setLongestDuration(qreal newLongestDuration)
{
    if (qFuzzyCompare(m_longestDuration, newLongestDuration))
        return;
    m_longestDuration = newLongestDuration;
    emit longestDurationChanged();
}

/**
 * @brief best pace in m/s
 *
 * @return qreal
 */
qreal DataBaseModel::bestPace()
{
    double bestPace = 0.0;
    for (int i = 0; i < 7; ++i)
    {
        if (runningTime[i] > 0)
            bestPace = std::max(kmRunInDay[i] / runningTime[i], bestPace);
    }
    if (m_bestPace != bestPace)
    {
        m_bestPace = bestPace;
    }
    return m_bestPace;
}

void DataBaseModel::setBestPace(qreal newBestPace)
{
    if (qFuzzyCompare(m_bestPace, newBestPace))
        return;
    m_bestPace = newBestPace;
    emit bestPaceChanged();
}

/**
 * @brief average duration in seconds
 *
 * @return qreal
 */
qreal DataBaseModel::averageDuration()
{
    if (m_averageDuration < std::accumulate(runningTime.begin(), runningTime.end(), 0) / 7)
    {
        m_averageDuration = std::accumulate(runningTime.begin(), runningTime.end(), 0) / 7;
    }
    return m_averageDuration;
}

void DataBaseModel::setAverageDuration(qreal newAverageDuration)
{
    if (qFuzzyCompare(m_averageDuration, newAverageDuration))
        return;
    m_averageDuration = newAverageDuration;
    emit averageDurationChanged();
}
/**
 * @brief all duration in seconds
 *
 * @return qreal
 */
qreal DataBaseModel::allDuration()
{
    if (m_allDuration < std::accumulate(runningTime.begin(), runningTime.end(), 0))
    {
        m_allDuration = std::accumulate(runningTime.begin(), runningTime.end(), 0);
    }
    return m_allDuration;
}

void DataBaseModel::setAllDuration(qreal newAllDuration)
{
    if (qFuzzyCompare(m_allDuration, newAllDuration))
        return;
    m_allDuration = newAllDuration;
    emit allDurationChanged();
}

void DataBaseModel::setWeeklyGoal(int newWeeklyGoal)
{
    m_weeklyGoal = newWeeklyGoal;
    emit weeklyGoalChanged();
}

int DataBaseModel::weeklyGoal() const
{
    return returnDataBaseElementByName("Goal").first;
}

void DataBaseModel::setDailyGoal(int newDailyGoal)
{
    m_dailyGoal = newDailyGoal;
    emit dailyGoalChanged();
}

int DataBaseModel::dailyGoal() const
{
    return returnDataBaseElementByName("Goal").second;
}
// /////////////////////////////////////////////////////////////////////
// DAYS

void DataBaseModel::setMonday(int new_km, int new_time)
{
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement("Monday", new_km, new_time, 1); // day, meters, time
        qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";
    runningTime[0] = new_km;
    kmRunInDay[0] = new_time;
    emit monday_kmChanged();
    emit monday_timeChanged();
}

void DataBaseModel::setTuesday(int new_km, int new_time)
{
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement("Tuesday", new_km, new_time, 2); // day, meters, time
        qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";
    runningTime[1] = new_km;
    kmRunInDay[1] = new_time;
    emit tuesday_kmChanged();
    emit tuesday_timeChanged();
}

void DataBaseModel::setWednesday(int new_km, int new_time)
{
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement("Wednesday", new_km, new_time, 3); // day, meters, time
        qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";
    runningTime[2] = new_km;
    kmRunInDay[2] = new_time;
    emit wednesday_kmChanged();
    emit wednesday_timeChanged();
}

void DataBaseModel::setThursday(int new_km, int new_time)
{
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement("Thursday", new_km, new_time, 4); // day, meters, time
        qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";
    runningTime[3] = new_km;
    kmRunInDay[3] = new_time;
    emit thursday_kmChanged();
    emit thursday_timeChanged();
}

void DataBaseModel::setFriday(int new_km, int new_time)
{
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement("Friday", new_km, new_time, 5); // day, meters, time
        qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";
    runningTime[4] = new_km;
    kmRunInDay[4] = new_time;
    emit friday_kmChanged();
    emit friday_timeChanged();
}

void DataBaseModel::setSaturday(int new_km, int new_time)
{
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement("Monday", new_km, new_time, 6); // day, meters, time
        qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";
    runningTime[5] = new_km;
    kmRunInDay[5] = new_time;
    emit saturday_kmChanged();
    emit saturday_timeChanged();
}

void DataBaseModel::setSunday(int new_km, int new_time)
{
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement("Monday", new_km, new_time, 7); // day, meters, time
        qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";
    runningTime[6] = new_km;
    kmRunInDay[6] = new_time;
    emit sunday_kmChanged();
    emit sunday_timeChanged();
}

void DataBaseModel::emitDayChanges()
{
    emit weeklyKmRunChanged();
    emit longestDistanceChanged();
    emit longestDurationChanged();
    emit bestPaceChanged();
    emit averageDurationChanged();
    emit allDurationChanged();
}
void DataBaseModel::initializeDataBase()
{
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.clearDataBase();
        db.createTable();
        db.addElement("Monday", kmRunInDay[0], runningTime[0]); // day, meters, time
        db.addElement("Tuesday", kmRunInDay[1], runningTime[1]);
        db.addElement("Wednesday", kmRunInDay[2], runningTime[2]);
        db.addElement("Thursday", kmRunInDay[3], runningTime[3]);
        db.addElement("Friday", kmRunInDay[4], runningTime[4]);
        db.addElement("Saturday", kmRunInDay[5], runningTime[5]);
        db.addElement("Sunday", kmRunInDay[6], runningTime[6]);
        db.addElement("Goal", m_weeklyGoal, m_dailyGoal); //musze chociaz raz dodac te wszystkie maxy
        db.addElement("LongestRun", m_longestDistance, m_longestDuration);
        db.addElement("Duration", m_averageDuration, m_allDuration);
        db.addElement("WeeklyKmRun_BestPace", m_weeklyKmRun, m_bestPace);

        qDebug() << "Initialization complete";
    }
    else
        qDebug() << "Database is not open!";
}

void DataBaseModel::clearAllData()
{
    setMonday(0, 0);
    setTuesday(0, 0);
    setWednesday(0, 0);
    setThursday(0, 0);
    setFriday(0, 0);
    setSaturday(0, 0);
    setSunday(0, 0);
    // initializeDataBase();//i don't this this is needed TODO RETEST
}

std::pair<int, int> DataBaseModel::returnDataBaseElementByName(const QString &name) const
{
    std::pair<int, int> day;
    DataBase db("database_file.db");
    return db.returnDataBaseElementByName(name);
}

void DataBaseModel::printDataBase()
{
    DataBase db("database_file.db");
    if (db.isOpen()) db.printAll();
}

int DataBaseModel::monday_km() const
{
    return returnDataBaseElementByName("Monday").first;
}

int DataBaseModel::monday_time() const
{
    return returnDataBaseElementByName("Monday").second;
}

int DataBaseModel::tuesday_km() const
{
    return returnDataBaseElementByName("Tuesday").first;
}

int DataBaseModel::tuesday_time() const
{
    return returnDataBaseElementByName("Tuesday").second;
}

int DataBaseModel::wednesday_km() const
{
    return returnDataBaseElementByName("Wednesday").first;
}

int DataBaseModel::wednesday_time() const
{
    return returnDataBaseElementByName("Wednesday").second;
}

int DataBaseModel::thursday_km() const
{
    return returnDataBaseElementByName("Thursday").first;
}

int DataBaseModel::thursday_time() const
{
    return returnDataBaseElementByName("Thursday").second;
}

int DataBaseModel::friday_km() const
{
    return returnDataBaseElementByName("Friday").first;
}

int DataBaseModel::friday_time() const
{
    return returnDataBaseElementByName("Friday").second;
}

int DataBaseModel::saturday_km() const
{
    return returnDataBaseElementByName("Saturday").first;
}

int DataBaseModel::saturday_time() const
{
    return returnDataBaseElementByName("Saturday").second;
}

int DataBaseModel::sunday_km() const
{
    return returnDataBaseElementByName("Sunday").first;
}

int DataBaseModel::sunday_time() const
{
    return returnDataBaseElementByName("Sunday").second;
}


