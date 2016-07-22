//
// Created by mahat on 22.07.2016.
//

#ifndef DNAKMERS_COUNTER_H
#define DNAKMERS_COUNTER_H

#include <iostream>
#include <map>
#include "../IO/FastQDataContainer.h"


class CounterBase {
protected:
    FastQDataContainer container;
public:
    CounterBase(const FastQDataContainer &container);
    virtual std::map<std::string, int> count();
};


#endif //DNAKMERS_COUNTER_H
