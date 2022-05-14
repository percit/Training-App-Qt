import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQml 2.3

MainPage {
	id: root

	readonly property double distance: 0.0
	readonly property string time: "0: 00"
	placeholder: false


	MapModel {
		anchors.top: parent.top
		width: 375 * Style.scaleX
		height: (parent.height - runningMenu.height - 64 * Style.scaleY) * Style.scaleY
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
				text: distance
				font: Style.fontBold16
				color: Style.black75
			}
			Text {
				text: "Distance (km)"
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
				text: time
				font: Style.fontBold16
				color: Style.black75
			}
			Text {
				text: "Time elapsed"
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
		}
	}
}
