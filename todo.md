
./tools/build-desktop.sh && ./build/src/Training-app


# firebase
- przetestuj firebase auth
- z jakiegos powodu to zmieniam maila na regex np test@gmail.com, tak nie powinno byc i tego nie powinienem tak ogarniac


# firebase - //this is a bit of a hack, bc firebase produces some weird string, that I don't want rn TODO: find solution when free time
to wymaga duzo czytania dokumentacji firebase jak to ma dzialac i jak to profesjonalnie napisac


# bazy danych powinny byc tworzone przez design patterny i solid
takze jak bedziesz przepisywal, to przepisz najpierw jedna baze danych, a dopiero potem druga
takze mozesz wyedytowac jak wyglada ta baza danych, zeby byl i mail itd (albo poczytaj jak sie robi tak cos zwykle, ze nie musi byc baza danych lokalna, tylko jakis json) 
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
- rysowanie map
- maxy
- powiadomienia (raz dziennie i powinno sie powtarzac) plus jesli samemu nie ustawisz to powinno byc o 12 
- wykresy
- przeklikac wszedzie