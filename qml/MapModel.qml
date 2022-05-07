import QtQuick 2.3
import QtQuick.Controls 1.4
import QtPositioning 5.6
import QtLocation 5.11
import "Helper.js" as Helper

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
                //tutaj by byl for loop z wielkosca kontenera, ktory dodaje waypointy, a waypointy bierzemy z lokacji co 10s
                routeQuery.addWaypoint(QtPositioning.coordinate(51.054788, 16.970955)); 
                routeQuery.travelModes = RouteQuery.PedestrianTravel
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

        GeocodeModel { //chyba z tego moge wyciagnac dana pozycje
            id: geocodeModel
            plugin: map.plugin
            onStatusChanged: {
                if ((status == GeocodeModel.Ready) || (status == GeocodeModel.Error))
                    map.geocodeFinished()
            }
            onLocationsChanged:
            {
                if (count == 1) {
                    map.center.latitude = get(0).coordinate.latitude
                    map.center.longitude = get(0).coordinate.longitude
                }
            }
        }
        function calculateCoordinateRoute(startCoordinate, endCoordinate)
        {
            routeQuery.clearWaypoints();
            routeQuery.addWaypoint(startCoordinate)
            routeQuery.addWaypoint(endCoordinate)
            routeQuery.travelModes = RouteQuery.CarTravel
            routeQuery.routeOptimizations = RouteQuery.FastestRoute
            //! [routerequest0 feature weight]
            for (var i=0; i<9; i++) {
                routeQuery.setFeatureWeight(i, 0)
            }
            //for (var i=0; i<routeDialog.features.length; i++) {
            //    map.routeQuery.setFeatureWeight(routeDialog.features[i], RouteQuery.AvoidFeatureWeight)
            //}
            routeModel.update();
            map.center = startCoordinate;
        }
    } //map
} //item
// property variant toCoordinate: QtPositioning.coordinate(59.9645, 10.671)
//routeQuery.clearWaypoints();