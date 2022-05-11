import QtQuick 2.3
import QtQuick.Controls 1.4
import QtPositioning 5.6
import QtLocation 5.11
import "Helper.js" as Helper

Item {
    visible: true
    width: 375 * Style.scaleX
    height: 418 * Style.scaleY

    property variant fromCoordinate: QtPositioning.coordinate(51.099695, 17.028648)
    property variant toCoordinate: QtPositioning.coordinate(51.054788, 16.970955)


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
                routeQuery.addWaypoint(fromCoordinate);
                //tutaj by byl for loop z wielkosca kontenera, ktory dodaje waypointy, a waypointy bierzemy z lokacji co 10s
                routeQuery.addWaypoint(toCoordinate); 
                routeQuery.travelModes = RouteQuery.PedestrianTravel
                update();
            }
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

    } //map
} //item


// liczenie dystansu:

    property variant markers //to bylo w obiekcie map
    property double fullDistance: 0.0
    for (var i = 0; i < markers.length - 1; i++) {
        var coordinate1 = markers[i].coordinate;
        var coordinate2 = markers[i+1].coordinate;
        fullDistance += Helper.formatDistance(coordinate1.distanceTo(coordinate2));
    }
                

    function addMarker()
    {
        var count = map.markers.length
        markerCounter++
        var marker = Qt.createQmlObject ('Marker {}', map)
        map.addMapItem(marker)
        marker.z = map.z+1
        marker.coordinate = mouseArea.lastCoordinate

        //update list of markers
        var myArray = new Array()
        for (var i = 0; i<count; i++){
            myArray.push(markers[i])
        }
        myArray.push(marker)
        markers = myArray
    }


//timer:
    odpalam timer1 liczacy caly bieg
    jak timer1 jest running, to timer2 jest running
    timer2 ma czas 10 sekund
    timer2 odczytuje wartosc, tworzy waypoint i pakuje do listy
    timer1 wciskamy, wylacza nam timer2, liczy nam odleglosc, odpala routeQuery.clearWaypoints();
    no i timer1 jest zbindowany z przyciskiem run


//deployment na androida:
    usun te wersje placeholderowe
    przejrzyj kod, zeby byl ladny
    dodaj viewmodele i podziel na foldery
    dodaj readme jak budowac apk i update starego readme 