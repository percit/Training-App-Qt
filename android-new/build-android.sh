#!/bin/bash

qt-cmake . -G Ninja -B build_android -DQT_ANDROID_BUILD_ALL_ABIS=YES
cmake --build build_android --target apk
jesli uzyje tego powyzej i wywale to :
if(ANDROID)
  include(AddQtAndroidApk.cmake)
  add_qt_android_apk(Training-app-apk Training-app)
endif()
z cmake to sie buduje, ale buduje sie libka, a nie apk i ja nie wiem dlaczego, trzeba pewnie pokombinowac z naprawieniem tego w qt creatorze, a dopiero potem w dokerze


#to nie dziala
# qt-cmake . -DQT_ANDROID_BUILD_ALL_ABIS=YES
# cmake --build . --target apk

#to powinno dzialac i costam sie dzieje, ale sie wywala jeszcze, wiec cos tam brakuje
# /./opt/Qt/6.5.0/android_arm64_v8a/bin/qt-cmake -DQT_ANDROID_BUILD_ALL_ABIS=TRUE -DANDROID_SDK_ROOT=/opt/android-sdk -DANDROID_NDK_ROOT=/opt/android-sdk/ndk/25.1.8937393 -DQT_CHAINLOAD_TOOLCHAIN_FILE=/opt/android-sdk/ndk/25.1.8937393/build/cmake/android.toolchain.cmake  -S . -B build_android -GNinja