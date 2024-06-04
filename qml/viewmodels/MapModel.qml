import QtQuick
import QtPositioning
import QtLocation
import DataBaseModel
import "../Helper.js" as Helper

Item {
    id: root

    property DataBaseViewModel viewModel: DataBaseViewModel {}

	//properties for checking which day is it
	property var days: ['Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday']
    property var now: new Date()
    readonly property string dateString: days[ now.getDay() ]

    //showing route properties
    property variant currentCoordinate
    property variant markers: []

    //showing time and distane properties, in meters and seconds
    property double fullDistance: 0.0  //for database
	property int fullRunTime: 0 //this is in 10 seconds 
	property double temporaryDistance: 0.0
	property double startTime: 0.0
	readonly property int timerRefreshRate: 10

    signal trainButtonClicked

    Plugin {
        id: plugin
        name: "osm" //mapboxgl not working for routing right now
        PluginParameter {
            name: "osm.mapping.providersrepository.disabled"
            value: "true"
        }
        PluginParameter {
            name: "osm.mapping.providersrepository.address"
            value: "http://maps-redirect.qt.io/osm/5.6/"
        }
    }

    Map { //map doesn't work on android and desktop for now
        id: map
//         // gesture.enabled: true //no sign of it in qt 6.5
//         anchors.fill: parent
//         plugin: plugin
//         zoomLevel: 15
//         center: src.position.coordinate
//         activeMapType: map.supportedMapTypes[0]
//         copyrightsVisible: false
//         RouteModel {
//             id: routeModel
//             plugin: plugin
//             query: RouteQuery {id: routeQuery }
//             Component.onCompleted: {
//                 // routeQuery.addWaypoint(currentCoordinate); //
//                 //Could not find any constructor for value type QGeoCoordinate to call with value undefined
// // "Could not convert argument 0 at"
// // 	 "expression for onCompleted@qrc:/viewmodels/MapModel.qml:57"
// // qrc:/viewmodels/MapModel.qml:57: TypeError: Passing incompatible arguments to C++ functions from JavaScript is not allowed.
// //todo chyba nie dzialaja rzeczy z geo
//                 // routeQuery.travelModes = RouteQuery.PedestrianTravel
//                 // update();
//             }
//         }

//         MapItemView {
//             model: routeModel
//             delegate: Component{
//                 MapRoute {
//                     route: routeData
//                     line.color: "green"
//                     line.width: 4
//                     smooth: true
//                 }
//             }
//         }
//         PositionSource {
//             id: src
//             updateInterval: 1000
//             active: true
//             onPositionChanged: {
//                 var coord = src.position.coordinate;
//                 root.currentCoordinate = coord
//                 map.center = coord
//             }
//         }

    } //map

    Timer {
        interval: timerRefreshRate * 1000 //10 sec
        running: startTime > 0
        repeat: true
        onTriggered: {
            console.warn("Timer is running - Run starts")

            //reading time elapsed
            fullRunTime++

            markers.push(currentCoordinate) // current coordinate is pushed to markers array
            routeQuery.addWaypoint(currentCoordinate);//and to the map
			      routeModel.update()

            for (var i = 0; i < markers.length - 1; i++) {
                temporaryDistance += markers[i].distanceTo(markers[i+1])
            }
            
            fullDistance = temporaryDistance
            temporaryDistance = 0.0

            // propagating values to c++ backend
            DbModel.setWeek(root.dateString, fullDistance, fullRunTime * timerRefreshRate)
        }
    }

    onTrainButtonClicked: { 
        if(startTime === 0.0) { //we start running
            // now we reset everything
            routeQuery.clearWaypoints()
            fullDistance = 0.0
            fullRunTime = 0.0
            //we start running, until second clicked() signal occurs, the time is here
            startTime = new Date().getTime()
        }
        else { //we stop running
            startTime = 0.0
        }
    }

} //item

