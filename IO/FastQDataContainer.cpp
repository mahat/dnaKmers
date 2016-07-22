//
// Created by mahat on 22.07.2016.
//

#include <fstream>
#include <cmath>
#include <array>
#include <vector>
#include <list>
#include "FastQDataContainer.h"

using namespace std;

const std::list<std::string> &FastQDataContainer::getData() const {
    return data;
}

std::vector<std::list<std::string>> FastQDataContainer::split(int n) {
    // spliting data into n chunks
    int lenChunks = (int) ceil((double) data.size() / (double) n);
    int sizeOfChunks = data.size() / n;

    std::vector<std::list<std::string>> subChunks(lenChunks);

    int index = 0,subIndex = 0;
    for (string str : this->data) {
        subChunks[index].push_back(str);
        subIndex++;
        if (subIndex == sizeOfChunks) {
            index++;
            subIndex = 0;
        }

    }
    return subChunks;

}

std::istream &operator>>(std::istream &is, FastQDataContainer &container) {
    std::string line;
    while (getline(is, line)) {
        // actual sequence
        getline(is, line);
        container.data.push_back(line);
        // dummy seq1
        getline(is, line);
        // dummy seq2
        getline(is, line);
    }
    return is;
}

FastQDataContainer::FastQDataContainer() {

}

void FastQDataContainer::readFromFile(string fname) {
    std::ifstream is(fname);
    if (!is) {
        std::cout << "Error opening output file" << std::endl;
        system("pause");
    }
    is >> *this;
}
