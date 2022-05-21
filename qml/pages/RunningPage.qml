import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQml 2.3
import StyleSingleton 1.0
import "../Helper.js" as Helper
import "../utils"
import "../viewmodels"

MainPage {
	id: root

	placeholder: false

	MapModel {
		id: mapModel
		
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
				text: Helper.roundNumber((mapModel.fullDistance / 1000), 2)
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
				text: Helper.roundNumber((mapModel.currentlyElapsedTime / 6), 2) //shows in minutes
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
			onClicked: {
				mapModel.trainButtonClicked()
			}
		}
	}
}
