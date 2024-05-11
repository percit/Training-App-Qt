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

void DataBaseModel::updateAllMaxes() 
{
    qreal newLongestDistance = *(std::max_element(kmRunInDay.begin(), kmRunInDay.end()));
    if(newLongestDistance > longestDistance())
    {
        setLongestDistance(newLongestDistance);
    }
    
    qreal newLongestDuration = *(std::max_element(runningTime.begin(), runningTime.end()));
    if(newLongestDuration > longestDuration())
    {
        setLongestDuration(newLongestDuration);
    }

    qreal newWeeklyKmRun = std::accumulate(kmRunInDay.begin(), kmRunInDay.end(), 0);
    if(newWeeklyKmRun > weeklyKmRun())
    {
        setWeeklyKmRun(newWeeklyKmRun);
    }

    qreal newBestPace = 0;
    for (int i = 0; i < 7; ++i)
    {
        if (runningTime[i] > 0) newBestPace = std::max(kmRunInDay[i] / runningTime[i], newBestPace);
    }
    if(newBestPace > bestPace())
    {
        setBestPace(newBestPace);
    }

    qreal newAverageDuration = std::accumulate(runningTime.begin(), runningTime.end(), 0) / 7;
    if(newAverageDuration > averageDuration())
    {
        setAverageDuration(newAverageDuration);
    }

    qreal newAllDuration = std::accumulate(runningTime.begin(), runningTime.end(), 0);
    if(newAllDuration > allDuration())
    {
        setAllDuration(newAllDuration);
    }
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
        db.addElement("Goal", m_weeklyGoal, m_dailyGoal);
        db.addElement("LongestRun", m_longestDistance, m_longestDuration);
        db.addElement("Duration", m_averageDuration, m_allDuration);
        db.addElement("WeeklyKmRun_BestPace", m_weeklyKmRun, m_bestPace);
        db.addMail("Mail", m_mail);

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

    setWeeklyKmRun(0);
    setLongestDistance(0);
    setLongestDuration(0);
    setBestPace(0);
    setAverageDuration(0);
    setAllDuration(0);
    setWeeklyGoal(0);
    setDailyGoal(0);
    setMail("");
    // qDebug() << "CLEAR ALL DATA";
}

std::pair<int, int> DataBaseModel::returnDataBaseElementByName(const QString &name) const
{
    DataBase db("database_file.db");
    return db.returnDataBaseElementByName(name);
}

QString DataBaseModel::returnMail(const QString &name)
{
    DataBase db("database_file.db");
    return db.returnMail(name);
}

void DataBaseModel::printDataBase()
{
    DataBase db("database_file.db");
    if (db.isOpen()) db.printAll();
}

void DataBaseModel::setWeeklyGoal(int newWeeklyGoal)
{
    m_weeklyGoal = std::max(m_weeklyGoal, newWeeklyGoal);
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement("Goal", m_weeklyGoal, m_dailyGoal, 8); // day, meters, time
        // qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";
    emit weeklyGoalChanged();
}

void DataBaseModel::setDailyGoal(int newDailyGoal)
{
    m_dailyGoal = std::max(m_dailyGoal, newDailyGoal);
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement("Goal", m_weeklyGoal, m_dailyGoal, 8); // day, meters, time
        // qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";
    emit dailyGoalChanged();
}

void DataBaseModel::setLongestDistance(qreal newLongestDistance)
{
    m_longestDistance = std::max(m_longestDistance, newLongestDistance);
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement("LongestRun", m_longestDuration, m_averageDuration, 9); // day, meters, time
        // qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";
    emit longestDistanceChanged();
}

void DataBaseModel::setLongestDuration(qreal newLongestDuration)
{
    m_longestDuration = std::max(m_longestDuration, newLongestDuration);
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement("LongestRun", m_longestDuration, m_averageDuration, 9); // day, meters, time
        // qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";
    emit longestDurationChanged();
}

void DataBaseModel::setAverageDuration(qreal newAverageDuration)
{
    m_averageDuration = std::max(m_averageDuration, newAverageDuration);
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement("Duration", m_averageDuration, m_allDuration, 10); // day, meters, time
        // qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";
    emit averageDurationChanged();
}

void DataBaseModel::setAllDuration(qreal newAllDuration)
{
    m_allDuration = std::max(m_allDuration, newAllDuration);
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement("Duration", m_averageDuration, m_allDuration, 10); // day, meters, time
        // qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";
    emit allDurationChanged();
}

void DataBaseModel::setWeeklyKmRun(qreal newWeeklyKmRun)
{
    m_weeklyKmRun = std::max(m_weeklyKmRun, newWeeklyKmRun);
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement("WeeklyKmRun_BestPace", m_weeklyKmRun, m_bestPace, 11); // day, meters, time
        // qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";

    emit weeklyKmRunChanged();
}

void DataBaseModel::setBestPace(qreal newBestPace)
{
    m_bestPace = std::max(m_bestPace, newBestPace);
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement("WeeklyKmRun_BestPace", m_weeklyKmRun, m_bestPace, 11); // day, meters, time
        // qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";
    emit bestPaceChanged();
}

void DataBaseModel::setMail(QString newMail)
{
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateMail("Mail", newMail, 12); // day, meters, time
        // qDebug() << "setmail";
        // qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";
    emit mailChanged();
}

// /////////////////////////////////////////////////////////////////////
// DAYS

void DataBaseModel::setMonday(int new_km, int new_time)
{
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement("Monday", new_km, new_time, 1); // day, meters, time
        // qDebug() << "Updating database complete";
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
        // qDebug() << "Updating database complete";
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
        // qDebug() << "Updating database complete";
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
        // qDebug() << "Updating database complete";
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
        // qDebug() << "Updating database complete";
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
        db.updateElement("Saturday", new_km, new_time, 6); // day, meters, time
        // qDebug() << "Updating database complete";
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
        db.updateElement("Sunday", new_km, new_time, 7); // day, meters, time
        // qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";
    runningTime[6] = new_km;
    kmRunInDay[6] = new_time;
    emit sunday_kmChanged();
    emit sunday_timeChanged();
}

int DataBaseModel::weeklyGoal() const
{
    return returnDataBaseElementByName("Goal").first;
}

int DataBaseModel::dailyGoal() const
{
    return returnDataBaseElementByName("Goal").second;
}

qreal DataBaseModel::weeklyKmRun()
{
    return returnDataBaseElementByName("WeeklyKmRun_BestPace").first;
}

qreal DataBaseModel::bestPace()
{
    return returnDataBaseElementByName("WeeklyKmRun_BestPace").second;
}

qreal DataBaseModel::longestDistance()
{
    return returnDataBaseElementByName("LongestRun").first;
}

qreal DataBaseModel::longestDuration()
{
    return returnDataBaseElementByName("LongestRun").second;
}

qreal DataBaseModel::averageDuration()
{
    return returnDataBaseElementByName("Duration").first;
}

qreal DataBaseModel::allDuration()
{
    return returnDataBaseElementByName("Duration").second;
}

QString DataBaseModel::mail()
{
    return returnMail("Mail");
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


