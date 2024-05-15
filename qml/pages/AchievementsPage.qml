import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQml 2.3
import StyleSingleton 1.0
import "../utils"
import "../viewmodels"
import "../Helper.js" as Helper

MainPage {
	readonly property DataBaseViewModel viewModel: DataBaseViewModel {}
	placeholder: false

	RadialProgressBar {
	    lineWidth: 10 * Style.scaleY
        value: viewModel.radialProgressBarValue
        size: 230 * Style.scaleY
        secondaryColor: Style.black10
  		primaryColor: Style.green
		anchors {
			horizontalCenter: parent.horizontalCenter
			top: parent.top; topMargin: 30 * Style.scaleY
		}
		Column {
			anchors.centerIn: parent
			Text {
				anchors.horizontalCenter: parent.horizontalCenter
				text: "Distance"
				font: Style.fontNormal15
				color: Style.black75
			}
			Text {
				anchors.horizontalCenter: parent.horizontalCenter
				text: viewModel.weeklyKmRun
				font: Style.fontBold22
				color: Style.black75
			}
			Text {
				anchors.horizontalCenter: parent.horizontalCenter
				text: "Weekly Goal " + viewModel.weeklyGoalInKm
				font: Style.fontNormal12
				color: Style.black75
			}
		}
	}
	Text {
		anchors {
			left: parent.left; leftMargin: 10 * Style.scaleX
			top: parent.top; topMargin: 300 * Style.scaleY
		}
		text: "Best Records"
		font: Style.fontBold22
		color: Style.black75
	}

	Column {
		anchors {
			left: parent.left; leftMargin: 10 * Style.scaleX
			top: parent.top; topMargin: 350 * Style.scaleY
		}
		spacing: 15
		Column {
			TextWithIcon {
				text: "Longest Distance"
				font: Style.fontDemiBold12
				source: "qrc:/assets/route.png"
			}
			Text {
				text: viewModel.longestDistance
				font: Style.fontBold16
				color: Style.green
			}
		}
		Column {
			TextWithIcon {
				text: "Best Pace"
				font: Style.fontDemiBold12
				source: "qrc:/assets/speed.png"
			}
			Text {
				text: viewModel.bestPace + "km/h"
				font: Style.fontBold16
				color: Style.green
			}
		}
		Column {
			TextWithIcon {
				text: "Longest Duration"
				font: Style.fontDemiBold12
				source: "qrc:/assets/time.png"
			}
			Text {
				text: viewModel.longestDuration
				font: Style.fontBold16
				color: Style.green
			}
		}
	}
}
