import QtQuick 2.3
import QtPositioning 5.6
import QtLocation 5.11
import DataBaseModel 1.0
import "../Helper.js" as Helper

Item {
    id: root

    property DataBaseViewModel viewModel: DataBaseViewModel {}

    property double fullDistance: 0.0  //distance in meters
    property double fullRunTime: timerTriggered * 10 //time in seconds
    property var days: ['Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday']
    property var now: new Date()
    readonly property string dateString: days[ now.getDay() ]

    //counting distance helper properties
    property double temporaryDistance: 0.0
    property variant currentCoordinate
    property variant markers: []

    property variant fromCoordinate: QtPositioning.coordinate(51.099695, 17.028648)
    property variant toCoordinate: QtPositioning.coordinate(51.054788, 16.970955)

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
        center: src.position.coordinate
        activeMapType: map.supportedMapTypes[0]
        copyrightsVisible: false
        RouteModel {
            id: routeModel
            plugin: plugin
            query: RouteQuery {id: routeQuery }
            Component.onCompleted: {
                routeQuery.addWaypoint(fromCoordinate);
                routeQuery.addWaypoint(toCoordinate);
                // routeQuery.addWaypoint(currentCoordinate);
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
        PositionSource {
            id: src
            updateInterval: 1000
            active: true
            onPositionChanged: {
                var coord = src.position.coordinate;
                root.currentCoordinate = coord
                map.center = coord
            }
        }

    } //map

    Timer {
        interval: 10 * 1000 //10 sec
        running: startTime > 0
        repeat: true
        onTriggered: {
            console.log("biegam sobie")
            markers.push(currentCoordinate) // every 10 second a marker is added
            routeQuery.addWaypoint(currentCoordinate);

            //showing time
            fullRunTime++

            //counting distance
            // for (var i = 0; i < markers.length - 1; i++) {
            //     temporaryDistance += markers[i].distanceTo(markers[i+1]) //chyba cos tu nie dziala?
            // }
            temporaryDistance = fromCoordinate.distanceTo(toCoordinate)
            fullDistance = temporaryDistance
            temporaryDistance = 0.0
            switch(root.dateString) {
                case 'Monday':
                    DbModel.setMonday_time(fullRunTime * 10)
                    DbModel.setMonday_km(fullDistance)
                case 'Tuesday':
                    DbModel.setTuesday_time(fullRunTime * 10)
                    DbModel.setTuesday_km(fullDistance)
                case 'Wednesday':
                    DbModel.setWednesday_time(fullRunTime * 10)
                    DbModel.setWednesday_km(fullDistance)
                case 'Thursday':
                    DbModel.setThursday_time(fullRunTime * 10)
                    DbModel.setThursday_km(fullDistance)
                case 'Friday':
                    DbModel.setFriday_time(fullRunTime * 10)
                    DbModel.setFriday_km(fullDistance)
                case 'Saturday':
                    DbModel.setSaturday_time(fullRunTime * 10)
                    DbModel.setSaturday_km(fullDistance)
                case 'Sunday':
                    DbModel.setSunday_time(fullRunTime * 10)
                    DbModel.setSunday_km(fullDistance)
            }
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

} //item


// lista zadan:
// - deployment
// easy logging
// refactor codu
// moduly
// testowanie przez gtest

