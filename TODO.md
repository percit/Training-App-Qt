# TODO:
1. Email Authentication via Firebase - retest and fix
2. Database on Firebase - retest and fix if necessary, change from name@gmail.com -> name as parameter to name-gmail as parameter
3. Add async where it's needed
4. Add Design Patterns 
5. Add CI/CD
6. Fix building on Android (preferably on CI)



# Testing:

dodaj do updatedatabase wszystkie te maksy i zwracaj wartosci z bazy danych

dodaj sprawdzanie przy update database czy wartosci nie sa zerami (albo najlepiej wstaw jakas wartosc na minusie, to update nie wywola sie
na danej wartosci, ktora jedyne co zostala to zainicjalizowana, czyli dopoki wartosc nie wynosi -20 np to wywolasz dana funkcje i to dla kazdej linijki
to bedize gituwa O TO CZESC TO ZROB DRUGIE UPDATEMAXES NP i tutaj takze goalsy ustaw i tutaj tylko bedzie sprawdzanie tego magic numbera, bo tydzien nas nie
obchodzi, ale maksy sa na lata, wiec drugia funkcje stworz


Check if logging in and registing actually works

Test if map actually tracks data and puts in everywhere else all those maxes and so on


i budowanie na androida tez nie dziala, ale narazie olej






//wszystko powinno byc w bazie danych

dni juz sa(ale zmien settery na takie od razu uzywajace bazy danych dla dni)


zamien settery na wlasne (edytuj takze w tym Q_porperty to SET, bo musisz to usunac)
i te settery od razu update robia na 2 wartosci


ten calculate maxes bedzie odpalany tylko i wylacznie raz na 24h przy tym timerze
w nim bedzie kazde sprawdzanie wartosci z std, jesli lepsza wartosc to dopiero setter sie odpali i value = max(newValue, value)


czyli tak:

1. settery dla dni zamieniasz na 1 setter lacznie z km i time
2. od razu w tych setterach zapisujesz dane do bazy danych
3. usun SET z   Q-PROPERTY

1. stworz calculateAllMaxes i odpalaj raz na 24h
2. odczytujesz maxy tylko i wylacznie z bazy danych


1. poczysc kod
2. zbuduj paczke
3. zrob ladniejsze kolorki do UI
4. zbuduj paczke na androida 
5. opisz ladnie githuba6
6. zapomnij o tym projekcie