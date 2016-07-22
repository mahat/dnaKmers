#include <iostream>
#include <vector>
#include "IO/FastQDataContainer.h"

using namespace std;

int main(int argc, char *argv[]) {
    string fname = "/home/mahat/Projects/dnaKmers/data/ERR047698.filt.fastq";
    FastQDataContainer container;
    container.readFromFile(fname);
    std::vector<std::list<std::string>> r = container.split(2);

    for (int i = 0;i < 2;i++) {
        int count = 0;
        cout << "vector " << i << endl;
        for (string str : r[i]) {
            cout << str << endl;
            if (count++ > 10) {
                break;
            }
        }
    }

    return 0;
}