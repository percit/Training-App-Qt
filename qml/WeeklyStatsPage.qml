import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQml 2.3

MainPage {
  id: root

  readonly property double totalKm: 0.0
  readonly property double totalHours: 0.0
  readonly property double totalKcal: 0.0
  readonly property double avarageDuration: 0.0 //value in minutes
  placeholder:false

	Text {
	  anchors {
		left: parent.left; leftMargin: 20
		top: parent.top; topMargin: 10
	  }	
	  text: "My Progress"
	  font: Style.fontBold16 //TODO make it bigger
	}
	Column {
	  anchors {
		left: parent.left; leftMargin: 20
		top: parent.top; topMargin: 50
	  }
	  Text {
		text: totalKm
		font: Style.fontBold16 //TODO make it bigger
	  }
	  Text {
		text: "Total km"
		font: Style.fontNormal11//TODO make it smaller
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
		text: totalHours
		font: Style.fontBold16
	  }
	  Text {
		text: "Total Hours"
		font: Style.fontDemiBold12
	  }
	}
	Column {
	  Text {
		text: totalKcal
		font: Style.fontBold16
	  }
	  Text {
		text: "Total Kcal"
		font: Style.fontDemiBold12
	  }
	}
	Column {
	  Text {
		text: avarageDuration
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
	  // ProgressBar { 	//TODO FIX 
		 // // text: "Pn."
	  // }
	  Column {
		spacing: 2
		Rectangle {
		  anchors.horizontalCenter: parent.horizontalCenter
		  width: 25; height: 200
		  color: "black"
		}
		Text {
		  anchors.horizontalCenter: parent.horizontalCenter
		  text: "Pn."
		  font: Style.fontNormal11
		  color: "green"
		}
	  }
	  Column {
		spacing: 2
		Rectangle {
		  anchors.horizontalCenter: parent.horizontalCenter
		  width: 25; height: 200
		  color: "black"
		}
		Text {
		  anchors.horizontalCenter: parent.horizontalCenter
		  text: "Wt."
		  font: Style.fontNormal11
		  color: "green"
		}
	  }
	  Column {
		spacing: 2
		Rectangle {
		  anchors.horizontalCenter: parent.horizontalCenter
		  width: 25; height: 200
		  color: "black"
		}
		Text {
		  anchors.horizontalCenter: parent.horizontalCenter
		  text: "Sr."
		  font: Style.fontNormal11
		  color: "green"
		}
	  }
	  Column {
		spacing: 2
		Rectangle {
		  anchors.horizontalCenter: parent.horizontalCenter
		  width: 25; height: 200
		  color: "black"
		}
		Text {
		  anchors.horizontalCenter: parent.horizontalCenter
		  text: "Cw."
		  font: Style.fontNormal11
		  color: "green"
		}
	  }
	  Column {
		spacing: 2
		Rectangle {
		  anchors.horizontalCenter: parent.horizontalCenter
		  width: 25; height: 200
		  color: "black"
		}
		Text {
		  anchors.horizontalCenter: parent.horizontalCenter
		  text: "Pt."
		  font: Style.fontNormal11
		  color: "green"
		}
	  }
	  Column {
		spacing: 2
		Rectangle {
		  anchors.horizontalCenter: parent.horizontalCenter
		  width: 25; height: 200
		  color: "black"
		}
		Text {
		  anchors.horizontalCenter: parent.horizontalCenter
		  text: "Sb."
		  font: Style.fontNormal11 
		  color: "green"
		}
	  }
	  Column {
		spacing: 2
		Rectangle {
		  anchors.horizontalCenter: parent.horizontalCenter
		  width: 25; height: 200
		  color: "black"
		}
		Text {
		  anchors.horizontalCenter: parent.horizontalCenter
		  text: "Nd."
		  font: Style.fontNormal11
		  color: "green"
		}
	  }
	}
}
