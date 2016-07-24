//
// Created by mahat on 22.07.2016.
//

#ifndef DNAKMERS_MULTITHREADCOUNTING_H
#define DNAKMERS_MULTITHREADCOUNTING_H


#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <mutex>
#include "CounterBase.h"

using namespace std;

class MultiThreadCounting : public CounterBase{
private:
    int length;
    void worker(const int id,const int l, int begin, int end,vector<string> &data,unordered_map<string,int> &map);
    unordered_map<string,int> count();
    mutex thread_mutex;
    clock_t start_t;
    bool multiThread;
public:
    MultiThreadCounting(FastQDataContainer &container,int length,bool multiThread);
    vector<pair<string,int>> getTopN(int n);

};


#endif //DNAKMERS_MULTITHREADCOUNTING_H
