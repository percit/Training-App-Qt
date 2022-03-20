import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQml 2.3

MainPage {
  id: root
  readonly property double weeklyDistance: 0.0
  readonly property double longestDistance: 0.0
  readonly property double bestPace: 0.0
  readonly property string longestDuration: "0:00"
  placeholder:false

  Rectangle { 
	width: 180; height: 180
	color: "grey" //TODO get background color somehow
	border.color: "white"
	border.width: 10
	radius: width * 0.5
    anchors {
	  horizontalCenter: parent.horizontalCenter
	  top: parent.top; topMargin: 80
	}
	Column {
	  anchors.centerIn: parent
	  Text {
		anchors.horizontalCenter: parent.horizontalCenter
		text: "Distance"
		font: Style.fontNormal12
	  }
	  Text {
		anchors.horizontalCenter: parent.horizontalCenter
		text: weeklyDistance + "km"
		font: Style.fontBold16 //TODO make it bigger
	  }
	  Text {
		anchors.horizontalCenter: parent.horizontalCenter
		text: "Weekly Goal 5km"
		font: Style.fontNormal11//TODO make it smaller
	  }
	}
  }
  Text {
	anchors {
	  left: parent.left; leftMargin: 10
	  top: parent.top; topMargin: 300
	}
	text: "Best Records"
	font: Style.fontBold16
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
		source: "assets/shoe-sneaker.png"
	  }
	  Text {
		text: longestDistance + " km"
		font: Style.fontBold16
		color: "green"
	  }
	}
	Column {
	  TextWithIcon {
		text: "Best Pace"
		font: Style.fontDemiBold12
		source: "assets/shoe-sneaker.png"
	  }
	  Text {
		text: bestPace + " min/km"
		font: Style.fontBold16
		color: "green"
	  }
	}
	Column {
	  TextWithIcon {
		text: "Longest Duration"
		font: Style.fontDemiBold12
		source: "assets/shoe-sneaker.png"
	  }
	  Text {
		text: longestDuration
		font: Style.fontBold16
		color: "green"
	  }
	}
  }
}
