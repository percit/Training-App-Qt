import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQml 2.3
import StyleSingleton 1.0
import "../utils"
import "../viewmodels"
import FirebaseAuth 1.0

MainPage {
    id: root
    placeholder: false
    signal changeBottomRowVisibility
    property bool signInOn: true
    property string password
    property string email

    Rectangle {
        width: 375 * Style.scaleX
        height: 612 * Style.scaleY
        anchors.centerIn: parent
        color: "transparent"
        Text {
            id: signInText
            anchors{
                left: parent.left; leftMargin: 50
                top: parent.top; topMargin: 100
            }
            text: "Sign In"
            font: Style.fontBold22
            color: signInOn ? "white" : Style.black75
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    root.signInOn = true
                }
            }
        }
        Text {
            id:signUpText
            anchors{
                left: signInText.right; leftMargin: 60
                top: parent.top; topMargin: 100
            }
            text: "Sign Up"
            font: Style.fontBold22
            color: signInOn ? Style.black75 : "white"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    root.signInOn = false
                }
            }
        }

        Column {
            anchors {
                left: parent.left; leftMargin: 40
                top: parent.top; topMargin: 200
            }
            spacing: 20
            Text {
                text: "Mail"
                font: Style.fontBold16
                color: Style.black75
            }
            TextField {
                anchors.horizontalCenter: parent.horizontalCenter
                width: 300 * Style.scaleX; height: 50 * Style.scaleY
                font.pointSize: 14
                placeholderText: "Input mail"
                onTextChanged: {
                    email = text
                }
            }
            Text {
                text: "Password"
                font: Style.fontBold16
                color: Style.black75
            }
            TextField {
                anchors.horizontalCenter: parent.horizontalCenter
                width: 300 * Style.scaleX; height: 50 * Style.scaleY
                font.pointSize: 14
                placeholderText: "Input password"
                onTextChanged: {
                    password = text
                }
            }
        }

		TextButton {
			anchors {
				horizontalCenter: parent.horizontalCenter
				bottom: parent.bottom; bottomMargin: 100 * Style.scaleY
			}
            fontStyle: Style.fontBold16
			width: 300 * Style.scaleX; height: 60 * Style.scaleY
			text: signInOn ? "Sign in" : "Sign up"
			onClicked: {
                if(signInOn) {
                    FbAuth.signUserIn(email, password)
                    logTimer.start()
                }
                else {
                    FbAuth.signUserUp(email, password)
                    logTimer.start()
                }
			}
		}
    }
    Timer {
        id: logTimer
        interval: 500 
        running: false
        repeat: false
        onTriggered: {
            // if (FbAuth.connectSuccesful) { //uncomment only if signUserIn/Up are uncommented (firebase_auth.cpp)
                root.changeBottomRowVisibility()
            // }
        }
    }
}

