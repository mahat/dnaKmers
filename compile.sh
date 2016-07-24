#!/bin/bash

if [ -d "./build" ]
then
    echo ""
else
    mkdir build
fi

program="cmake"
condition=$(which $program 2>/dev/null | grep -v "not found" | wc -l)
if [ $condition -eq 0 ] ; then
    echo "$program is not installed please install $program 3.5.2"
    exit
fi


cd ./build
cmake ..
make
