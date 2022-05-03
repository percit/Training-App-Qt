import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQml 2.3

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
