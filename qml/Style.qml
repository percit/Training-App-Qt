pragma Singleton
import QtQuick 2.3

QtObject {
  // readonly property double scaleY: Screen.height / 612
  // readonly property double scaleX: Screen.width / 375
  readonly property double scaleY: 1 
  readonly property double scaleX: 1
  readonly property color backgroundColor: "#2C3F58"
  readonly property color red: "#B81E12"
  readonly property color darkRed: "#FF0000"
  readonly property color green: "#41C864"
  readonly property color yellow: "#FFC531"



  function makeColorWithOpacity(color, opacity) {
	return Qt.rgba(color.r, color.g, color.b, opacity)
  }
  readonly property color black: "#150C00"
  readonly property color white: "#FFFFFF"
  
  readonly property color black10: makeColorWithOpacity(black, 0.10)
  readonly property color white10: makeColorWithOpacity(white, 0.10)
  readonly property color black30: makeColorWithOpacity(black, 0.30)
  readonly property color white30: makeColorWithOpacity(white, 0.30)
  readonly property color black50: makeColorWithOpacity(black, 0.50)
  readonly property color white50: makeColorWithOpacity(white, 0.50)
  readonly property color black75: makeColorWithOpacity(black, 0.75)
  readonly property color white75: makeColorWithOpacity(white, 0.75)




    readonly property font fontNormal8:Qt.font({
        family: "Open Sans",
        weight: Font.Normal,
        pointSize: 8
    })
    readonly property font fontNormal12:Qt.font({
        family: "Open Sans",
        weight: Font.Normal,
        pointSize: 12
    })
    readonly property font fontNormal13:Qt.font({
        family: "Open Sans",
        weight: Font.Normal,
        pointSize: 13
    })
    readonly property font fontNormal15:Qt.font({
        family: "Open Sans",
        weight: Font.Normal,
        pointSize: 15
    })

    readonly property font fontDemiBold12:Qt.font({
        family: "Open Sans",
        weight: Font.DemiBold,
        pointSize: 12
    })

    readonly property font fontBold12:Qt.font({
        family: "Open Sans",
        weight: Font.Bold,
        pointSize: 12
    })
    readonly property font fontBold13:Qt.font({
        family: "Open Sans",
        weight: Font.Bold,
        pointSize: 13
	})
	readonly property font fontBold16:Qt.font({
        family: "Open Sans",
        weight: Font.Bold,
        pointSize: 16
	  })
    readonly property font fontBold22:Qt.font({
        family: "Open Sans",
        weight: Font.Bold,
        pointSize: 22
	  })
}
