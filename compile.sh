#!/bin/bash

if [ -d "./build" ]
then
    
else
    mkdir build
fi

program="cmake"
condition=$(which $program 2>/dev/null | grep -v "not found" | wc -l)
if [ $condition -eq 0 ] ; then
    echo "$program is not installed"
    exit
fi


cd ./build
cmake ..
make
