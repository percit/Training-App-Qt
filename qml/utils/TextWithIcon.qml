import QtQuick 2.3
import StyleSingleton 1.0

Row {
	id: root

	property alias text: m_text.text
	property alias source: m_icon.source
	property color mainColor: Style.black75
	property alias font: m_text.font
	property int space: 5

	spacing: space
	Icon {
		id: m_icon

		width: m_text.height; height: m_text.height
		color: mainColor
	}
	Text {
		id: m_text

		color: mainColor
	}
}
