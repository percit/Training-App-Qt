import QtQuick 2.3
import DataBaseModel 1.0
import "../Helper.js" as Helper

QtObject {
    readonly property double weeklyKmRun: Math.round(dbModel.weeklyKmRun * 100) / 100
    readonly property double longestDistance: Math.round(dbModel.longestDistance * 100) / 100
    readonly property double longestDuration: Math.round(dbModel.longestDuration * 100) / 100
    readonly property double bestPace: Math.round(dbModel.bestPace * 100) / 100
    readonly property double averageDuration: Math.round(dbModel.averageDuration * 100) / 100
    readonly property double allDuration: Math.round(dbModel.allDuration * 100) / 100
    readonly property double weeklyGoalInMeters: 20000 //20k meters is day's standard


    readonly property double progressBarMonday: (dbModel.monday_km / weeklyGoalInMeters > 1) ? 1 : dbModel.monday_km / weeklyGoalInMeters
    readonly property double progressBarTuesday: (dbModel.tuesday_km / weeklyGoalInMeters > 1) ? 1 : dbModel.tuesday_km / weeklyGoalInMeters
    readonly property double progressBarWednesday: (dbModel.wednesday_km / weeklyGoalInMeters > 1) ? 1 : dbModel.wednesday_km / weeklyGoalInMeters
    readonly property double progressBarThursday: (dbModel.thursday_km / weeklyGoalInMeters > 1) ? 1 : dbModel.thursday_km / weeklyGoalInMeters
    readonly property double progressBarFriday: (dbModel.friday_km / weeklyGoalInMeters > 1) ? 1 : dbModel.friday_km / weeklyGoalInMeters
    readonly property double progressBarSaturday: (dbModel.saturday_km / weeklyGoalInMeters > 1) ? 1 : dbModel.saturday_km / weeklyGoalInMeters
    readonly property double progressBarSunday: (dbModel.sunday_km / weeklyGoalInMeters > 1) ? 1 : dbModel.sunday_km / weeklyGoalInMeters



    property DbModel dbModel: DbModel {}

    // // property var monday: d.dbModel.monday[fullDistance, fullRunTime]
    // // property var day: [fullDistance, fullRunTime]
    // // property var week: //to jest array dni, week.push(day)

    // property var priv: QtObject {
    //     id: d

    //     property DbModel dbModel: DbModel {}
    // }
}
