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
			LogPage {
				onChangeBottomRowVisibility: {
					pagesRow.setCurrentIndex(1)
					bottomRow.visible = true
				}
			}
			RunningPage {}
			AchievementsPage {}
			WeeklyStatsPage {}
			SettingsPage {}
			MainPage {
				id: debugPage
				text: "DEBUG"
				MouseArea {
					anchors.fill: parent
					onClicked: {
						console.log("10")
					}
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
	id:bottomRow

	visible: false
	anchors.bottom: parent.bottom
	onPage1: {
		pagesRow.setCurrentIndex(1)
	}
	onPage2: {
		pagesRow.setCurrentIndex(2)
	}
	onPage3: {
		pagesRow.setCurrentIndex(3)
	}
	onPage4: {
		pagesRow.setCurrentIndex(4)
	}
	onPage5: {
		pagesRow.setCurrentIndex(5)
	}
}

}
