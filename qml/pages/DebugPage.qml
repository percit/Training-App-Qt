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
                DbModel.setMonday(1234, 1234)
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
            text: DbModel.monday_km
        }
        MouseArea {
            anchors.fill: parent
            onClicked:{
                buttonText.text = DbModel.monday_km
                // console.log(DbModel.monday_time)
            }
        }   
    }
}