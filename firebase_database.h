#ifndef FIREBASEDATABASE_H
#define FIREBASEDATABASE_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class FirebaseDataBase : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int weeklyKmRun READ weeklyKmRun WRITE setWeeklyKmRun NOTIFY weeklyKmRunChanged)
    Q_PROPERTY(int longestDistance READ longestDistance WRITE setLongestDistance NOTIFY longestDistanceChanged)
    Q_PROPERTY(int longestDuration READ longestDuration WRITE setLongestDuration NOTIFY longestDurationChanged)
    Q_PROPERTY(int bestPace READ bestPace WRITE setBestPace NOTIFY bestPaceChanged)
    Q_PROPERTY(int averageDuration READ averageDuration WRITE setAverageDuration NOTIFY averageDurationChanged)
    Q_PROPERTY(int allDuration READ allDuration WRITE setAllDuration NOTIFY allDurationChanged)
    Q_PROPERTY(int weeklyGoal READ weeklyGoal WRITE setWeeklyGoal NOTIFY weeklyGoalChanged) // how many meters we want to run in a week
    Q_PROPERTY(int dailyGoal READ dailyGoal WRITE setDailyGoal NOTIFY dailyGoalChanged)    // or day


public:
    explicit FirebaseDataBase(QObject *parent = nullptr);
    ~FirebaseDataBase();
public slots:
    void networkReplyReadyRead();

    Q_INVOKABLE void testFirebaseFunc();
    Q_INVOKABLE void testFirebaseFuncWithMail(const QString&); 

//methods for Q_PROPERTY
    void setWeeklyKmRun(int newWeeklyKmRun);
    void setLongestDistance(int newLongestDistance);
    void setLongestDuration(int newLongestDuration);
    void setBestPace(int newBestPace);
    void setAverageDuration(int newAverageDuration);
    void setAllDuration(int newAllDuration);
    void setWeeklyGoal(int newWeeklyGoal);
    void setDailyGoal(int newDailyGoal);

    int weeklyKmRun();
    int longestDuration();
    int longestDistance();
    int bestPace();
    int averageDuration();
    int allDuration();
    int weeklyGoal();
    int dailyGoal();

signals:
    void weeklyKmRunChanged(); 
    void longestDistanceChanged();
    void longestDurationChanged();
    void bestPaceChanged();
    void averageDurationChanged();
    void allDurationChanged();
    void weeklyGoalChanged();
    void dailyGoalChanged();

private:
    QNetworkAccessManager *m_networkManager;
    QNetworkReply *m_networkReply;

    int m_weeklyKmRun = 0;
    int m_longestDistance = 0;
    int m_longestDuration = 0;
    int m_bestPace = 0;
    int m_averageDuration = 0;
    int m_allDuration = 0;
    int m_weeklyGoal = 0;
    int m_dailyGoal = 0;

};

#endif // FIREBASEDATABASE_H
