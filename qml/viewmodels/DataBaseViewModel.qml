import QtQuick 2.3
import DataBaseModel 1.0
import "../Helper.js" as Helper


QtObject {
    readonly property string weeklyKmRun: Helper.formatDistance(DbModel.weeklyKmRun)
    readonly property string longestDistance: Helper.formatDistance(DbModel.longestDistance)
    readonly property string longestDuration: Helper.formatDistance(DbModel.longestDuration)
    readonly property string averageDuration: Helper.formatDistance(DbModel.averageDuration)
    readonly property string allDuration: Helper.formatDistance(DbModel.allDuration)
	readonly property string bestPace: Math.round(DbModel.bestPace * 3.6 * 100) / 100
	readonly property int weeklyGoalInMeters: 20000 //20k meters is day's standard, this should be set in settings of app
    readonly property int totalKcalRun: Math.round(DbModel.weeklyKmRun * 100) / 100 * 62

//to sa wartosci z wektora, a nie bazy danych
    readonly property double progressBarMonday: (DbModel.monday_km / weeklyGoalInMeters > 1) ? 1 : DbModel.monday_km / weeklyGoalInMeters
    readonly property double progressBarTuesday: (DbModel.tuesday_km / weeklyGoalInMeters > 1) ? 1 : DbModel.tuesday_km / weeklyGoalInMeters
    readonly property double progressBarWednesday: (DbModel.wednesday_km / weeklyGoalInMeters > 1) ? 1 : DbModel.wednesday_km / weeklyGoalInMeters
    readonly property double progressBarThursday: (DbModel.thursday_km / weeklyGoalInMeters > 1) ? 1 : DbModel.thursday_km / weeklyGoalInMeters
    readonly property double progressBarFriday: (DbModel.friday_km / weeklyGoalInMeters > 1) ? 1 : DbModel.friday_km / weeklyGoalInMeters
    readonly property double progressBarSaturday: (DbModel.saturday_km / weeklyGoalInMeters > 1) ? 1 : DbModel.saturday_km / weeklyGoalInMeters
    readonly property double progressBarSunday: (DbModel.sunday_km / weeklyGoalInMeters > 1) ? 1 : DbModel.sunday_km / weeklyGoalInMeters

    // // property var monday: d.dbModel.monday[fullDistance, fullRunTime]
    // // property var day: [fullDistance, fullRunTime]
    // // property var week: //to jest array dni, week.push(day)

}