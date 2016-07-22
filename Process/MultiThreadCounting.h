//
// Created by mahat on 22.07.2016.
//

#ifndef DNAKMERS_MULTITHREADCOUNTING_H
#define DNAKMERS_MULTITHREADCOUNTING_H


#include "CounterBase.h"

class MultiThreadCounting : public CounterBase{
private:
    int numberOfThreads;
public:
    MultiThreadCounting(FastQDataContainer container);
    std::map<std::string, int> count();

};


#endif //DNAKMERS_MULTITHREADCOUNTING_H
