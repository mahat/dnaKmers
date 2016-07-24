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

std::vector<std::string> &FastQDataContainer::getData() {
    return data;
}

std::vector<std::list<std::string>> FastQDataContainer::split(int n) {
    // spliting data into n chunks
    //int lenChunks = (int) ceil((double) data.size() / (double) n);
    int sizeOfChunks = data.size() / n;

    std::vector<std::list<std::string>> subChunks(n);

    int index = 0, subIndex = 0;
    for (string str : this->data) {
        subChunks[index].push_back(str);
        subIndex++;
        if (subIndex == sizeOfChunks && index < n - 1) {
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
        //throw "Error opening output file";
        throw -9;
    }
    is >> *this;
}

std::vector<int> FastQDataContainer::getDataBounds(int parts) {
    std::vector<int> bnd;
    int delta = this->data.size() / parts;
    int reminder = this->data.size() % parts;
    int N1 = 0, N2 = 0;
    bnd.push_back(N1);
    for (int i = 0; i < parts; ++i) {
        N2 = N1 + delta;
        if (i == parts - 1)
            N2 += reminder;
        bnd.push_back(N2);
        N1 = N2;
    }
    return bnd;
}
