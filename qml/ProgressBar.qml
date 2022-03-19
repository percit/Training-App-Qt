import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQml 2.3
Item {
  Column {
	anchors.fill: parent
  property string dayName: "Pn"
  property int progressValue: 0.5 // 50%
  spacing: 2
  Rectangle {
	id: mainBar

	anchors.horizontalCenter: parent.horizontalCenter
	width: 25; height: 200
	color: "black"
	// Rectangle {
	//   anchors {
	// 	bottom: parent.bottom
	// 	horizontalCenter: parent.horizontalCenter
	//   }
	//   width: mainBar.width; height: 100//mainBar.height * progressValue 
	//   color: "green"
	// }
  }
  Text {
	text: dayName
	anchors.horizontalCenter: parent.horizontalCenter
	font: Style.fontNormal11
	color: "green"
  }
}	
}
