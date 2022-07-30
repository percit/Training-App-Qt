import QtQuick 2.15
import QtQuick.Controls 2.3
import QtQml 2.3
import StyleSingleton 1.0
import DataBaseModel 1.0
import "../utils"


MainPage {
	placeholder: false

    Flickable {
        id:settingsPage
        width: parent.width
        height: parent.height - 64 * Style.scaleY
        contentHeight: parent.height
        flickableDirection: Flickable.VerticalFlick
        boundsMovement: Flickable.StopAtBounds
        clip: true 
        ScrollBar.vertical: ScrollBar {}

        Column {
            SettingsItem {
                text: "Change reminder time"
                onClicked:{
                    dayKm.visible = true
                    popup.open()
                }
            }
            SettingsItem {
                text: "Daily minimum km"
                onClicked:{
                    weekKm.visible = true
                    popup.open()
                }
            }
            SettingsItem {
                text: "Weekly minimum km"
                onClicked:{
                    reminderTime.visible = true
                    popup.open()
                }
            }
            SettingsItem {
                text: "RuleBook"
                onClicked:{
                    popupText.text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
                    popupText.visible = true
                    popup.open()
                }
            }
            SettingsItem {
                text: "Privacy Notice"
                onClicked:{
                    popupText.text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
                    popupText.visible = true
                    popup.open()
                }
            }
        }
    }


    Popup {
        id: popup

        width: settingsPage.width
        height: settingsPage.height

        contentItem: Rectangle {
            anchors.fill: parent

            MenuButton {
                id: exitButton
                width: parent.width
                color: Style.black50
                onClicked: {
                    popup.close()
                    dayKm.visible = false
                    weekKm.visible = false
                    reminderTime.visible = false
                }
                source: "qrc:/assets/close.png"
            }
            Rectangle {
                anchors {
                    top: exitButton.bottom
                    horizontalCenter: parent.horizontalCenter
                }
                width: settingsPage.width - 2
                height: settingsPage.height - 64 * Style.scaleY
                color: Style.black10

                StyledComboBox {
                    id: dayKm
                    visible: false
                    anchors {
                        top: parent.top; topMargin: 40 * Style.scaleY
                        horizontalCenter: parent.horizontalCenter
                    }
                    model: ListModel {
                        ListElement { text: "1" }
                        ListElement { text: "2" }
                        ListElement { text: "3" }
                        ListElement { text: "4" }
                        ListElement { text: "5" }
                        ListElement { text: "6" }
                        ListElement { text: "7" }
                        ListElement { text: "8" }
                        ListElement { text: "9" }
                        ListElement { text: "10" }
                    }
                    onActivated: {
                        DbModel.setDaylyGoal(currentText)
                    }
                }
                StyledComboBox {
                    id: weekKm
                    visible: false
                    anchors {
                        top: parent.top; topMargin: 40 * Style.scaleY
                        horizontalCenter: parent.horizontalCenter
                    }
                    model: ListModel {
                        ListElement { text: "5" }
                        ListElement { text: "10" }
                        ListElement { text: "15" }
                        ListElement { text: "20" }
                        ListElement { text: "25" }
                        ListElement { text: "30" }
                        ListElement { text: "35" }
                        ListElement { text: "40" }
                        ListElement { text: "45" }
                        ListElement { text: "50" }
                    }
                    onActivated: {
                        DbModel.setWeeklyGoal(currentText)
                    }
                }
                StyledComboBox {
                    id: reminderTime
                    anchors {
                        top: parent.top; topMargin: 40 * Style.scaleY
                        horizontalCenter: parent.horizontalCenter
                    }
                    visible: false
                    model: ListModel {
                        ListElement { text: "6:00" }
                        ListElement { text: "7:00" }
                        ListElement { text: "8:00" }
                        ListElement { text: "9:00" }
                        ListElement { text: "10:00" }
                        ListElement { text: "11:00" }
                        ListElement { text: "12:00" }
                        ListElement { text: "13:00" }
                        ListElement { text: "14:00" }
                        ListElement { text: "15:00" }
                        ListElement { text: "16:00" }
                        ListElement { text: "17:00" }
                        ListElement { text: "18:00" }
                        ListElement { text: "19:00" }
                        ListElement { text: "20:00" }
                        ListElement { text: "21:00" }
                        ListElement { text: "22:00" }
                        ListElement { text: "23:00" }
                    }
                    onActivated: {
                        console.log(currentText)
                    }
                }

                Text { //only for roolbook and privacy notice
                    id: popupText
                    anchors.fill: parent
                    visible: false
                    font: Style.fontBold12
                    wrapMode: Text.WordWrap
                    elide: Text.ElideRight
                    padding: 5
                }
            }
        }
    }
}
