#!/bin/bash

docker run -it --rm \
--device /dev/dri/ \
-e DISPLAY=$DISPLAY \
-v /tmp/.X11-unix:/tmp/.X11-unix \
-v $PWD:/workspace \
-w /workspace/build \
--name qt-android-docker qt6-android:1.0.0


docker run -it --rm -v "${PWD}:/home/user/project:ro" stateoftheartio/qt6:6.3-android-aqt \
    sh -c 'qt-cmake ./project -G Ninja -B ./build; cmake --build ./build'