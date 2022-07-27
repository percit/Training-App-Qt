import QtQuick 2.3
import StyleSingleton 1.0
import QtQuick.Controls 2.3

Rectangle {
	id: root

    property alias text: settingsName.text

	width: 375 * Style.scaleX
	height: 64 * Style.scaleY
    color: "white"
	signal clicked

    border.color: Style.black75
    border.width: 1

    Text {
        id: settingsName
        anchors.centerIn: parent
        font: Style.fontBold16
    }

	MouseArea {
		anchors.fill: parent
		onClicked: {
			root.clicked()
		}
	}
}

