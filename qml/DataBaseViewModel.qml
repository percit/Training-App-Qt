import QtQuick 2.3
import com.blikoon.batteryvalue 1.0//nasz url


QtObject {
    id: root



    readonly property double weeklyKmRun: 0//DbModel.getWeeklyKmRun()
    readonly property double longestDistance: 0//DbModel.getLongestDistance()
    readonly property double longestDuration: 0//DbModel.getLongestDuration()
    readonly property double bestPace: 0//DbModel.getBestPace()
    readonly property double averageDuration: 0//DbModel.getAverageDuration()
    readonly property double allDuration: 0//DbModel.getAllDuration()
    // property var priv: QtObject {
    //     id: d 


    //     readonly property double getWeeklyKmRun: DbModel.getWeeklyKmRun()
    // }

    readonly property Battery mBattery: Battery {}

    //tu by byl timer, albo serio dac q_property do tych wartosci 
}