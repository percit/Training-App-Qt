import QtQuick 2.3

Row {
  id: root

  property alias text: m_text.text
  property alias source: m_icon.source
  property color mainColor: Style.black75
  property alias font: m_text.font

  spacing: 5
  Icon {
	id: m_icon

	anchors.verticalCenter: root.verticalCenter
	width: m_text.height; height: m_text.height
	color: mainColor
  }  
  Text {
	id: m_text

	anchors.verticalCenter: root.verticalCenter
	color: mainColor
  }
}
