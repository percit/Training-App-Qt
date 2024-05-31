
./tools/build-desktop.sh && ./build/src/Training-app




# dodaj faktyczne testy do tego co sie da
testy napisane, ale mam problem z linkowaniem, bo mam undefined wszedzie, moze poszukaj projektow z dysku twardego, zeby porownac


# firebase - //this is a bit of a hack, bc firebase produces some weird string, that I don't want rn TODO: find solution when free time



# firebase
- przetestuj firebase auth
- z jakiegos powodu to zmieniam maila na regex np test@gmail.com, tak nie powinno byc i tego nie powinienem tak ogarniac


# docker do budowania na androida (znalazlem nowy link do dockerfile)
ten link ponizej jedynie co dal to libke
1. https://doc.qt.io/qt-6/android-getting-started.html sprobuj zbudowac caly projekt na qtcreatorze
- pobralem qt creator
- brakuje javy to pobralem stad: https://doc.qt.io/qt-6/android-getting-started.html
- to co qt creator sam skonfiguruje to uzywam stad: https://doc.qt.io/qtcreator/creator-developing-android.html#specifying-android-device-settings
- udalo sie zrobic setup, ale nie moge zbudowac apk, bo musze ustawic telefon do budowania

2. jesli nie dziala to zrob hello world z androida przez qt creator i popraw cmake
3. wtedy popraw dockera


https://github.com/state-of-the-art/qt6-docker/tree/master/6.5-android-aqt to poprobuj, bo to nizej to pewnie nie odpisze typ
generalnie to jakos dziala i buduje, ale zamiast apk, to buduje .so


jesli dziala to trzeba dodac moduly do qt
zmienic nazwy
dodac skrypty do budowania i odpalania
wyczyscic historie gita



- to tak, zbudowalem kontener, ale jak probuje cos budowac, to build folder jest pusty
- napisalem do tworcy w tej sprawie, moze pomoze: https://github.com/a12e/docker-qt/issues/8


https://dominikberner.ch/cmake-android-apk-and-qt/ to tez znalazlem

# we settingspage.qml jest ustawianie czasu powiadomienia, mozesz to zaimplementowac
https://forum.qt.io/topic/93962/push-notifications-in-qt/15
generalnie to dodalem ten kod, ale musze przetestowac na androidzie, ale wyglada chyba git?

# bazy danych powinny byc tworzone przez design patterny i solid
dlaczego ja w databasemodel ciagle tworze obiekt Database db(nazwa) ???

ostateczne rozwiazanie
- interfejs database, ktory ogarnia podstawowe info
- potem firebase i sqldatabase klasy, ktore implementuja te wszystkie updateElement itd
- a na koncu firebase i sql model, ktore maja implementacje pod konkretnie qproperty

plus wymysl w koncu jakas konwencje nazw, a nie database, firebase_database i DatabaseModel, 3 rozne konwencje xd


tok myslenia:
- generalnie to w database.h itd to mam obsluge bazy danych sql, a w databasemodel uzywam jej, zeby ustawic wszystko pod moja apke i podlaczyc pod qml, which is good
- potem jest firebase database, ktore robi to samo, ale 2 naraz, nie do konca wiem czy to dobrze
- moze by zrobic wlasnie taka database_sql, database_firebase, a potem database model i sobie moge podrzucic dane do obu? tylko wtedy qproperty nie bedzie dzialalo, wiec chyba potrzebuje modeli


-  ogarnij jak naprawde powinna byc tworzona baza danych, takze takie lokalne storage jak powinno byc ogarniete, bo to co robisz z sqlitem teraz jest tak naprawde meh, nawet maila tutaj nie wrzucisz, moze json jako local storage?




# przetestuj wszystko co sie da recznie