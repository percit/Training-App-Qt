import QtQuick
import QtQuick.Controls
import QtQml
import StyleSingleton

Item {
	id: root

	property bool placeholder: false
	property string text: ""

	Rectangle {
		anchors.fill: parent
		color: Style.black50
		Text {
			anchors.centerIn: parent
			text: placeholder ? (root.text + " Placeholder"): root.text
			font: Style.fontBold16
		}
	}
}
