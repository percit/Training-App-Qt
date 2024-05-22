import QtQuick
import QtQuick.Controls
import QtQml
import "../utils"
import "../viewmodels"
import "../Helper.js" as Helper
import StyleSingleton
import DataBaseModel
import FirebaseDataBase

MainPage {
	id: root
    readonly property DataBaseViewModel viewModel: DataBaseViewModel {}

	placeholder: false

    CustomIcon {
        anchors.centerIn: parent
        source: "qrc:/assets/route.png"
        color: "blue"
    }

    Rectangle {
        id:logButton
        color: "white"
        width: 100; height: 100
        MouseArea {
            anchors.fill: parent
            onClicked:{
            }
        }   
    }
    Rectangle {
        id:reloadButton
        color: "black"
        width: 100; height: 100
        anchors.top: logButton.bottom
        Text {
            id: buttonText
            color: "white"
            anchors.centerIn: parent
            text: viewModel.weeklyGoalInKm
        }
        MouseArea {
            anchors.fill: parent
            onClicked:{
                console.log(viewModel.weeklyGoalInKm)
                console.log(DbModel.weeklyGoal)
            }
        }   
    }
}