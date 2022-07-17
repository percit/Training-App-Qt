import QtQuick 2.15
import QtQuick.Controls 2.3
import QtQml 2.3
import StyleSingleton 1.0
import "../utils"


MainPage {
	placeholder: false

    property string popupText: ""

    Flickable {//TODO fix swipeview
        width: parent.width
        height: parent.height - 64 * Style.scaleY
        contentHeight: parent.height
        flickableDirection: Flickable.VerticalFlick
        boundsMovement: Flickable.StopAtBounds
        clip: true 
        ScrollBar.vertical: ScrollBar {}

        Column {
            SettingsItem {
                text: "1 setting"
                onClicked:{
                    popupText = "text1"
                    popup.open()
                }
            }
            SettingsItem {
                text: "2 setting"
                onClicked:{
                    popupText = "text2"
                    popup.open()
                }
            }
            SettingsItem {
                text: "3 setting"
                onClicked:{
                    popupText = "text3"
                    popup.open()
                }
            }
            SettingsItem {
                text: "4 setting"
                onClicked:{
                    popupText = "text4"
                    popup.open()
                }
            }
            SettingsItem {
                text: "5 setting"
                onClicked:{
                    popupText = "text5"
                    popup.open()
                }
            }
            SettingsItem {
                text: "6 setting"
                onClicked:{
                    popupText = "text6"
                    popup.open()
                }
            }
            SettingsItem {
                text: "7 setting"
                onClicked:{
                    popupText = "text7"
                    popup.open()
                }
            }
            SettingsItem {
                text: "8 setting"
                onClicked:{
                    popupText = "text8"
                    popup.open()
                }
            }
            SettingsItem {
                text: "9 setting"
                onClicked:{
                    popupText = "text9"
                    popup.open()
                }
            }
        }
    }


    Popup {
        id: popup

        anchors.centerIn: parent
        width: 300 * Style.scaleX
        height: 300 * Style.scaleX

        contentItem: Text {
            text: popupText
            anchors.centerIn: parent
            font: Style.fontBold16
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                popup.close()
            }
        }
    }
}



//TODO pomysl nad ladnym UI pod settingsy i jak otworzyc cos na cala strone
