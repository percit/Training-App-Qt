import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQml 2.3

MainPage {
  id: root

  readonly property double distance: 0.0
  readonly property string time: "0:00"
  placeholder:true

  Rectangle {
	width: parent.width; height: 110
	color: "blue"
	anchors {
	  bottom: parent.bottom; bottomMargin: 64 * Style.scaleY
	}
	Column {
	  anchors {
		left: parent.left; leftMargin: 10
		top: parent.top; topMargin: 5
	  }
	  Text {
		anchors.horizontalCenter: parent.horizontalCenter
	    text: distance  
		font: Style.fontBold16
	  }
	  Text {
		text: "Distance (km)"
		font: Style.fontDemiBold12
	  }
	}
	Column {
	  anchors {
		right: parent.right; rightMargin: 10 
		top: parent.top; topMargin: 5
	  }
	  Text {
		anchors.horizontalCenter: parent.horizontalCenter
		text: time 
		font: Style.fontBold16
	  }
	  Text {
		text: "Time elapsed"
		font: Style.fontDemiBold12
	  }
	}
	TextButton {
	  anchors {
		horizontalCenter: parent.horizontalCenter
		bottom: parent.bottom; bottomMargin: 10
	  }
	  width: 200; height: 30
	  text: "Train"
	}
  }
}
