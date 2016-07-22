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
    const std::list<std::string> &getData() const;
    friend std::istream& operator>>(std::istream& is, FastQDataContainer& container);
    void readFromFile(std::string fname);
    FastQDataContainer();

private:
    std::list<std::string> data;
};


#endif //DNAKMERS_FASTQREADER_H
