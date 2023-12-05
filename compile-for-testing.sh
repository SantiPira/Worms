#!/bin/bash

sudo rm -r build

mkdir build

cd build

cmake -DTESTING=ON ..

make -j4