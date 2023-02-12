import QtQuick 2.3
import DataBaseModel 1.0
import "../Helper.js" as Helper
import FirebaseDataBase 1.0

QtObject {
    readonly property string weeklyKmRun: Helper.formatDistance(DbModel.weeklyKmRun)
    readonly property string longestDistance: Helper.formatDistance(DbModel.longestDistance)
    readonly property string longestDuration: Helper.formatDistance(DbModel.longestDuration)
    readonly property string averageDuration: Helper.formatDistance(DbModel.averageDuration)
    readonly property string allDuration: Helper.formatDistance(DbModel.allDuration)
	readonly property string bestPace: Math.round(DbModel.bestPace * 3.6 * 100) / 100
	readonly property int weeklyGoalInMeters: DbModel.weeklyGoal * 1000
    readonly property int daylyGoalInMeters: DbModel.daylyGoal * 1000
    readonly property int totalKcalRun: Math.round(DbModel.weeklyKmRun * 100) / 100 * 62

    readonly property double progressBarMonday: (DbModel.monday_km / daylyGoalInMeters > 1) ? 1 : DbModel.monday_km / daylyGoalInMeters
    readonly property double progressBarTuesday: (DbModel.tuesday_km / daylyGoalInMeters > 1) ? 1 : DbModel.tuesday_km / daylyGoalInMeters
    readonly property double progressBarWednesday: (DbModel.wednesday_km / daylyGoalInMeters > 1) ? 1 : DbModel.wednesday_km / daylyGoalInMeters
    readonly property double progressBarThursday: (DbModel.thursday_km / daylyGoalInMeters > 1) ? 1 : DbModel.thursday_km / daylyGoalInMeters
    readonly property double progressBarFriday: (DbModel.friday_km / daylyGoalInMeters > 1) ? 1 : DbModel.friday_km / daylyGoalInMeters
    readonly property double progressBarSaturday: (DbModel.saturday_km / daylyGoalInMeters > 1) ? 1 : DbModel.saturday_km / daylyGoalInMeters
    readonly property double progressBarSunday: (DbModel.sunday_km / daylyGoalInMeters > 1) ? 1 : DbModel.sunday_km / daylyGoalInMeters

    readonly property Timer refreshFirebaseTimer : Timer {
        interval: 3600000 //24h
        running: true
        repeat: true
        onTriggered: {
            DbModel.updateAllMaxes();
            FbDatabase.setLongestDistance(DbModel.longestDistance);
            FbDatabase.setLongestDuration(DbModel.longestDuration);
            FbDatabase.setLongestDistance(DbModel.longestDistance);
            FbDatabase.setBestPace(DbModel.bestPace);
            FbDatabase.setDailyGoal(DbModel.dailyGoal);
            FbDatabase.setWeeklyGoal(DbModel.weeklyGoal);
            FbDatabase.putValues(DbModel.mail)
        }
    }
}

