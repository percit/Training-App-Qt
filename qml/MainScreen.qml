import QtQuick 2.3
import QtQuick.Controls 2.3 
import QtQml.Models 2.15
Item {
  id: root

  anchors.fill: parent

  SwipeView {
	id: pagesRow
	
	anchors.fill: parent
	currentIndex: 2
	interactive: false
	ObjectModel {
	  id: modelObject
	  RunningPage {
		id: dummyPage1
		text: "Google Maps \n"
	  }
	  AchievementsPage {
		id: dummyPage2
	  }
	  WeeklyStatsPage {
		id: dummyPage3
	  }
	  MainPage {//settings
		id: dummyPage4
		text: "Page 4"
	  }
	  MainPage {
		id: dummyPage_DEBUG
		text: "DEBUG"
		placeholder: true
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
