import QtQuick
import QtQuick.Controls
import QtQml
import StyleSingleton
import DataBaseModel
import "../utils"
import NotificationClient

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
            Rectangle {
                width: 375 * Style.scaleX
                height: 60 * Style.scaleY
                color: Style.black10
                Text {
                    anchors.centerIn: parent
                    text: "User Settings"
                    color: "white"
                    font: Style.fontBold22
                }
            }
            SettingsItem {
                text: "Change reminder time"
                source: "qrc:/assets/close.png"
                onClicked:{
                    reminderTime.visible = true
                    popup.open()
                }
            }
            SettingsItem {
                text: "Daily minimum km"
                source: "qrc:/assets/close.png"
                onClicked:{
                    dayKm.visible = true
                    popup.open()
                }
            }
            SettingsItem {
                text: "Weekly minimum km"
                source: "qrc:/assets/close.png"
                onClicked:{
                    weekKm.visible = true
                    popup.open()
                }
            }
            SettingsItem {
                text: "RuleBook"
                source: "qrc:/assets/close.png"
                onClicked:{
                    popupText.text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
                    popupText.visible = true
                    popup.open()
                }
            }
            SettingsItem {
                text: "Privacy Notice"
                source: "qrc:/assets/close.png"
                onClicked:{
                    popupText.text = "Our Privacy Policy was last updated on 15.10.2022.
This Privacy Policy describes Our policies and procedures on the collection, use and disclosure of Your
information when You use the Service and tells You about Your privacy rights and how the law protects You.
We use Your Personal data to provide and improve the Service. By using the Service, You agree to the
collection and use of information in accordance with this Privacy Policy."
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

            Rectangle {
                id: exitButton

                width: 375 * Style.scaleX
                height: 60 * Style.scaleY
                color: Style.black50
                TextWithIcon {
                    anchors {
                        left: parent.left;
                        leftMargin: 10
                        verticalCenter: parent.verticalCenter
                    }
                    space: 80
                    text: "Go back"
                    font: Style.fontBold22
                    mainColor: "white"
                    source: "qrc:/assets/close.png"
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        popup.close()
                        popupText.text = ""
                        dayKm.visible = false
                        weekKm.visible = false
                        reminderTime.visible = false
                    }
                }
            }
            
            Rectangle {
                anchors {
                    top: exitButton.bottom
                    horizontalCenter: parent.horizontalCenter
                }
                width: settingsPage.width
                height: settingsPage.height - 64 * Style.scaleY + 5
                color: Style.black30

                StyledComboBox {
                    id: dayKm
                    visible: false
                    anchors {
                        top: parent.top; topMargin: 100 * Style.scaleY
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
                        DbModel.setDailyGoal(currentText * 1000)
                    }
                }
                StyledComboBox {
                    id: weekKm
                    visible: false
                    anchors {
                        top: parent.top; topMargin: 100 * Style.scaleY
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
                        DbModel.setWeeklyGoal(currentText * 1000)
                    }
                }
                StyledComboBox {
                    id: reminderTime
                    visible: false
                    anchors {
                        top: parent.top; topMargin: 100 * Style.scaleY
                        horizontalCenter: parent.horizontalCenter
                    }
                    model: ListModel {
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
                    }
                    onActivated: {                      
                        NotificationClient.setNotification("GO RUN", getHour(reminderTime.text)) //todo test on android
                    }
                }

                Text { //only for rulebook and privacy notice
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
    function getHour(timeText) {
        var parts = timeText.split(":");
        return parseInt(parts[0], 10);
    }
}
