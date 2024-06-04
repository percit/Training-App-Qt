Enable Developer Mode and USB Debugging:
On your Android phone, enable Developer Mode and USB debugging. This can typically be done by going to Settings > About phone and tapping the Build number several times. Then, go to Settings > Developer options and enable USB debugging.

Make sure your device is in File Transfer mode (or MTP mode).

w run w kitach wlacz debugger settings dla cpp i qml

z jakiegos powodu libplugins_position_qtposition_android_armeabi-v7a.so sie nie kopiuje do build/Android_Qt_6_7_1_Clang_armeabi_v7a-Debug/src/android-build/libs/armeabi-v7a


moze dodaj do clocks positioning i jakis pusty import i sprobuj zbudowac => to moze byc qtbug


w qt meintainence musialem jeszcze location module pobrac


okej, to udalo mi sie zbudowac przy pomocy qt creatora, na dokerze tez chyba zadziala

taski:
- odpal clocks z tym positioning na qtcreatorze do telefonu i zobacz czy dziala => dziala, weird
- zbuduj apk z poziomu dockera
- zbuduj apke teraz na desktopie, czy dalej dziala



# wersja z qtcreatorem
\1. https://doc.qt.io/qt-6/android-getting-started.html sprobuj zbudowac caly projekt na qtcreatorze
- pobralem qt creator
- brakuje javy to pobralem stad: https://doc.qt.io/qt-6/android-getting-started.html
- to co qt creator sam skonfiguruje to uzywam stad: https://doc.qt.io/qtcreator/creator-developing-android.html#specifying-android-device-settings
CO DO QTCREATORA TO PRZY ANDROID TO MUISSZ DODAC POSITIONING I QT5 COMPAT