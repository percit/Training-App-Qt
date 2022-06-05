import QtQuick 2.3
import QtPositioning 5.6
import QtLocation 5.11
import DataBaseModel 1.0
import "../Helper.js" as Helper

Item {
    id: root

    property DataBaseViewModel viewModel: DataBaseViewModel {}

    property double fullDistance: 0.0  //distance in meters
    property double fullRunTime: 0.0 //time in seconds
    property var days: ['Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday']
    property var now: new Date()
    readonly property string dateString: days[ now.getDay() ]





    //counting distance helper properties
    property double temporaryDistance: 0.0
    property variant currentCoordinate

    // property int temporaryValue: 0
    // property variant coord1: QtPositioning.coordinate(51.115543, 17.129033)
    // property variant coord2: QtPositioning.coordinate(51.115738, 17.128733)
    // property variant coord31: QtPositioning.coordinate(51.114642, 17.130270)
    // property variant coord32: QtPositioning.coordinate(51.114874, 17.127304)
    // property variant coord3: QtPositioning.coordinate(51.115921, 17.128475)
    //coord1, coord2,coord31, coord32, coord3,
    // property variant coord4: QtPositioning.coordinate(51.116214, 17.128558)
    // property variant coord5: QtPositioning.coordinate(51.116416, 17.128879)
    // property variant coord6: QtPositioning.coordinate(51.116692, 17.128844)
    // property variant coord7: QtPositioning.coordinate(51.116977, 17.129032)
    // property variant coord8: QtPositioning.coordinate(51.117227, 17.129305)
    // property variant coord9: QtPositioning.coordinate(51.117463, 17.129479)
    // property variant coord10: QtPositioning.coordinate(51.117700, 17.129184)
    // property variant markers: [ coord4, coord5, coord6, coord7, coord8, coord9, coord10]
    
    
    property variant markers:[]

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
        PluginParameter {
            name: "osm.mapping.providersrepository.disabled"
            value: "true"
        }
        PluginParameter {
            name: "osm.mapping.providersrepository.address"
            value: "http://maps-redirect.qt.io/osm/5.6/"
        }
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
                routeQuery.addWaypoint(currentCoordinate);
                // routeQuery.addWaypoint(fromCoordinate);
                // routeQuery.addWaypoint(toCoordinate);
                // routeQuery.addWaypoint(markers[0]);
                // routeQuery.addWaypoint(markers[2]);
                // routeQuery.addWaypoint(markers[3]);
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
        interval:10000 //10 sec
        running: startTime > 0
        repeat: true
        onTriggered: {
            console.warn("biegam sobie")

            //showing time
            fullRunTime++


            // routeQuery.addWaypoint(markers[temporaryValue]);
            // routeModel.update()
            // fullDistance += markers[root.temporaryValue].distanceTo(markers[root.temporaryValue+1])
            // root.temporaryValue++



            markers.push(currentCoordinate); // every 10 second a marker is added
            routeQuery.addWaypoint(currentCoordinate);
            routeModel.update();

            // counting distance
            for (var i = 1; i < markers.length - 1; i++) {
                temporaryDistance += markers[i].distanceTo(markers[i+1]);
            }
            
            fullDistance = temporaryDistance
            temporaryDistance = 0.0

            //propagating values to c++ backend
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
            DbModel.updateDataBaseFile()
        }
    }

    onTrainButtonClicked: { 
        if(startTime === 0.0) { //we start running
            routeQuery.clearWaypoints() //czyscimy waypointy jak przestajemy biegac
            timeElapsed = 0.0
            fullDistance = 0.0
            fullRunTime = 0.0
            startTime = new Date().getTime()
        }
        else { //we stop running
            timeElapsed = (new Date().getTime() - startTime) / 1000
            startTime = 0.0
        }
    }

} //item
