#!/bin/bash

docker run -it --rm \
--device /dev/dri/ \
-e DISPLAY=$DISPLAY \
-v /tmp/.X11-unix:/tmp/.X11-unix \
-v $PWD:/workspace \
-w /workspace/build \
--name qt-docker qt5:1.0.0