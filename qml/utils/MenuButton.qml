import QtQuick
import StyleSingleton

Rectangle {
	id: root

	width: 64 * Style.scaleX
	height: 64 * Style.scaleX
	signal clicked
	property bool buttonOn: false
	property alias source: mainIcon.source

	color: "transparent"
	CustomIcon {
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
