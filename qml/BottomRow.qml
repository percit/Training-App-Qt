import QtQuick 2.3

Rectangle {
  id: root 
   
  width: 375 * Style.scaleX //TODO recheck these values
  height: 64 * Style.scaleY
  // color: Style.backgroundColor
  color: "yellow"
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
	spacing: (root.width - 5 * menuButton1.width) / 4
	MenuButton {
	  id: menuButton1

	  buttonOn: activeSouce === BottomRow.ActiveSource.PAGE1 
	  onClicked: {
		activeSouce = BottomRow.ActiveSource.PAGE1
		root.page1()
	  }
	}
	MenuButton {
	  buttonOn: activeSouce === BottomRow.ActiveSource.PAGE2 
	  onClicked: {
		activeSouce = BottomRow.ActiveSource.PAGE2
		root.page2()
	  }
	}
	MenuButton {
	  buttonOn: activeSouce === BottomRow.ActiveSource.PAGE3 
	  onClicked: {
		activeSouce = BottomRow.ActiveSource.PAGE3
		root.page3()
	  }
	}
	MenuButton {
	  buttonOn: activeSouce === BottomRow.ActiveSource.PAGE4 
	  onClicked: {
		activeSouce = BottomRow.ActiveSource.PAGE4
		root.page4()
	  }
	}
	MenuButton {
	  buttonOn: activeSouce === BottomRow.ActiveSource.PAGE5 
	  onClicked: {
		activeSouce = BottomRow.ActiveSource.PAGE5
		root.page5()
	  }
	}
  }
}
