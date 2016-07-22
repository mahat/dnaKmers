//
// Created by mahat on 22.07.2016.
//

#include "CounterBase.h"

CounterBase::CounterBase(const FastQDataContainer &container) : container(container) {
    this->container = container;
}

std::map<std::string, int> CounterBase::count() {
    return std::map<std::string, int>();
}
