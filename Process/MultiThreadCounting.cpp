//
// Created by mahat on 22.07.2016.
//

#include <iostream>
#include <thread>
#include <vector>
#include <unordered_map>
#include <list>
#include <map>
#include <time.h>
#include <queue>
#include "MultiThreadCounting.h"


using namespace std;

MultiThreadCounting::MultiThreadCounting(FastQDataContainer &container, int length,bool multiThread) : CounterBase(container) {
    this->container = container;
    this->length = length;
    this->multiThread = multiThread;
}

unordered_map<string, int> MultiThreadCounting::count() {

    //start_t = clock();
    if (!this->multiThread) {
        cout << "running with none threads" << endl;
        unordered_map<string, int> subResult;
        worker(-1, this->length, 0, container.getData().size(), container.getData(), subResult);
        return subResult;
    }
    // check number of available threads
    unsigned concurentThreadsSupported = std::thread::hardware_concurrency();
    cout << "avaliable threads: " << concurentThreadsSupported << endl;

    // create threads
    // maping workers
    vector<thread> threads(concurentThreadsSupported);

    vector<unordered_map<string, int>> subResults(concurentThreadsSupported);

    vector<int> bounds = this->container.getDataBounds(concurentThreadsSupported);

    for (int i = 0; i < concurentThreadsSupported; i++) {
        threads[i] = thread(&MultiThreadCounting::worker, this, -1, this->length, bounds[i], bounds[i + 1],
                            ref(this->container.getData()), ref(subResults[i]));
    }

    // join threads
    for (auto &t : threads) {
        t.join();
    }
    // reduce results
    unordered_map<string, int> reduce;
    for (auto &sR : subResults) {
        for (auto it = sR.begin(); it != sR.end(); ++it) {
            reduce[it->first] += it->second;
        }
    }


    return reduce;
}

vector<pair<string, int>> MultiThreadCounting::getTopN(int n) {
    unordered_map<string, int> counts = this->count();


    int maxVal;
    struct Order {
        bool operator()(pair<string, int> const &a, pair<string, int> const &b) const {
            return a.second < b.second;
        }
    };

    priority_queue<pair<string, int>, vector<pair<string, int>>, Order> pQ;

    for (auto it = counts.begin(); it != counts.end(); ++it) {
        if(maxVal < it->second) {
            pQ.push(make_pair(it->first,it->second));
        }
    }
    vector<pair<string, int>> result(n);
    for (int i = 0 ;i < n;i++) {
        result[i] = pQ.top();
        pQ.pop();
    }

    return result;
}

void MultiThreadCounting::worker(const int id, const int l, int begin, int end, vector<string> &data,
                                 unordered_map<string, int> &map) {

    for (int i = begin; i < end; ++i) {
        string str = data[i];
        for (int i = 0; i <= str.length() - l; i++) {
            string key = str.substr(i, l);
            // adding mutex
            // lock
            if (id != -1)
                thread_mutex.lock();
            map[key]++;
            if (id != -1)
                thread_mutex.unlock();
            // unlock
        }
    }


    //cout << "worker with id: " << id << "is ended" << endl;

}


