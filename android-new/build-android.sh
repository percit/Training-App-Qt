#!/bin/bash

qt-cmake . -G Ninja -B build_android -DQT_ANDROID_BUILD_ALL_ABIS=YES
cmake --build build_android --target all