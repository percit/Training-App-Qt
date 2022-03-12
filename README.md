# Training-App-Qt

This is a project made for "Projekt zespolowy" on Wroclaw University of Technology

# Setup

## Qt5

Qt5.15.x (https://tutorialforlinux.com/2021/07/17/step-by-step-qt-creator-manjaro-installation/2/  )

Qt -> Qt 5.15.x -> Desktop GCC 64 bit

Qt -> Qt 5.15.x -> Android 

Qt -> Qt 5.15.x -> Qt Quick 3D 

Qt -> Qt 5.15.x -> Qt Virtual Keyboard

Qt -> Qt 5.15.x -> Qt Quick Timeline

Qt -> Developer and Designer Tools -> CMake

Qt -> Developer and Designer Tools -> Ninja

Qt -> Developer and Designer Tools -> OpenSSL

## Android Studio

SDK Manager (at the bottom) -> Appearance & Behavior -> Android SDK

### SDK Platforms
Android 10.0
Android SKD Build-Tools 33-rc1
Android SDK Command-line Tools
Android Emulator
Android SDK Platform-Tools

### Click Package Details
32.1.0.rc1
32.0.0
30.0.2
NDK -> 21.3.6528147


## Configure Qt Creator for Android (recheck if needed)

Options -> Devices -> Android
Android SDK Locations: home/percit/Android/Sdk
Android NDK list: home/percit/Android/Sdk/ndk/21.3.6528147
OpenSSL binaries location: home/percit/Android/Sdk/android_openssl

#### if it asks You to download something, do it



## Add this to .zshrc / .bashrc


paths:
export JAVA_HOME=/usr/lib/jvm/java-8-openjdk
export ANDROID_HOME=/home/percit/Android
export ANDROID_SDK=/home/percit/Android/Sdk
export ANDROID_NDK=/home/percit/Android/Sdk/ndk/21.3.6528147
export ANDROID_NDK_TOOLCHAIN_ROOT=/home/percit/Android/Sdk/ndk/21.3.6528147/build/cmake/android.toolchain.cmake


export PATH=$PATH:$JAVA_HOME/bin
export PATH=$PATH:$ANDROID_HOME
export PATH=$PATH:$ANDROID_SDK
export PATH=$PATH:$ANDROID_NDK 
export PATH=$PATH:$ANDROID_NDK_TOOLCHAIN_ROOT
