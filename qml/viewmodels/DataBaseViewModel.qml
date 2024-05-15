import QtQuick 2.3
import DataBaseModel 1.0
import "../Helper.js" as Helper
import FirebaseDataBase 1.0

QtObject {
    readonly property string weeklyKmRun: Helper.formatDistance(DbModel.weeklyMetersRun) //here we format meters to km
    readonly property string longestDistance: Helper.formatDistance(DbModel.longestDistance)
    readonly property string longestDuration: Helper.formatDistance(DbModel.longestDuration)
    readonly property string averageDuration: Helper.formatDistance(DbModel.averageDuration)
    readonly property string allDuration: Helper.formatDistance(DbModel.allDuration)
	readonly property string bestPace: Math.round(DbModel.bestPace * 3.6 * 100) / 100
	readonly property string weeklyGoalInKm: Helper.formatDistance(DbModel.weeklyGoal)
    readonly property string dailyGoalInKm: Helper.formatDistance(DbModel.dailyGoal)
    readonly property int totalKcalRun: Math.round(DbModel.weeklyMetersRun * 0.1) //average
    readonly property int radialProgressBarValue: DbModel.weeklyMetersRun / DbModel.weeklyGoal

    readonly property double progressBarMonday: (DbModel.weekMeters[0] / DbModel.dailyGoal > 1) ? 1 : DbModel.weekMeters[0]  / DbModel.dailyGoal
    readonly property double progressBarTuesday: (DbModel.weekMeters[1] / DbModel.dailyGoal > 1) ? 1 : DbModel.weekMeters[1] / DbModel.dailyGoal
    readonly property double progressBarWednesday: (DbModel.weekMeters[2] / DbModel.dailyGoal > 1) ? 1 : DbModel.weekMeters[2] / DbModel.dailyGoal
    readonly property double progressBarThursday: (DbModel.weekMeters[3] / DbModel.dailyGoal > 1) ? 1 : DbModel.weekMeters[3] / DbModel.dailyGoal
    readonly property double progressBarFriday: (DbModel.weekMeters[4] / DbModel.dailyGoal > 1) ? 1 : DbModel.weekMeters[4] / DbModel.dailyGoal
    readonly property double progressBarSaturday: (DbModel.weekMeters[5] / DbModel.dailyGoal > 1) ? 1 : DbModel.weekMeters[5] / DbModel.dailyGoal
    readonly property double progressBarSunday: (DbModel.weekMeters[6] / DbModel.dailyGoal > 1) ? 1 : DbModel.weekMeters[6] / DbModel.dailyGoal

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

