import QtQuick 2.3
import StyleSingleton 1.0
import QtQuick.Controls 2.3

Rectangle {
	id: root

    property alias text: settingsName.text
	property alias source: mainIcon.source

	width: 375 * Style.scaleX
	height: 60 * Style.scaleY
    color: "transparent"
	signal clicked

	Row {
		anchors {
			left: parent.left;
			leftMargin: 5
		}
		spacing: 10
		CustomIcon {
			id: mainIcon

			height: 40 * Style.scaleX; width: 40 * Style.scaleX
			color: "white"
		}
		Text {
			id: settingsName

			anchors.verticalCenter: parent.verticalCenter
			color: "white"
			font: Style.fontBold16
		}
	}

	MouseArea {
		anchors.fill: parent
		onClicked: {
			root.clicked()
		}
	}
}

