import QtQuick 2.3
import StyleSingleton 1.0

Rectangle {
	id: root

	width: 64 * Style.scaleX
	height: 64 * Style.scaleX
	signal clicked
	property bool buttonOn: false
	property alias source: mainIcon.source

	color: "transparent"
	Icon {
		id: mainIcon

		height: 40 * Style.scaleX; width: 40 * Style.scaleX
		anchors.centerIn: parent
		color: buttonOn ? Style.green: Style.red
	}
	MouseArea {
		anchors.fill: parent
		onClicked: {
			root.clicked()
		}
	}
}
