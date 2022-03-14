import QtQuick 2.3

Rectangle {
  id: root

  width: 64 * Style.scaleX
  height: 64 * Style.scaleY
  signal clicked
  property bool buttonOn: false

  color: buttonOn ? "green" : "red"
  Icon {
	height: 40; width: 40
	anchors.fill: parent
	source: "assets/shoe-sneaker.png" 
	color: buttonOn ? "white" : "black"
  }
	MouseArea {
	  anchors.fill: parent
	  onClicked:{
		root.clicked()
	  }
	}
}
