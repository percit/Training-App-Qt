#include "../inc/DataBaseModel.h"
#include <QDebug>
DataBaseModel::DataBaseModel(QObject *parent) : QObject(parent),
                                                m_weeklyKmRun(0),
                                                m_longestDistance(0),
                                                m_longestDuration(0),
                                                m_bestPace(0),
                                                m_averageDuration(0),
                                                m_allDuration(0)
{
    qDebug() << "created DataBaseModel constructor";
    initializeDataBase();
}

/**
 * @brief checks how many meters run in a current week, checks from vector in local data
 * @return qreal
 */
qreal DataBaseModel::weeklyKmRun()
{
    if (m_weeklyKmRun != std::accumulate(kmRunInDay.begin(), kmRunInDay.end(), 0))
    {
        m_weeklyKmRun = std::accumulate(kmRunInDay.begin(), kmRunInDay.end(), 0);
    }
    return m_weeklyKmRun;
}
/**
 * @brief gets most meters run in a day
 * @return qreal
 */
qreal DataBaseModel::longestDistance()
{
    if (m_longestDistance != *(std::max_element(kmRunInDay.begin(), kmRunInDay.end())))
    {
        m_longestDistance = *(std::max_element(kmRunInDay.begin(), kmRunInDay.end()));
    }
    return m_longestDistance;
}
/**
 * @brief gets longest time in seconds
 *
 * @return qreal
 */
qreal DataBaseModel::longestDuration()
{
    if (m_longestDuration != *(std::max_element(runningTime.begin(), runningTime.end())))
    {
        m_longestDuration = *(std::max_element(runningTime.begin(), runningTime.end()));
    }
    return m_longestDuration;
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
/**
 * @brief average duration in seconds
 *
 * @return qreal
 */
qreal DataBaseModel::averageDuration()
{
    if (m_averageDuration != std::accumulate(runningTime.begin(), runningTime.end(), 0) / 7)
    {
        m_averageDuration = std::accumulate(runningTime.begin(), runningTime.end(), 0) / 7;
    }
    return m_averageDuration;
}
/**
 * @brief all duration in seconds
 *
 * @return qreal
 */
qreal DataBaseModel::allDuration()
{
    if (m_allDuration != std::accumulate(runningTime.begin(), runningTime.end(), 0))
    {
        m_allDuration = std::accumulate(runningTime.begin(), runningTime.end(), 0);
    }
    return m_allDuration;
}

int DataBaseModel::weeklyGoal() const
{
    return m_weeklyGoal;
}

int DataBaseModel::daylyGoal() const
{
    return m_daylyGoal;
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

void DataBaseModel::setWeeklyGoal(int newWeeklyGoal)
{
    m_weeklyGoal = newWeeklyGoal;
    emit weeklyGoalChanged();
}

void DataBaseModel::setDaylyGoal(int newDaylyGoal)
{
    m_daylyGoal = newDaylyGoal;
    emit weeklyGoalChanged();
}

// /////////////////////////////////////////////////////////////////////
// DAYS

int const DataBaseModel::monday_km() const
{
    return returnDataBaseElementByName("Monday").first;
}

void DataBaseModel::emitDayChanges()
{
    emit weeklyKmRunChanged();
    emit longestDistanceChanged();
    emit longestDurationChanged();
    emit bestPaceChanged();
    emit averageDurationChanged();
    emit allDurationChanged();
    qDebug() << "emitDayChanges";
}

void DataBaseModel::setMonday_km(int newMonday_km)
{
    if (m_monday_km == newMonday_km)
        return;
    m_monday_km = newMonday_km;
    kmRunInDay[0] = m_monday_km;
    emit monday_kmChanged();
    emitDayChanges();
}

int DataBaseModel::monday_time() const
{
    return returnDataBaseElementByName("Monday").second;
}

void DataBaseModel::setMonday_time(int newMonday_time)
{
    if (m_monday_time == newMonday_time)
        return;
    m_monday_time = newMonday_time;
    runningTime[0] = m_monday_time;
    emit monday_timeChanged();
    emitDayChanges();
}

int DataBaseModel::tuesday_km() const
{
    return returnDataBaseElementByName("Tuesday").first;
}

void DataBaseModel::setTuesday_km(int newTuesday_km)
{
    if (m_tuesday_km == newTuesday_km)
        return;
    m_tuesday_km = newTuesday_km;
    kmRunInDay[1] = m_tuesday_km;
    emit tuesday_kmChanged();
    emitDayChanges();
}

int DataBaseModel::tuesday_time() const
{
    return returnDataBaseElementByName("Tuesday").second;
}

void DataBaseModel::setTuesday_time(int newTuesday_time)
{
    if (m_tuesday_time == newTuesday_time)
        return;
    m_tuesday_time = newTuesday_time;
    runningTime[1] = m_tuesday_time;
    emit tuesday_timeChanged();
    emitDayChanges();
}

int DataBaseModel::wednesday_km() const
{
    return returnDataBaseElementByName("Wednesday").first;
}

void DataBaseModel::setWednesday_km(int newWednesday_km)
{
    if (m_wednesday_km == newWednesday_km)
        return;
    m_wednesday_km = newWednesday_km;
    kmRunInDay[2] = m_wednesday_km;
    emit wednesday_kmChanged();
    emitDayChanges();
}

int DataBaseModel::wednesday_time() const
{
    return returnDataBaseElementByName("Wednesday").second;
}

void DataBaseModel::setWednesday_time(int newWednesday_time)
{
    if (m_wednesday_time == newWednesday_time)
        return;
    m_wednesday_time = newWednesday_time;
    runningTime[2] = m_wednesday_time;
    emit wednesday_timeChanged();
    emitDayChanges();
}

int DataBaseModel::thursday_km() const
{
    return returnDataBaseElementByName("Thursday").first;
}

void DataBaseModel::setThursday_km(int newThursday_km)
{
    if (m_thursday_km == newThursday_km)
        return;
    m_thursday_km = newThursday_km;
    kmRunInDay[3] = m_thursday_km;
    emit thursday_kmChanged();
    emitDayChanges();
}

int DataBaseModel::thursday_time() const
{
    return returnDataBaseElementByName("Thursday").second;
}

void DataBaseModel::setThursday_time(int newThursday_time)
{
    if (m_thursday_time == newThursday_time)
        return;
    m_thursday_time = newThursday_time;
    runningTime[3] = m_thursday_time;
    emit thursday_timeChanged();
    emitDayChanges();
}

int DataBaseModel::friday_km() const
{
    return returnDataBaseElementByName("Friday").first;
}

void DataBaseModel::setFriday_km(int newFriday_km)
{
    if (m_friday_km == newFriday_km)
        return;
    m_friday_km = newFriday_km;
    kmRunInDay[4] = m_friday_km;
    emit friday_kmChanged();
    emitDayChanges();
}

int DataBaseModel::friday_time() const
{
    return returnDataBaseElementByName("Friday").second;
}

void DataBaseModel::setFriday_time(int newFriday_time)
{
    if (m_friday_time == newFriday_time)
        return;
    m_friday_time = newFriday_time;
    runningTime[4] = m_friday_time;
    emit friday_timeChanged();
    emitDayChanges();
}

int DataBaseModel::saturday_km() const
{
    return returnDataBaseElementByName("Saturday").first;
}

void DataBaseModel::setSaturday_km(int newSaturday_km)
{
    if (m_saturday_km == newSaturday_km)
        return;
    m_saturday_km = newSaturday_km;
    kmRunInDay[5] = m_saturday_km;
    emit saturday_kmChanged();
    emitDayChanges();
}

int DataBaseModel::saturday_time() const
{
    return returnDataBaseElementByName("Saturday").second;
}

void DataBaseModel::setSaturday_time(int newSaturday_time)
{
    if (m_saturday_time == newSaturday_time)
        return;
    m_saturday_time = newSaturday_time;
    runningTime[5] = m_saturday_time;
    emit saturday_timeChanged();
    emitDayChanges();
}

int DataBaseModel::sunday_km() const
{
    return returnDataBaseElementByName("Sunday").first;
}

void DataBaseModel::setSunday_km(int newSunday_km)
{
    if (m_sunday_km == newSunday_km)
        return;
    m_sunday_km = newSunday_km;
    kmRunInDay[6] = m_sunday_km;
    emit sunday_kmChanged();
    emitDayChanges();
}

int DataBaseModel::sunday_time() const
{
    return returnDataBaseElementByName("Sunday").second;
}

void DataBaseModel::setSunday_time(int newSunday_time)
{
    if (m_sunday_time == newSunday_time)
        return;
    m_sunday_time = newSunday_time;
    runningTime[6] = m_sunday_time;
    emit sunday_timeChanged();
    emitDayChanges();
}

void DataBaseModel::initializeDataBase()
{
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.clearDataBase(); // temporary solution
        db.createTable();
        db.addElement("Monday", kmRunInDay[0], runningTime[0]); // day, meters, time
        db.addElement("Tuesday", kmRunInDay[1], runningTime[1]);
        db.addElement("Wednesday", kmRunInDay[2], runningTime[2]);
        db.addElement("Thursday", kmRunInDay[3], runningTime[3]);
        db.addElement("Friday", kmRunInDay[4], runningTime[4]);
        db.addElement("Saturday", kmRunInDay[5], runningTime[5]);
        db.addElement("Sunday", kmRunInDay[6], runningTime[6]);

        qDebug() << "Initialization complete";
    }
    else
        qDebug() << "Database is not open!";
}

void DataBaseModel::updateDataBaseFile()
{
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.clearDataBase();                                     // there should be function with update, and taking day name as parameter
        db.addElement("Monday", kmRunInDay[0], runningTime[0]); // day, meters, time
        db.addElement("Tuesday", kmRunInDay[1], runningTime[1]);
        db.addElement("Wednesday", kmRunInDay[2], runningTime[2]);
        db.addElement("Thursday", kmRunInDay[3], runningTime[3]);
        db.addElement("Friday", kmRunInDay[4], runningTime[4]);
        db.addElement("Saturday", kmRunInDay[5], runningTime[5]);
        db.addElement("Sunday", kmRunInDay[6], runningTime[6]);

        qDebug() << "Updating database complete";
    }
    else
        qDebug() << "Database is not open!";

    qDebug() << "updateDataBaseFile";
}

void DataBaseModel::testDataBase()
{
    DataBase db("database_file_test.db");
    if (db.isOpen())
    {
        db.clearDataBase();            // temporary solution
        db.addElement("Monday", 0, 0); // day, meters, time
        db.addElement("Tuesday", 1, 1);
        db.addElement("Wednesday", 2, 2);
        db.addElement("Thursday", 3, 3);
        db.addElement("Friday", 4, 4);
        db.addElement("Saturday", 5, 5);
        db.addElement("Sunday", 6, 6);

        qDebug() << "Test done ";
    }
    else
        qDebug() << "Database is not open!";
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
    if (db.isOpen())
        db.printAll();
}
