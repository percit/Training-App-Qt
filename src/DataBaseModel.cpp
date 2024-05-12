#include "DataBaseModel.h"
#include <QDebug>
DataBaseModel::DataBaseModel(QObject *parent) : QObject(parent),
                                                m_weeklyMetersRun(0),
                                                m_longestDistance(0),
                                                m_longestDuration(0),
                                                m_bestPace(0),
                                                m_averageDuration(0),
                                                m_allDuration(0),
                                                m_weekMeters(7, 0),
                                                m_weekTime(7, 0)
{
    // initializeDataBase();
}

void DataBaseModel::updateAllMaxes() 
{
    int newLongestDistance = *(std::max_element(m_weekMeters.begin(), m_weekMeters.end()));
    if(newLongestDistance > longestDistance())
    {
        setLongestDistance(newLongestDistance);
    }
    
    int newLongestDuration = *(std::max_element(m_weekTime.begin(), m_weekTime.end()));
    if(newLongestDuration > longestDuration())
    {
        setLongestDuration(newLongestDuration);
    }

    int newweeklyMetersRun = std::accumulate(m_weekMeters.begin(), m_weekMeters.end(), 0);
    if(newweeklyMetersRun > weeklyMetersRun())
    {
        setweeklyMetersRun(newweeklyMetersRun);
    }

    int newBestPace = 0;
    for (int i = 0; i < 7; ++i)
    {
        if (m_weekTime[i] > 0) newBestPace = std::max(m_weekMeters[i] / m_weekTime[i], newBestPace);
    }
    if(newBestPace > bestPace())
    {
        setBestPace(newBestPace);
    }

    int newAverageDuration = std::accumulate(m_weekTime.begin(), m_weekTime.end(), 0) / 7;
    if(newAverageDuration > averageDuration())
    {
        setAverageDuration(newAverageDuration);
    }

    int newAllDuration = std::accumulate(m_weekTime.begin(), m_weekTime.end(), 0);
    if(newAllDuration > allDuration())
    {
        setAllDuration(newAllDuration);
    }
}

void DataBaseModel::emitDayChanges()
{
    emit weeklyMetersRunChanged();
    emit longestDistanceChanged();
    emit longestDurationChanged();
    emit bestPaceChanged();
    emit averageDurationChanged();
    emit allDurationChanged();
}
void DataBaseModel::initializeDataBase()
{
    
    // DataBase db("database_file.db");
    // if (db.isOpen())
    // {
    //     db.clearDataBase();
    //     db.createTable();
    //     db.addElement("Monday", m_weekMeters[0], m_weekTime[0]); // day, meters, time
    //     db.addElement("Tuesday", m_weekMeters[1], m_weekTime[1]);
    //     db.addElement("Wednesday", m_weekMeters[2], m_weekTime[2]);
    //     db.addElement("Thursday", m_weekMeters[3], m_weekTime[3]);
    //     db.addElement("Friday", m_weekMeters[4], m_weekTime[4]);
    //     db.addElement("Saturday", m_weekMeters[5], m_weekTime[5]);
    //     db.addElement("Sunday", m_weekMeters[6], m_weekTime[6]);
    //     db.addElement("Goal", m_weeklyGoal, m_dailyGoal);
    //     db.addElement("LongestRun", m_longestDistance, m_longestDuration);
    //     db.addElement("Duration", m_averageDuration, m_allDuration);
    //     db.addElement("weeklyMetersRun_BestPace", m_weeklyMetersRun, m_bestPace);
    //     db.addMail("Mail", m_mail);

    //     qDebug() << "Initialization complete";
    // }
    // else
    //     qDebug() << "Database is not open!";
}

void DataBaseModel::clearAllData()
{
    setWeek("Monday", 0, 0);
    setWeek("Tuesday", 0, 0);
    setWeek("Wednesday", 0, 0);
    setWeek("Thursday", 0, 0);
    setWeek("Friday", 0, 0);
    setWeek("Saturday", 0, 0);
    setWeek("Sunday", 0, 0);
    

    setweeklyMetersRun(0);
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
    qDebug() << newWeeklyGoal << " " << m_weeklyGoal;//to dziala
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

void DataBaseModel::setLongestDistance(int newLongestDistance)
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

void DataBaseModel::setLongestDuration(int newLongestDuration)
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

void DataBaseModel::setAverageDuration(int newAverageDuration)
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

void DataBaseModel::setAllDuration(int newAllDuration)
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

void DataBaseModel::setweeklyMetersRun(int newweeklyMetersRun)
{
    m_weeklyMetersRun = std::max(m_weeklyMetersRun, newweeklyMetersRun);
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement("weeklyMetersRun_BestPace", m_weeklyMetersRun, m_bestPace, 11); // day, meters, time
        // qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";

    emit weeklyMetersRunChanged();
}

void DataBaseModel::setBestPace(int newBestPace)
{
    m_bestPace = std::max(m_bestPace, newBestPace);
    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement("weeklyMetersRun_BestPace", m_weeklyMetersRun, m_bestPace, 11); // day, meters, time
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

void DataBaseModel::setWeek(QString day, int new_meters, int new_time) {

    DataBase db("database_file.db");
    if (db.isOpen())
    {
        db.updateElement(day, new_meters, new_time, 1); // day, meters, time
        // qDebug() << "Updating database complete";
    }
    else qDebug() << "Database is not open!";


    m_weekMeters[returnNumberFromDay(day)] = new_meters;
    m_weekTime[returnNumberFromDay(day)] = new_time;
    emit weekMetersChanged();
    emit weekTimeChanged();
}

int DataBaseModel::returnNumberFromDay(QString day) {
    QVector<QString> days;
    days << "Monday" <<  "Tuesday" << "Wednesday" << "Thursday" << "Friday" << "Saturday" << "Sunday";
    return days.indexOf(day);
}

int DataBaseModel::weeklyGoal() const
{
    return m_weeklyGoal;
    // return returnDataBaseElementByName("Goal").first;
}

int DataBaseModel::dailyGoal() const
{
    return m_dailyGoal;
    // return returnDataBaseElementByName("Goal").second;
}

int DataBaseModel::weeklyMetersRun()
{
    return m_weeklyMetersRun;
    // return returnDataBaseElementByName("weeklyMetersRun_BestPace").first;
}

int DataBaseModel::bestPace()
{
    return m_bestPace;
    // return returnDataBaseElementByName("weeklyMetersRun_BestPace").second;
}

int DataBaseModel::longestDistance()
{
    return m_longestDistance;
    // return returnDataBaseElementByName("LongestRun").first;
}

int DataBaseModel::longestDuration()
{
    return m_longestDuration;
    // return returnDataBaseElementByName("LongestRun").second;
}

int DataBaseModel::averageDuration()
{
    return m_averageDuration;
    // return returnDataBaseElementByName("Duration").first;
}

int DataBaseModel::allDuration()
{
    return m_allDuration;
    // return returnDataBaseElementByName("Duration").second;
}

QString DataBaseModel::mail()
{
    return m_mail;
    // return returnMail("Mail");
}


QVector<int> DataBaseModel::weekMeters() const
{
    return m_weekMeters;
}
QVector<int> DataBaseModel::weekTime() const
{
    return m_weekTime;
}