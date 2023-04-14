//
// Created by Paolo Octoman on 3/23/23.
//

#ifndef INC_3_20PROJ_WORDSORT_H
#define INC_3_20PROJ_WORDSORT_H
#include "Word.h"
#include <SFML/Graphics.hpp>
#include "../TextInput/TextInput.h"
#include "FileReader.h"
#include <iostream>
#include <string>
#include <vector>
#include "../../heap/Heap.h"

class WordSort :public sf::Drawable{
private:
    std::vector<Word> drawingVec;

public:
    WordSort();
    WordSort(std::string filename);
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void prioritize(std::string tiText, const TextInput& ti);
    void update();
};


#endif //INC_3_20PROJ_WORDSORT_H
