import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQml 2.3

Item {
  id: root
  
  // property alias text:pageText.text 
  property string text: ""
  Text {
	id: pageText
	anchors.centerIn: parent
	text: root.text + " Placeholder"
	font {
	  bold: true
	  family: "Open Sans"
	  pointSize: 20
	}
  }
}
