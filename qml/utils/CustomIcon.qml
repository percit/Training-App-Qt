import QtQuick
import Qt5Compat.GraphicalEffects

Item {
    id: root
    property color color: "transparent"
    property alias source: img.source

    Image {
        id: img
        width: parent.width
        height: parent.height
    }
    ColorOverlay {
        anchors.fill: img
        source: img
        color: root.color
    }
}