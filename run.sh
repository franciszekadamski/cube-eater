#!/bin/bash

mkdir -p build
cd build || exit
cmake ..
make
cd ..
build/cube-eater
