import QtQuick 2.3
import DataBaseModel 1.0
import "../Helper.js" as Helper


QtObject {
    readonly property string weeklyKmRun: Helper.formatDistance(DbModel.weeklyKmRun) // Math.round(DbModel.weeklyKmRun * 100) / 100
    readonly property string longestDistance: Helper.formatDistance(DbModel.longestDistance) //Math.round(DbModel.longestDistance * 100) / 100
    readonly property string longestDuration: Helper.formatDistance(DbModel.longestDuration) //Math.round(DbModel.longestDuration * 100) / 100
    readonly property string averageDuration: Helper.formatDistance(DbModel.averageDuration) //Math.round(DbModel.averageDuration * 100) / 100
    readonly property string allDuration: Helper.formatDistance(DbModel.allDuration) //Math.round(DbModel.allDuration * 100) / 100
	readonly property string bestPace: Math.round(DbModel.bestPace * 3.6 * 100) / 100//tu nie trzeba helpera, tu mozna poprostu tu tak dac
	readonly property int weeklyGoalInMeters: 20000 //20k meters is day's standard, this should be set in settings of app

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
