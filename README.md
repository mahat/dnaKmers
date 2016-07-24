# Goal
This program aims to find top n K-mears in given fastQ file and prints to console

# Usage
./dnaKmers --filename [filename] --kmersize [kmersize] --topcount [topcount] --threadSupport [0,1]
OR
./dnaKmers [filename] [kmersize] [topcount]

# Features
MultiThread support: if --threadSupport != 0 it runs multi threaded. Default runs single thread
Polymorphism support: any classes extends CounterBase class can be used as different count approaches

# Running Code
Code is written in CLion and tested by CMake 3.5.2
in order to compile from strach:
- get into build folder 
- run cmake ..
- run make

Or

run compile.sh


