import QtQuick 2.3
import QtPositioning 5.6
import QtLocation 5.11
import "../Helper.js" as Helper

Item {
    property DataBaseViewModel viewmodel: DataBaseViewModel {}

    property double fullDistance: 0.0  //distance in meters
    property double fullRunTime: timerTriggered * 10 //time in seconds
    onFullRunTimeChanged: {viewmodel.dbModel.setMonday_time(fullRunTime * 10)}

    //counting distance helper properties
    property double temporaryDistance: 0.0
    property variant currentCoordinate
    // property variant markers

    property variant fromCoordinate: QtPositioning.coordinate(51.099695, 17.028648)
    property variant toCoordinate: QtPositioning.coordinate(51.054788, 16.970955)
    property variant markers: [
        fromCoordinate, QtPositioning.coordinate(51.087586, 17.013730), QtPositioning.coordinate(51.060790, 16.994307), toCoordinate
    ]

    //showing time helper properties
    property double timeElapsed: 0.0
    property double startTime: 0.0
    property int timerTriggered: 0

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
            id: routeModel
            plugin: plugin
            query: RouteQuery {id: routeQuery }
            Component.onCompleted: {
                routeQuery.addWaypoint(fromCoordinate);
                routeQuery.addWaypoint(QtPositioning.coordinate(51.087586, 17.013730));
                routeQuery.addWaypoint(QtPositioning.coordinate(51.060790, 16.994307));
                routeQuery.addWaypoint(toCoordinate);
                routeQuery.travelModes = RouteQuery.PedestrianTravel
                update();
            }
        }

        MapItemView {
            model: routeModel
            delegate: Component{
                MapRoute {
                    route: routeData
                    line.color: "green"
                    line.width: 4
                    smooth: true
                }
            }
        }

        GeocodeModel {//retest it
            id: geocodeModel
            plugin: map.plugin
            onStatusChanged: {
                if ((status == GeocodeModel.Ready) || (status == GeocodeModel.Error))
                    map.geocodeFinished()
            }
            onLocationsChanged:
            {
                currentCoordinate = QtPositioning.coordinate(get(0).coordinate.latitude, get(0).coordinate.longitude)
            }
        }

    } //map

    Timer {
        interval: 10 * 1000 //10 sec
        running: startTime > 0
        repeat: true
        onTriggered: {
            console.log("biegam sobie")
            // markers.addMarker(currentCoordinate) // every 10 second a marker is added, THIS DOESN'T WORK ON DESKTOP
            // routeQuery.addWaypoint(currentCoordinate);

            //showing time
            fullRunTime++

            //counting distance
            for (var i = 0; i < markers.length - 1; i++) {
                temporaryDistance += markers[i].distanceTo(markers[i+1])
            }
            fullDistance = temporaryDistance
            temporaryDistance = 0.0
            viewmodel.dbModel.setMonday_km(fullDistance) //tutaj powinnismy dostawac nasze wartosci, ale nie dostajemy
        }
    }

    onTrainButtonClicked: { 
        if(startTime === 0.0) { //we start running
            routeQuery.clearWaypoints() //czyscimy waypointy jak przestajemy biegac
            timeElapsed = 0.0
            timerTriggered = 0
            fullDistance = 0.0
            startTime = new Date().getTime()
        }
        else { //we stop running
            timeElapsed = (new Date().getTime() - startTime) / 1000
            startTime = 0.0
        }
    }

    function addMarker(currentCoordinate)
    {
        myArray.push(currentCoordinate)


        // marker = currentCoordinate
        // //update list of markers
        // var myArray = new Array()
        // for (var i = 0; i<count; i++){
        //     myArray.push(markers[i])
        // }
        // myArray.push(marker)
        // markers = myArray
    }
} //item



// lista zadan:
// - dodanie czasu i odleglosci w jakis sposob do cpp
// - dodanie tych wartosci z cpp do bazy danych
// - deployment
// - dodawanie wartosci w zaleznosci od dnia tygodnia