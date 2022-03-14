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
	  MainPage {
		id: dummyPage1
		text: "Page1"
	  }
	  MainPage {
		id: dummyPage2
		text: "Page2"
	  }
	  MainPage {
		id: dummyPage3
		text: "Page 3"
	  }
	  MainPage {
		id: dummyPage4
		text: "Page 4"
	  }
	  MainPage {
		id: dummyPage5
		text: "Page 5"
	  }
	  MainPage {
		id: dummyPage_DEBUG
		text: "DEBUG"
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
