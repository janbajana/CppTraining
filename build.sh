#!/bin/bash

set -x

# export CC=/usr/bin/clang
# export CXX=/usr/bin/clang++

cd ./build

cmake -DCMAKE_BUILD_TYPE=Debug -GNinja ..

