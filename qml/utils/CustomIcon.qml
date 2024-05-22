import QtQuick
import Qt5Compat.GraphicalEffects
Item {
    property color color: "transparent"
    property alias source: root.source

    Image {
        id: root
        width: parent.width
        height: parent.height
    }
    ColorOverlay {
        anchors.fill: root
        source: root
        color: "#ff0000"
    }
}