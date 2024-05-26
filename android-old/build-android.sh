#!/bin/bash
# mkdir build_android && cd build_android
qt-cmake . -DQT_ANDROID_BUILD_ALL_ABIS=YES
cmake --build . --target apk



# cmake --preset=android -S .
# cmake --build build_android --target apk

qt-cmake . -G Ninja -B .
; cmake --build ./build