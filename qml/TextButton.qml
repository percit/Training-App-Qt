import QtQuick 2.3

Rectangle {
  id: root

  property bool buttonOn: false
  property string text: ""

  width: 70 * Style.scaleX
  height: 200 * Style.scaleY
  radius: root.width / 2
  color: buttonOn ? "green" : "red"

  signal clicked  
  
  Text {
	anchors.centerIn: parent
	text: root.text
	font: Style.fontDemiBold12
  }
	MouseArea {
	  anchors.fill: root
	  onClicked:{
		root.clicked()
		buttonOn = !buttonOn 
	  }
	}
}
