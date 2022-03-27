import QtQuick 2.3

Rectangle {
  id: root

  width: 64 * Style.scaleY
  height: 64 * Style.scaleY
  signal clicked
  property bool buttonOn: false

  color: buttonOn ? "green" : "red"
  Icon {
	height: 50 * Style.scaleY; width: 50 * Style.ScaleY
	anchors.centerIn: parent
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
