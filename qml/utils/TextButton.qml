import QtQuick 2.3
import StyleSingleton 1.0

Rectangle {
  id: root

  property bool buttonOn: false
  property string text: ""
  property var fontStyle: Style.fontDemiBold12

  width: 70 * Style.scaleX
  height: 200 * Style.scaleY
  radius: root.width / 2
  color: buttonOn ? Style.green: Style.red

  signal clicked

  Text {
    anchors.centerIn: parent
    text: root.text
    font: fontStyle
  }
  MouseArea {
    anchors.fill: root
    onClicked: {
      root.clicked()
      buttonOn = !buttonOn
    }
  }
}
