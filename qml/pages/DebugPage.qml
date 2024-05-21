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