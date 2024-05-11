#!/bin/bash

docker build -f Dockerfile-android -t qt5-android:1.0.0 .


#tbh to mozna by bylo dawac argi rozne do tego, zeby zamieniac android i desktop

# docker run -it --rm \
# --device /dev/dri/ \
# -e DISPLAY=$DISPLAY \
# -v /tmp/.X11-unix:/tmp/.X11-unix \
# -v $PWD:/workspace \
# -w /workspace/build \
# --name qt-docker qt5-android:1.0.0

# docker run -it --rm \
# --device /dev/dri/ \
# -e DISPLAY=$DISPLAY \
# -v /tmp/.X11-unix:/tmp/.X11-unix \
# -v $PWD:/workspace \
# -w /workspace/build \
# --name qt-docker qt-android