import QtQuick
import QtQuick.Controls
import QtQml
import StyleSingleton
import "../utils"
import "../viewmodels"
import "../Helper.js" as Helper

MainPage {
	id: root

	placeholder: false

	readonly property string runningTime: Helper.formatTime(mapModel.fullRunTime * mapModel.timerRefreshRate)
    readonly property string runningDistance: Helper.formatDistance(mapModel.fullDistance)

	MapModel {
		id: mapModel
		
		anchors.top: parent.top
		width: 375 * Style.scaleX
		height: parent.height - runningMenu.height - 64 * Style.scaleY
	}

	Rectangle {
		id: runningMenu

		width: parent.width; height: 110 * Style.scaleY
		color: Style.black30
		anchors {
			bottom: parent.bottom; bottomMargin: 64 * Style.scaleY
		}
		Column {
			anchors {
				left: parent.left; leftMargin: 10 * Style.scaleX
				top: parent.top; topMargin: 5 * Style.scaleY
			}
			Text {
				anchors.horizontalCenter: parent.horizontalCenter
				text: root.runningDistance
				font: Style.fontBold16
				color: Style.black75
			}
			Text {
				anchors.horizontalCenter: parent.horizontalCenter
				text: "Distance"
				font: Style.fontDemiBold12
				color: Style.black75
			}
		}
		Column {
			anchors {
				right: parent.right; rightMargin: 10 * Style.scaleX
				top: parent.top; topMargin: 5 * Style.scaleY
			}
			Text {
				anchors.horizontalCenter: parent.horizontalCenter
				text: root.runningTime
				font: Style.fontBold16
				color: Style.black75
			}
			Text {
				anchors.horizontalCenter: parent.horizontalCenter
				text: "Time"
				font: Style.fontDemiBold12
				color: Style.black75
			}
		}
		TextButton {
			anchors {
				horizontalCenter: parent.horizontalCenter
				bottom: parent.bottom; bottomMargin: 10 * Style.scaleY
			}
			width: 200 * Style.scaleX; height: 30 * Style.scaleY
			text: "Train"
			onClicked: {
				mapModel.trainButtonClicked()
			}
		}
	}
}
