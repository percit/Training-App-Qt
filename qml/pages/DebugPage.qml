import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQml 2.3
import StyleSingleton 1.0
import "../utils"
import "../viewmodels"
import "../Helper.js" as Helper
import DataBaseModel 1.0
import FirebaseDataBase 1.0

MainPage {
	id: root

	placeholder: false

    Rectangle {
        id:logButton
        color: "white"
        width: 100; height: 100
        MouseArea {
            anchors.fill: parent
            onClicked:{
                console.log("log Button")
                //funkcja q_invokable, ktora wszystko zeruje
                DbModel.clearAllData();

                //updating database TODO recheck if this updates nicely
                DbModel.setLongestDuration(FbDatabase.longestDuration);
                DbModel.setLongestDistance(FbDatabase.longestDistance);
                DbModel.setBestPace(FbDatabase.bestPace);
                DbModel.setDailyGoal(FbDatabase.dailyGoal);
                DbModel.setWeeklyGoal(FbDatabase.weeklyGoal);

                //to jest test z nowym mailem
                // FbDatabase.postValues("test2")
            }
        }   
    }
    Rectangle {
        id:reloadButton
        color: "black"
        width: 100; height: 100
        anchors.top: logButton.bottom
        MouseArea {
            anchors.fill: parent
            onClicked:{
                console.log("reload Button")
                FbDatabase.setLongestDistance(DbModel.longestDistance);
                FbDatabase.setLongestDuration(DbModel.longestDuration);
                FbDatabase.setLongestDistance(DbModel.longestDistance);
                FbDatabase.setBestPace(DbModel.bestPace);
                FbDatabase.setDailyGoal(DbModel.dailyGoal);
                FbDatabase.setWeeklyGoal(DbModel.weeklyGoal);

                // FbDatabase.postValues("test1");//TODO I suppose it should work, I have no internet, so no way to test it
                // FbDatabase.putValues("test2");
                // FbDatabase.readFirebaseData("test1")

                //jakas funkcja na post tutaj
            }
        }   
    }
}




//on update every 24h
// FbDatabase.setLongestDistance(DbModel.longestDistance);
// FbDatabase.setLongestDuration(DbModel.longestDuration);
// FbDatabase.setLongestDistance(DbModel.longestDistance);
// FbDatabase.setBestPace(DbModel.bestPace);
// FbDatabase.setDailyGoal(DbModel.dailyGoal);
// FbDatabase.setWeeklyGoal(DbModel.weeklyGoal);
// FbDatabase.putValues("test2")
