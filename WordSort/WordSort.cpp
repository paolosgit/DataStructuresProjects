//
// Created by Paolo Octoman on 3/23/23.
//

#include "WordSort.h"
#include "../Helpers/Position.h"
#include <algorithm>
#include <cctype>
#include <string>

void WordSort::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (int i = 0; i < drawingVec.size(); ++i) {
        window.draw(drawingVec[i]); //testing the first 1
    }
}

void WordSort::prioritize(std::string tiText, const TextInput& ti) {
    Heap<Word> heap;

    if (!drawingVec.empty()){
        drawingVec.clear();
    }

    FileReader fr("WordSort/Words.txt");
    auto wordsStr = fr.getWords();

    if (!tiText.empty()){
        for (int i = 0; i < wordsStr.size(); ++i) {
            Word drawableWord;
            drawableWord.setWord(wordsStr[i]);
            std::transform(wordsStr[i].begin(), wordsStr[i].end(), wordsStr[i].begin(),
                           [](unsigned char c){ return std::tolower(c); });
            for (int j = 0; j < tiText.size(); ++j) {
                if (tiText[j] == wordsStr[i][j]){
                    drawableWord +=1;
                }
            }

            std::transform(wordsStr[i].begin(), wordsStr[i].end(), wordsStr[i].begin(), ::toupper);
            for (int j = 0; j < tiText.size(); ++j) {
                if (tiText[j] == wordsStr[i][j]){
                    drawableWord +=1;
                }
            }

            heap.push(drawableWord);
        }


        for (int i = 0; i < heap.getHeap().size(); ++i) {
            if (heap.getHeap()[i].getPriority() >0){
                drawingVec.push_back(heap.getHeap()[i]);
            }
        }

        Position::bottom(ti, drawingVec[0]);


        for (int i = 1; i < drawingVec.size(); ++i) {
            Position::bottom(drawingVec[i-1] , drawingVec[i]);
        }



    }



}

WordSort::WordSort() {

}

WordSort::WordSort(std::string filename) {

}

void WordSort::update() {

}
