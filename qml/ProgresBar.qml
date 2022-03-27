import QtQuick 2.3
Column {
  property string dayName: "Pn"
  property double progressValue: 0.5 // 50%
  spacing: 2
  Rectangle {
	id: mainBar

	anchors.horizontalCenter: parent.horizontalCenter
	width: 25; height: 200
	color: "black"
	Rectangle {
	  anchors {
		bottom: parent.bottom
		horizontalCenter: parent.horizontalCenter
	  }
	  width: mainBar.width; height: mainBar.height * progressValue
	  color: "green"
	}
  }
  Text {
	text: dayName
	anchors.horizontalCenter: parent.horizontalCenter
	font: Style.fontNormal11
	color: "red"
  }
}	
