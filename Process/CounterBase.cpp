//
// Created by mahat on 22.07.2016.
//



#include "CounterBase.h"

CounterBase::CounterBase(const FastQDataContainer &container) : container(container) {
    this->container = container;
}

std::vector<std::pair<std::string, int>> CounterBase::getTopN(int n) {
    return std::vector<std::pair<std::string, int>>();
}




