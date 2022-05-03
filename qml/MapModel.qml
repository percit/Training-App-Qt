import QtQuick 2.3
import QtQuick.Controls 1.4
import QtPositioning 5.6
import QtLocation 5.9

Item {
    id: win
    visible: true
    width: 375 * Style.scaleX
    height: 442 * Style.scaleY

    Plugin {
        id: plugin
        name: "mapboxgl"
    }

    Map {
        id: map
        gesture.enabled: true
        anchors.fill: parent
        plugin: plugin
        center: QtPositioning.coordinate(0, 180)
        activeMapType: map.supportedMapTypes[0]
        zoomLevel: 8
        copyrightsVisible: true

        RouteModel {
            id: routeModel
        }

        MapItemView {
            model: routeModel
            delegate: routeDelegate
        }

        Component {
            id: routeDelegate

            MapRoute {
                route: routeData
                line.color: "blue"
                line.width: 5
                smooth: true
                opacity: 0.8
            }
        }

        // MapPolyline {
        //     line.color: 'red'
        //     line.width: 10
        //     path: [
        //     { latitude: 1, longitude: 179 },
        //     { latitude: 1, longitude: -179 }
        //     ]
        // }

        // MapPolyline {
        //     line.color: 'blue'
        //     line.width: 10
        //     path: [
        //     { latitude: -1, longitude: -179 },
        //     { latitude: -1, longitude: 179 }
        //     ]
        // }
    }
}
