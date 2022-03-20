pragma Singleton
import QtQuick
import QtQuick.Window

QtObject {
  // readonly property double scaleY: Screen.height / 612
  // readonly property double scaleX: Screen.width / 375
  readonly property double scaleY: 1 
  readonly property double scaleX: 1
  readonly property color backgroundColor: "#2C3F58"
    readonly property font fontNormal11:Qt.font({
        family: "Open Sans",
        weight: Font.Normal,
        pointSize: 11
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
  }
