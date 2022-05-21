import QtQuick 2.3
import StyleSingleton 1.0

Rectangle {
	id: root

	width: 375 * Style.scaleX
	height: 64 * Style.scaleY
	color: Style.black50
	signal page1
	signal page2
	signal page3
	signal page4
	signal page5

	property int activeSouce: 1
	enum ActiveSource {
		NONE,
		PAGE1,
		PAGE2,
		PAGE3,
		PAGE4,
		PAGE5
	}
	Row {
		id: bottomRow
		spacing: (root.width - 30 - 5 * menuButton1.width) / 4
		anchors.left: parent.left; anchors.leftMargin: 15 * Style.scaleX
		MenuButton {
			id: menuButton1

			buttonOn: activeSouce === BottomRow.ActiveSource.PAGE1
			onClicked: {
				activeSouce = BottomRow.ActiveSource.PAGE1
				root.page1()
			}
			source: "qrc:/assets/timer.png"
		}
		MenuButton {
			buttonOn: activeSouce === BottomRow.ActiveSource.PAGE2
			onClicked: {
				activeSouce = BottomRow.ActiveSource.PAGE2
				root.page2()
			}
			source: "qrc:/assets/achievement.png"
		}
		MenuButton {
			buttonOn: activeSouce === BottomRow.ActiveSource.PAGE3
			onClicked: {
				activeSouce = BottomRow.ActiveSource.PAGE3
				root.page3()
			}
			source: "qrc:/assets/tasks.png"
		}
		MenuButton {
			buttonOn: activeSouce === BottomRow.ActiveSource.PAGE4
			onClicked: {
				activeSouce = BottomRow.ActiveSource.PAGE4
				root.page4()
			}
			source: "qrc:/assets/run.png"
		}
		MenuButton {
			buttonOn: activeSouce === BottomRow.ActiveSource.PAGE5
			onClicked: {
				activeSouce = BottomRow.ActiveSource.PAGE5
				root.page5()
			}
			source: "qrc:/assets/run.png"
		}
	}
}
