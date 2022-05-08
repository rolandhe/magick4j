#!/bin/sh

OS_NAME="`uname`"
echo  $OS_NAME


rm -fr build
mkdir build
cd build
cmake ..
make

if [ $OS_NAME = "Darwin" ];then
  # Mac OS X 操作系统
  echo "please run: sudo cp build/libMagick4J.dylib /usr/local/lib"
else
  # GNU/Linux操作系统
  echo "linux, and will install"
  sudo make install
fi


