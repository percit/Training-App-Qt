
./tools/build-desktop.sh && ./build/src/Training-app


# we settingspage.qml jest ustawianie czasu powiadomienia, mozesz to zaimplementowac
okej to notyfikacje dzialaja, trzeba tez przetestowac ten czas czy timer sie dobrze odpala

generalnie to tez problem, ze to sie nie odpala codziennie, a powinno(nawet jak sie nie wybierze godziny, to powinno byc default)


- udalo mi sie zbudowac apk, wlasnie testuje
- jak odpale ten test to apka sie crashuje, bede musial debugowac przez qtcreator



odkomentuj w src/cmakelists ta jave i te wszystkie notification
https://forum.qt.io/topic/93962/push-notifications-in-qt/15
generalnie to dodalem ten kod, ale musze przetestowac na androidzie, ale wyglada chyba git?
https://bugfreeblog.duckdns.org/2024/02/showing-local-notifications-in-qt.html =>
- duzo rzeczy ktorych nie potrzebuje
- musze miec caly projekt jako dependency (o ile dziala)
- probowalem dodac tylko to co potrzebuje,ale masa bledow ktorych nie rozumiem



generalnie to te funkcje z notyfikacjami powinny byc w ifdefach, a ifelse dac z "to dziala tylko na androidzie"

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