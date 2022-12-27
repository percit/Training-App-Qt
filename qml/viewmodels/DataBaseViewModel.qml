import QtQuick 2.3
import DataBaseModel 1.0
import "../Helper.js" as Helper
import FirebaseDataBase 1.0

QtObject {


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



    readonly property string weeklyKmRun: Helper.formatDistance(DbModel.weeklyKmRun)
    readonly property string longestDistance: Helper.formatDistance(DbModel.longestDistance)
    readonly property string longestDuration: Helper.formatDistance(DbModel.longestDuration)
    readonly property string averageDuration: Helper.formatDistance(DbModel.averageDuration)
    readonly property string allDuration: Helper.formatDistance(DbModel.allDuration)
	readonly property string bestPace: Math.round(DbModel.bestPace * 3.6 * 100) / 100
	readonly property int weeklyGoalInMeters: DbModel.weeklyGoal * 1000
    readonly property int daylyGoalInMeters: DbModel.daylyGoal * 1000
    readonly property int totalKcalRun: Math.round(DbModel.weeklyKmRun * 100) / 100 * 62

//to sa wartosci z wektora, a nie bazy danych
    readonly property double progressBarMonday: (DbModel.monday_km / daylyGoalInMeters > 1) ? 1 : DbModel.monday_km / daylyGoalInMeters
    readonly property double progressBarTuesday: (DbModel.tuesday_km / daylyGoalInMeters > 1) ? 1 : DbModel.tuesday_km / daylyGoalInMeters
    readonly property double progressBarWednesday: (DbModel.wednesday_km / daylyGoalInMeters > 1) ? 1 : DbModel.wednesday_km / daylyGoalInMeters
    readonly property double progressBarThursday: (DbModel.thursday_km / daylyGoalInMeters > 1) ? 1 : DbModel.thursday_km / daylyGoalInMeters
    readonly property double progressBarFriday: (DbModel.friday_km / daylyGoalInMeters > 1) ? 1 : DbModel.friday_km / daylyGoalInMeters
    readonly property double progressBarSaturday: (DbModel.saturday_km / daylyGoalInMeters > 1) ? 1 : DbModel.saturday_km / daylyGoalInMeters
    readonly property double progressBarSunday: (DbModel.sunday_km / daylyGoalInMeters > 1) ? 1 : DbModel.sunday_km / daylyGoalInMeters

    // // property var monday: d.dbModel.monday[fullDistance, fullRunTime]
    // // property var day: [fullDistance, fullRunTime]
    // // property var week: //to jest array dni, week.push(day)

    readonly property string weeklyKmRunFb: FbDatabase.longestDistance


    readonly property Timer refreshFirebaseTimer : Timer {//TODO retest
        interval: 3600000 //24h
        running: true
        repeat: true
        onTriggered: {
            FbDatabase.setLongestDistance(DbModel.longestDistance);
            FbDatabase.setLongestDuration(DbModel.longestDuration);
            FbDatabase.setLongestDistance(DbModel.longestDistance);
            FbDatabase.setBestPace(DbModel.bestPace);
            FbDatabase.setDailyGoal(DbModel.dailyGoal);
            FbDatabase.setWeeklyGoal(DbModel.weeklyGoal);
            FbDatabase.putValues("test2")
        }
    }
}

