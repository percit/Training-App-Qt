import QtQuick 2.3
import DataBaseModel 1.0


QtObject {
    id: root



    readonly property double weeklyKmRun: Math.round(d.dbModel.weeklyKmRun * 100) / 100 
    readonly property double longestDistance: Math.round(d.dbModel.longestDistance * 100) / 100 
    readonly property double longestDuration: Math.round(d.dbModel.longestDuration * 100) / 100 
    readonly property double bestPace: Math.round(d.dbModel.bestPace * 100) / 100 
    readonly property double averageDuration: Math.round(d.dbModel.averageDuration * 100) / 100 
    readonly property double allDuration: Math.round(d.dbModel.allDuration * 100) / 100 


    property var priv: QtObject {
        id: d

        readonly property DbModel dbModel: DbModel {}
    }


}


//total hours nie dziala
// distance undefined km