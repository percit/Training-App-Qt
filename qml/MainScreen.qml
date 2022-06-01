import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQml.Models 2.15
import "utils"
import "pages"


Item {
	id: root

	anchors.fill: parent

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
				ProgresBar { }
				property var days: ['Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday']
				property var now: new Date();
				property string dateString: debugPage.days[ now.getDay() ];
				Text {
					anchors.horizontalCenter: parent.horizontalCenter
					text: debugPage.dateString
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
