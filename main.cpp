#include <iostream>
#include <vector>
#include <cstring>
#include "IO/FastQDataContainer.h"
#include "Process/MultiThreadCounting.h"

#define MEASURE_PERF 1
#define DEBUG 0

using namespace std;



int main(int argc, char *argv[]) {
    string fname ;//= "/home/mahat/Projects/dnaKmers/data/ERR047698.filt.fastq";
    int kmearSize,topcount;
    int threadSupport = 0;
    time_t start, end;
    if (MEASURE_PERF) {
        time(&start);
    }

    // reading args
    if (argc >= 6) {
        for (int i = 0; i < argc; i++) {
            if (strcmp(argv[i], "--filename") == 0) {
                fname = argv[i + 1];
            }
            if (strcmp(argv[i], "--topcount") == 0) {
                topcount = atoi(argv[i + 1]);
            }
            if (strcmp(argv[i], "--kmersize") == 0) {
                kmearSize = atoi(argv[i + 1]);
            }
            if (strcmp(argv[i], "--threadSupport") == 0) {
                threadSupport = atoi(argv[i + 1]);
            }
        }
    } else if (argc == 4) {
        fname = argv[1];
        kmearSize = atoi(argv[2]);
        topcount = atoi(argv[3]);
    }

    FastQDataContainer container;
    try {
        container.readFromFile(fname);
    } catch (int n) {
        // file not oppened exception
        cout << n << endl;
        return n;
    }

    MultiThreadCounting *counter = new MultiThreadCounting(container, kmearSize,threadSupport != 0);
    vector<pair<string, int>> f = counter->getTopN(topcount);

    cout << "==top n==" << endl;
    for (int i = 0; i < f.size(); i++) {
        std::cout << f[i].first << " " << f[i].second << endl;
    }
    if (MEASURE_PERF) {
        time(&end);
        std::cout << difftime(end, start) << " seconds" << std::endl;
    }

    return 0;
}