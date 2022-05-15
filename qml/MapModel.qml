import QtQuick 2.3
import QtQuick.Controls 1.4
import QtPositioning 5.6
import QtLocation 5.11
import "Helper.js" as Helper

Item {
    property variant fromCoordinate: QtPositioning.coordinate(51.099695, 17.028648)
    property variant toCoordinate: QtPositioning.coordinate(51.054788, 16.970955)
    property double fullDistance: 0.0
    property variant markers //konetner z Qt.position

    //showing time
    property double time_elapsed: 0.0
    property double startTime: 0.0
    property double currentlyElapsedTime: 0

    signal trainButtonClicked

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
                // for (var i = 0; i<markers.length; i++){
                //     routeQuery.addWaypoint(markers[i]) //markers musi zwracac te QtPositioning.coordinate
                // }
                routeQuery.addWaypoint(QtPositioning.coordinate(51.087586, 17.013730));
                routeQuery.addWaypoint(QtPositioning.coordinate(51.060790, 16.994307));
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

    Timer { 
        interval: 10 * 1000 //10 sec
        running: startTime > 0
        repeat: true
        onTriggered: {
            //markers.addMarker() // co 10 sekund dodaje jakis marker

            //counting distance
            // var temporaryDistance = 0.0
            // for (var i = 0; i < markers.length - 1; i++) {
            //     var coordinate1 = markers[i];
            //     var coordinate2 = markers[i+1];
            //     temporaryDistance += Helper.formatDistance(coordinate1.distanceTo(coordinate2));
            // }
            // fullDistance = temporaryDistance
            // temporaryDistance = 0.0

            //showing time
            currentlyElapsedTime++
        }
    }

    onTrainButtonClicked: { 
        if(startTime === 0.0) { //timer wylaczony, nie zaczelismy biegac
            time_elapsed = 0.0
            currentlyElapsedTime = 0
            startTime = new Date().getTime()
        }
        else {
            time_elapsed = (new Date().getTime() - startTime) / 1000//(60 * 1000) //change to min from ms
            startTime = 0.0
            routeQuery.clearWaypoints() //czyscimy waypointy jak przestajemy biegac
        }
    }
    function addMarker()
    {
        console.log("addMarker fun")
    }
} //item


// liczenie dystansu:
     


//     function addMarker()
//     {
//         var count = map.markers.length
//         markerCounter++
//         var marker = Qt.createQmlObject ('Marker {}', map)
//         map.addMapItem(marker)
//         marker.z = map.z+1
//         marker.coordinate = mouseArea.lastCoordinate

//         //update list of markers
//         var myArray = new Array()
//         for (var i = 0; i<count; i++){
//             myArray.push(markers[i])
//         }
//         myArray.push(marker)
//         markers = myArray
//     }



// //deployment na androida:
//     usun te wersje placeholderowe
//     przejrzyj kod, zeby byl ladny
//     dodaj viewmodele i podziel na foldery
//     dodaj readme jak budowac apk i update starego readme 



//OGARNIJ TO DODAWANIE WAYPOINTOW DO ARRAYA CZYLI ADDMARKER