//
// Created by Paolo Octoman on 3/23/23.
//

#ifndef INC_3_20PROJ_FILEREADER_H
#define INC_3_20PROJ_FILEREADER_H



#include <string>
#include <vector>
#include "Word.h"

class FileReader {
public:
    FileReader();
    FileReader(const std::string& filename);
    std::vector<std::string> getWords() const;
    void printList();

private:
    std::vector<std::string> mWords;
    std::vector<Word> drawableWordsVec;
};

#endif