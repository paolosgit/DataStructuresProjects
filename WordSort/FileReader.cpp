//
// Created by Paolo Octoman on 3/23/23.
//

#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

FileReader::FileReader(const std::string& filename) {
    std::ifstream infile(filename);
    std::string line;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string word;
        iss >> word;
        mWords.push_back(word);
    }


}

std::vector<std::string> FileReader::getWords() const {
    return mWords;
}

void FileReader::printList() {
    for (int i = 0; i < mWords.size(); ++i) {
        std::cout << mWords[i] << std::endl;
    }
}

