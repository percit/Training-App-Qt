import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQml 2.3

Item {
  id: root
  
  property bool placeholder:false 
  property string text: ""
  Text {
	id: pageText
	anchors.centerIn: parent
	text: placeholder ? (root.text + " Placeholder") : root.text 
	font {
	  bold: true
	  family: "Open Sans"
	  pointSize: 20
	}
  }
}
