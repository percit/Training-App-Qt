
./tools/build-desktop.sh && ./build/src/Training-app

# docker do budowania na androida (znalazlem nowy link do dockerfile)
https://github.com/state-of-the-art/qt6-docker/tree/master/6.5-android-aqt to poprobuj, bo to nizej to pewnie nie odpisze typ
generalnie to jakos dziala i buduje, ale zamiast apk, to buduje .so


jesli dziala to trzeba dodac moduly do qt
zmienic nazwy
dodac skrypty do budowania i odpalania
wyczyscic historie gita



- to tak, zbudowalem kontener, ale jak probuje cos budowac, to build folder jest pusty
- napisalem do tworcy w tej sprawie, moze pomoze: https://github.com/a12e/docker-qt/issues/8


https://dominikberner.ch/cmake-android-apk-and-qt/ to tez znalazlem


# dodaj faktyczne testy do tego co sie da
testy napisane, ale mam problem z linkowaniem, bo mam undefined wszedzie, moze poszukaj projektow z dysku twardego, zeby porownac


# firebase - //this is a bit of a hack, bc firebase produces some weird string, that I don't want rn TODO: find solution when free time



# firebase
- przetestuj firebase auth
- z jakiegos powodu to zmieniam maila na regex np test@gmail.com, tak nie powinno byc i tego nie powinienem tak ogarniac




# we settingspage.qml jest ustawianie czasu powiadomienia, mozesz to zaimplementowac
https://forum.qt.io/topic/93962/push-notifications-in-qt/15
generalnie to dodalem ten kod, ale musze przetestowac na androidzie, ale wyglada chyba git?

# bazy danych powinny byc tworzone przez design patterny i solid
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