import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQml 2.3

MainPage {
	readonly property DataBaseViewModel viewModel: DataBaseViewModel {}
	placeholder: false

	Rectangle {
		width: 230; height: 230
		color: Style.black10
		border.color: Style.white75
		border.width: 10
		radius: width * 0.5
		anchors {
			horizontalCenter: parent.horizontalCenter
			top: parent.top; topMargin: 30
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
				text: viewModel.weeklyKmRun + "km"
				font: Style.fontBold22
				color: Style.black75
			}
			Text {
				anchors.horizontalCenter: parent.horizontalCenter
				text: "Weekly Goal 20km"
				font: Style.fontNormal12
				color: Style.black75
			}
		}
	}
	Text {
		anchors {
			left: parent.left; leftMargin: 10
			top: parent.top; topMargin: 300
		}
		text: "Best Records"
		font: Style.fontBold22
		color: Style.black75
	}

	Column {
		anchors {
			left: parent.left; leftMargin: 10
			top: parent.top; topMargin: 350
		}
		spacing: 15
		Column {
			TextWithIcon {
				text: "Longest Distance"
				font: Style.fontDemiBold12
				source: "assets/route.png"
			}
			Text {
				text: viewModel.longestDistance + " km"
				font: Style.fontBold16
				color: Style.green
			}
		}
		Column {
			TextWithIcon {
				text: "Best Pace"
				font: Style.fontDemiBold12
				source: "assets/speed.png"
			}
			Text {
				text: viewModel.bestPace + " min/km"
				font: Style.fontBold16
				color: Style.green
			}
		}
		Column {
			TextWithIcon {
				text: "Longest Duration"
				font: Style.fontDemiBold12
				source: "assets/time.png"
			}
			Text {
				text: viewModel.longestDuration + " min"
				font: Style.fontBold16
				color: Style.green
			}
		}
	}
}
