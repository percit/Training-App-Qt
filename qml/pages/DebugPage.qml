import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQml 2.3
import StyleSingleton 1.0
import "../utils"
import "../viewmodels"
import "../Helper.js" as Helper
import DataBaseModel 1.0
import FirebaseDataBase 1.0

MainPage {
	id: root

	placeholder: false

    signal loadFromFirebaseToDatabase()//tbh to nwm co z tym tutaj zrobic? moze to pozniej by przeszlo do DataBaseViewModela?
    signal loadFromDatabaseToFirebase()//pomysle pozniej, najpierw zrob mocki, ktore dzialaja

    //console.log(viewModel.weeklyKmRunFb)
	// FbDatabase.testFirebaseFuncWithMail("test1")

    Rectangle {
        id:logButton
        color: "white"
        width: 100; height: 100
        MouseArea {
            anchors.fill: parent
            onClicked:{
                console.log("log Button")
                //funkcja q_invokable, ktora wszystko zeruje
                DbModel.clearAllData();

                //updating database TODO recheck if this updates nicely
                DbModel.setLongestDuration(FbDatabase.longestDuration);
                DbModel.setLongestDistance(FbDatabase.longestDistance);
                DbModel.setBestPace(FbDatabase.bestPace);
                DbModel.setDailyGoal(FbDatabase.dailyGoal);
                DbModel.setWeeklyGoal(FbDatabase.weeklyGoal);

                //dodaj wartosci z firebase do tego
            }
        }   
    }
    Rectangle {
        id:reloadButton
        color: "black"
        width: 100; height: 100
        anchors.top: logButton.bottom
        MouseArea {
            anchors.fill: parent
            onClicked:{
                console.log("reload Button")
                FbDatabase.setLongestDistance(DbModel.longestDistance);
                FbDatabase.setLongestDuration(DbModel.longestDuration);
                FbDatabase.setLongestDistance(DbModel.longestDistance);
                FbDatabase.setBestPace(DbModel.bestPace);
                FbDatabase.setDailyGoal(DbModel.dailyGoal);
                FbDatabase.setWeeklyGoal(DbModel.weeklyGoal);

                FbDatabase.postValues("test1");//TODO I suppose it should work, I have no internet, so no way to test it
                FbDatabase.testFirebaseFuncWithMail("test1")

                //jakas funkcja na post tutaj
            }
        }   
    }
}
//tutaj jakis sygnal, ktory raz dziennie sie wstawi, ze bedzie przy logowaniu wywolywal
// funkcje z database i aktualnial je przy logow

//logowanie / rejestracja:
//laduje funkcje z firebase plus zeruje wszystkie inne wartosci (zrob funkcje q_invokable, ktora na wszystkim da clear)


//1. zrob 2 sygnaly i buttony, gdzie zmockujesz logowanie, rejestracje i to ladowanie raz dziennie

//2. logowanie/rejestracja:
//wywoluje funkcje q_invokalbe, ktora cala reszte wyzeruje
//pobieram wartosci z firebase (to ma byc pozniej, bo inaczej sie wszystko poblokuje)

//3. ladowanie raz dziennie
//onUpdateFirebaseWithDatabase
//i tutaj biore wszystkie wartosci (moge zrobic duza funkcje z duza iloscia zmiennych i w qml updatowac wszystko)
//i tutaj ostatecznie by byl timer, ktory by takie rzeczy ustawial


//4. takze popraw te wszystkie maxy, zeby nie braly juz tylko wartosci z tygodnia, ale poprzedniego maksa