#!/bin/sh

rm -fr build
mkdir build
cd build
cmake ..
make
cd ..

