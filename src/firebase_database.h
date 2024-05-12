#ifndef FIREBASEDATABASE_H
#define FIREBASEDATABASE_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class FirebaseDataBase : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int longestDistance READ longestDistance WRITE setLongestDistance NOTIFY longestDistanceChanged)
    Q_PROPERTY(int longestDuration READ longestDuration WRITE setLongestDuration NOTIFY longestDurationChanged)
    Q_PROPERTY(int bestPace READ bestPace WRITE setBestPace NOTIFY bestPaceChanged)
    Q_PROPERTY(int weeklyGoal READ weeklyGoal WRITE setWeeklyGoal NOTIFY weeklyGoalChanged) // how many meters we want to run in a week
    Q_PROPERTY(int dailyGoal READ dailyGoal WRITE setDailyGoal NOTIFY dailyGoalChanged)    // or day

public:
    explicit FirebaseDataBase(QObject *parent = nullptr);
    ~FirebaseDataBase();
public slots:
    void networkReplyReadyRead();

    Q_INVOKABLE void testFirebaseFunc();
    Q_INVOKABLE void readFirebaseData(const QString&); 
    Q_INVOKABLE void postValues(const QString&);
    Q_INVOKABLE void putValues(const QString&);

//methods for Q_PROPERTY
    void setLongestDistance(int newLongestDistance);
    void setLongestDuration(int newLongestDuration);
    void setBestPace(int newBestPace);
    void setWeeklyGoal(int newWeeklyGoal);
    void setDailyGoal(int newDailyGoal);

    int longestDuration();
    int longestDistance();
    int bestPace();
    int weeklyGoal();
    int dailyGoal();

signals:
    void longestDistanceChanged();
    void longestDurationChanged();
    void bestPaceChanged();
    void weeklyGoalChanged();
    void dailyGoalChanged();

private:
    QNetworkAccessManager *m_networkManager;
    QNetworkReply *m_networkReply;

    int m_weeklyKmRun = 0;
    int m_longestDistance = 0;
    int m_longestDuration = 0;
    int m_bestPace = 0;
    int m_weeklyGoal = 0;
    int m_dailyGoal = 0;

};

#endif // FIREBASEDATABASE_H
