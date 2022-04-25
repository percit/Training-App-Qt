import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQml 2.3

MainPage {
  id: root

  readonly property DataBaseViewModel viewModel: DataBaseViewModel {}

  placeholder:false

	Text {
	  anchors {
		left: parent.left; leftMargin: 20
		top: parent.top; topMargin: 10
	  }	
	  text: "My Progress"
	  font: Style.fontBold22 //TODO make it bigger
	}
	Column {
	  anchors {
		left: parent.left; leftMargin: 20
		top: parent.top; topMargin: 50
	  }
	  Text {
		text: root.viewModel.weeklyKmRun
		font: Style.fontBold22 //TODO make it bigger
	  }
	  Text {
		text: "Total km"
		font: Style.fontNormal8//TODO make it smaller
	  }
	}
 
  Row {
	anchors {
	  left: parent.left; leftMargin: 20
	  top: parent.top; topMargin: 120
	}
	spacing: 15
	Column {
	  Text {
		text: root.viewModel.allDuration / 60
		font: Style.fontBold16
	  }
	  Text {
		text: "Total Hours"
		font: Style.fontDemiBold12
	  }
	}
	Column {
	  Text {
		text: root.viewModel.weeklyKmRun * 62
		font: Style.fontBold16
	  }
	  Text {
		text: "Total Kcal"
		font: Style.fontDemiBold12
	  }
	}
	Column {
	  Text {
		text: root.viewModel.averageDuration
		font: Style.fontBold16
	  }
	  Text {
		text: "Avg Duration"
		font: Style.fontDemiBold12
	  }
	}
  }
	Text {
	  anchors {
		left: parent.left; leftMargin: 20
		top: parent.top; topMargin: 250
	  }	
	  text: "Weekly Chart"
	  font: Style.fontBold16 //TODO make it bigger
	}


	Row {
	  anchors {
		horizontalCenter: parent.horizontalCenter
		top: parent.top; topMargin: 300
	  }
	  spacing: 25
	  ProgresBar {
		dayName: "Pn."
		progressValue: 0.2 
	  }
	  ProgresBar {
		dayName: "Wt."
		progressValue: 0.3 
	  }
	  ProgresBar { 
		dayName: "Śr."
		progressValue: 0.4 
	  }
	  ProgresBar { 
		dayName: "Cz."
		progressValue: 0.5 
	  }
	  ProgresBar { 
		dayName: "Pt."
		progressValue: 0.6 
	  }
	  ProgresBar { 
		dayName: "Sb."
		progressValue: 0.8 
	  }
	  ProgresBar {
		dayName: "Nd."
		progressValue: 1.0 
	  }
	}
}
