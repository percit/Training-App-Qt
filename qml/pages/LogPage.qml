import QtQuick
import QtQuick.Controls
import QtQml 2.3
import "../utils"
import "../viewmodels"
import StyleSingleton
import FirebaseAuth
import FirebaseDataBase
import DataBaseModel

MainPage {
    id: root
    placeholder: false
    signal changeBottomRowVisibility
    property bool signInOn: true
    property string password
    property string email
    readonly property bool testBench: true

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
            if (FbAuth.connectSuccesful || root.testBench) {
                console.log("connect succesfull")
                root.changeBottomRowVisibility()
                //TODO it gave weak password, you need to accomodate that
            }
            const mailAfterRegex = extractEmailUsername(root.email);

            //this else could be async
            if (!root.signInOn) //make a table in firebase if signing up
            {
                FbDatabase.postValues(mailAfterRegex);
                DbModel.clearAllData();
                DbModel.setMail(mailAfterRegex);
            }
            else 
            {
                if(mailAfterRegex != null) {
                    FbDatabase.readFirebaseData(mailAfterRegex); //if mail is null, app will give segment fault,this is for testing
                }
                DbModel.clearAllData();
                DbModel.setLongestDuration(FbDatabase.longestDuration);
                DbModel.setLongestDistance(FbDatabase.longestDistance);
                DbModel.setBestPace(FbDatabase.bestPace);
                DbModel.setDailyGoal(FbDatabase.dailyGoal);
                DbModel.setWeeklyGoal(FbDatabase.weeklyGoal);
                DbModel.setMail(mailAfterRegex);
            }
        }
    }
    function extractEmailUsername(mail) {
        const regex = /^([^@]+)@/;
        const matches = regex.exec(mail);
        if (matches) {
            return matches[1];
        }
        return null;
    }
}

