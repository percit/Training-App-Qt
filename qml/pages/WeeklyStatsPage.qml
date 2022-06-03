import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQml 2.3
import StyleSingleton 1.0
import "../utils"
import "../viewmodels"

MainPage {
	readonly property DataBaseViewModel viewModel: DataBaseViewModel {}

	placeholder: false

	Text {
		anchors {
			left: parent.left; leftMargin: 20 * Style.scaleX
			top: parent.top; topMargin: 10 * Style.scaleY
		}
		text: "My Progress"
		font: Style.fontBold22 //TODO make it bigger
	}
	Column {
		anchors {
			left: parent.left; leftMargin: 20 * Style.scaleX
			top: parent.top; topMargin: 50 * Style.scaleY
		}
		Text {
			text: viewModel.weeklyKmRun
			font: Style.fontBold22 //TODO make it bigger
		}
		Text {
			text: "Total km"
			font: Style.fontNormal8//TODO make it smaller
		}
	}

	Row {
		anchors {
			left: parent.left; leftMargin: 20 * Style.scaleX
			top: parent.top; topMargin: 120 * Style.scaleY
		}
		spacing: 15
		Column {
			Text {
				text: Math.round((viewModel.allDuration / 60) * 100) / 100
				font: Style.fontBold16
			}
			Text {
				text: "Total Hours"
				font: Style.fontDemiBold10
			}
		}
		Column {
			Text {
				text: viewModel.weeklyKmRun * 62
				font: Style.fontBold16
			}
			Text {
				text: "Total Kcal"
				font: Style.fontDemiBold10
			}
		}
		Column {
			Text {
				text: viewModel.averageDuration + " min"
				font: Style.fontBold16
			}
			Text {
				text: "Avg Duration"
				font: Style.fontDemiBold10
			}
		}
	}
	Text {
		anchors {
			left: parent.left; leftMargin: 20 * Style.scaleX
			top: parent.top; topMargin: 250 * Style.scaleY
		}
		text: "Weekly Chart"
		font: Style.fontBold16 //TODO make it bigger
	}


	Row {
		anchors {
			horizontalCenter: parent.horizontalCenter
			top: parent.top; topMargin: 300 * Style.scaleY
		}
		spacing: 25
		ProgresBar {
			dayName: "Pn."
			progressValue: viewModel.progressBarMonday
		}
		ProgresBar {
			dayName: "Wt."
			progressValue: viewModel.progressBarTuesday
		}
		ProgresBar {
			dayName: "Śr."
			progressValue: viewModel.progressBarWednesday
		}
		ProgresBar {
			dayName: "Cz."
			progressValue: viewModel.progressBarThursday
		}
		ProgresBar {
			dayName: "Pt."
			progressValue: viewModel.progressBarFriday
		}
		ProgresBar {
			dayName: "Sb."
			progressValue: viewModel.progressBarSaturday
		}
		ProgresBar {
			dayName: "Nd."
			progressValue: viewModel.progressBarSunday
		}
	}
}
