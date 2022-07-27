import QtQuick 2.15
import QtQuick.Controls 2.3
import QtQml 2.3
import StyleSingleton 1.0
import "../utils"


MainPage {
	placeholder: false

    property string popupText: ""

    Flickable {//TODO add proper settings
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
                text: "Polityka prywatności"
                onClicked:{
                    popupText = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
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
            wrapMode: Text.WordWrap
            elide: Text.ElideRight
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
