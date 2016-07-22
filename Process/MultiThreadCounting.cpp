//
// Created by mahat on 22.07.2016.
//

#include <thread>
#include "MultiThreadCounting.h"


MultiThreadCounting::MultiThreadCounting(FastQDataContainer container) : CounterBase(container) {

}

std::map<std::string, int> MultiThreadCounting::count() {
    // check number of available threads
    unsigned concurentThreadsSupported = std::thread::hardware_concurrency();
    if (concurentThreadsSupported == 0){
        // exception throws
    }
    // create threads

    // count and store in a map
    // return map

    return CounterBase::count();
}
