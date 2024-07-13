#!/bin/bash

if [ ! -d "build" ]; then
  mkdir build && cd build
fi
cmake .. -DBUILD_TESTS=ON
ninja -j16