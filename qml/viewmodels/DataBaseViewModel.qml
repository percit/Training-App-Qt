import QtQuick 2.3
import DataBaseModel 1.0
import "../Helper.js" as Helper


QtObject {
    readonly property double weeklyKmRun: Math.round(DbModel.weeklyKmRun * 100) / 100
    readonly property double longestDistance: Math.round(DbModel.longestDistance * 100) / 100
    readonly property double longestDuration: Math.round(DbModel.longestDuration * 100) / 100
    readonly property double bestPace: Math.round(DbModel.bestPace * 100) / 100
    readonly property double averageDuration: Math.round(DbModel.averageDuration * 100) / 100
    readonly property double allDuration: Math.round(DbModel.allDuration * 100) / 100
    readonly property double weeklyGoalInMeters: 20000 //20k meters is day's standard

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

    // property var priv: QtObject {
    //     id: d

    //     property DbModel dbModel: DbModel {}
    // }
}
