#!/bin/bash

export CC=clang
export CXX=clang++

mkdir -p build
cd build

cmake .. \
    -DCMAKE_CPP_FLAGS="-g -Wall -Wextra" \
    -DCMAKE_CXX_FLAGS="-g -Wall -Wextra" \
    -DCMAKE_C_FLAGS="-g -Wall -Wextra"
make

mv testing ../testing
