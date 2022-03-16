import QtQuick 2.3
import QtQuick.Controls 2.3 
import QtQml.Models 2.15
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
		id: dummyPage1
		text: "Google Maps \n"
	  }
	  MainPage {
		id: dummyPage2
		text: "Page2"
		placeholder: true
	  }
	  MainPage {
		id: dummyPage3
		text: "Page 3"
		placeholder: true
	  }
	  MainPage {
		id: dummyPage4
		text: "Page 4"
		placeholder: true
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
