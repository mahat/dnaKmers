//
// Created by mahat on 22.07.2016.
//

#ifndef DNAKMERS_FASTQREADER_H
#define DNAKMERS_FASTQREADER_H

#include <iostream>
#include <vector>
#include <string>
#include <list>

class FastQDataContainer {
public:
    std::vector<std::list<std::string>> split(int n);
    std::vector<std::string> &getData() ;
    friend std::istream& operator>>(std::istream& is, FastQDataContainer& container);
    void readFromFile(std::string fname);
    std::vector<int> getDataBounds(int parts);
    FastQDataContainer();

private:
    std::vector<std::string> data;
};


#endif //DNAKMERS_FASTQREADER_H
