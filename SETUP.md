# To build with QtCreator
- Download Qt 6.7 for Android https://doc.qt.io/qt-6/android-getting-started.html
- download java (instructions here: https://doc.qt.io/qt-6/android-getting-started.html)
- download Qt Positioning, Qt Location and Qt5 Compat using Qt Meintenance tool
- https://doc.qt.io/qtcreator/creator-developing-android.html#specifying-android-device-settings configure qt for android with this instruction

It builds few minutes, so don't worry

# To deploy to phone:




- Enable Developer Mode and USB Debugging:
- On your Android phone, enable Developer Mode and USB debugging. This can typically be done by going to Settings > About phone and tapping the Build number several times. Then, go to Settings > Developer options and enable USB debugging.
- Make sure your device is in File Transfer mode (or MTP mode).
- in Run in Kits for android turn debugger settings for cpp and android on if you want logs
- I have encountered an issue that libplugins_position_qtposition_android_armeabi-v7a.so would not copy to build/Android_Qt_6_7_1_Clang_armeabi_v7a-Debug/src/android-build/libs/armeabi-v7a so I did it by hand



# To build with docker
Desktop:
- sudo ./tools/docker-build.sh
- sudo ./tools/run-docker.sh

Android
- sudo ./apk-build/docker-android-build.sh
- sudo ./apk-build/run-android-docker.sh