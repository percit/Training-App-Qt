import QtQuick 2.15
import QtQuick.Controls 2.3
import StyleSingleton 1.0

ComboBox {
    id: root
    width: 250 * Style.scaleX; height: 80 * Style.scaleY
    background: Rectangle {
        color: Style.black50
        radius: height/2
    }
    delegate: ItemDelegate {
        width: parent.width
        height:60 * Style.scaleY

        contentItem: Rectangle {
            width:parent.width
            height:parent.height
            color: Style.black10

            Text {
                text: modelData
                font: Style.fontBold16
                color: "white"
                elide: Text.ElideRight
                anchors.centerIn: parent
            }
        }
    }
    contentItem: Text {
            leftPadding: 20
            text: root.displayText
            font: Style.fontBold22
            color: "white"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            elide: Text.ElideRight
    }
    popup: Popup {
        width: root.width
        height:contentItem.implicitHeigh
        padding: 1

        contentItem: ListView {
            id:listView
            implicitHeight: contentHeight
            model: root.popup.visible ? root.delegateModel : null

            ScrollIndicator.vertical: ScrollIndicator { }
        }

        background: Rectangle {
            radius: 20
            color: Style.black50
            border.width: 1
            border.color: "white"
        }
    }
}