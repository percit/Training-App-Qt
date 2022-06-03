import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQml.Models 2.15
import "utils"
import "pages"
//temporary
import "viewmodels" 


Item {
	id: root

	anchors.fill: parent

	property DataBaseViewModel viewModel: DataBaseViewModel {}

	SwipeView {
		id: pagesRow

		anchors.fill: parent
		currentIndex: 0
		interactive: false
		ObjectModel {
			id: modelObject
			RunningPage {
				text: "Google Maps \n"
			}
			AchievementsPage {
			}
			WeeklyStatsPage {
			}
			MainPage {//settings
				text: "Page 4"
			}
			MainPage {
				id: debugPage
				text: "DEBUG"
				// ProgresBar {
				// 	progressValue: (viewModel.dbModel.wednesday_km / 20 > 1) ? 1 : viewModel.dbModel.wednesday_km / 20

				// }

				Text {
					anchors.horizontalCenter: parent.horizontalCenter
					text: root.viewModel.dbModel.friday_km
				}

			}
		}
		Repeater {
			model: modelObject
			delegate: Page {
			width: root.width
			height: root.height
			Loader {
				sourceComponent: modelData
			}
		}
	}
}

BottomRow {
	anchors.bottom: parent.bottom
	onPage1: {
		pagesRow.setCurrentIndex(0)
	}
	onPage2: {
		pagesRow.setCurrentIndex(1)
	}
	onPage3: {
		pagesRow.setCurrentIndex(2)
	}
	onPage4: {
		pagesRow.setCurrentIndex(3)
	}
	onPage5: {
		pagesRow.setCurrentIndex(4)
	}
}

}
