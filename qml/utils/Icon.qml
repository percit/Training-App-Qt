import QtQuick 2.3
import Qt5Compat.GraphicalEffects

Image {
    id: root
    property color color: "transparent"
    ColorOverlay {
        anchors.fill: root
        source: root
        color: "#ff0000"
    }
}

