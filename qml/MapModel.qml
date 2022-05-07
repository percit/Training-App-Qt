import QtQuick 2.3
import QtQuick.Controls 1.4
import QtPositioning 5.6
import QtLocation 5.11

Item {
    id: win
    visible: true
    width: 375 * Style.scaleX
    height: 438 * Style.scaleY

    Plugin {
        id: plugin
        name: "osm" //mapboxgl not working for routing right now, when working, use map.supportedMapTypes[3]
    }

    Map {
        id: map
        gesture.enabled: true
        anchors.fill: parent
        plugin: plugin
        zoomLevel: 15
        center { // Arcady Capitol
            latitude: 51.099695
            longitude: 17.028648
        }
        activeMapType: map.supportedMapTypes[0]
        copyrightsVisible: false
        RouteModel {
            id: rm
            plugin: plugin
            query: RouteQuery {id: routeQuery }
            Component.onCompleted: {
                routeQuery.addWaypoint(QtPositioning.coordinate(51.099695, 17.028648));
                routeQuery.addWaypoint(QtPositioning.coordinate(51.054788, 16.970955)); 
                update();
            } //TUTAJ POWINIENEM DODAWAC DUZO WAYPOINTOW, JAKAS FUNKCJA LADUJACA JE DO LISTVIEW CZY COS

        }

        MapItemView {
            model: rm
            delegate: Component{
                MapRoute {
                    route: routeData
                    line.color: "green"
                    line.width: 4
                    smooth: true
                }
            }
        }
        //zeby uzyskac czas i wsrzucic to do listy to jest plik RouteList

    } //map
} //item
