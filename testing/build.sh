#!/bin/bash

export CC=clang
export CXX=clang++

mkdir -p build
cd build

cmake ..
make

mv testing ../testing
