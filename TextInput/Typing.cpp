//
// Created by Paolo Octoman on 3/15/23.
//

#include "Typing.h"
#include "../Helpers/Font.h"
#include "../Helpers/KeyBoardShortCuts.h"
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>

Typing::Typing() {


}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        text.clear();
    }
    if (event.type == sf::Event::TextEntered){
        if (event.text.unicode){
            if (!isFull()){
                text.addLetter(static_cast<char>(event.text.unicode), letterSize, x,y);
            }
        }
        History::pushHistory({this, getSnapshot()});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace) && text.getSize() != 0){
        History::pushHistory({this, getSnapshot()});
        text.backSpace();

    }

        if (KeyBoardShortCuts::isUndo(window, event) && !History::empty()){
            History::popHistory();
            applySnapshot(History::topHistory());
        }
}

void Typing::update() {



    for(auto iter = text.begin(); iter != text.end(); ++iter){
        if ((*iter).getString() == "+" ||(*iter).getString() == "-" || (*iter).getString() == "/"|| (*iter).getString() == "*"||(*iter).getString() == "["||(*iter).getString() == "]"||(*iter).getString() == "="){
            iter->setColor(sf::Color::Green);
        }
        else
            iter->setColor(sf::Color::Black);
        if (is_number(iter->getString())){
            iter->setColor(sf::Color::Red);
        }
    }

    auto start = text.begin();
    auto end = text.begin();

    for (; end != text.end() ; ++end) {

        if (end->getString() == " "){

            keyWordFinder(start, end);








            start = end;
            ++start;
        }






    }





}

void Typing::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text);
}

Snapshot *Typing::getSnapshot() {
    TextInputSnapshot* p = new TextInputSnapshot;
    p->setData(getText());
    return p;
}

void Typing::applySnapshot( Snapshot *snapshot) {
    std::string s = dynamic_cast<TextInputSnapshot*>(snapshot)->getData();
    text.clear();
    for (int i = 0; i < s.size(); ++i) {
        text.addLetter(static_cast<char>(s[i]), letterSize, x,y);
    }

}

unsigned int Typing::getCharSize() {
    text.getCharSize();
}

sf::FloatRect Typing::firstLetterGGB() {
    return text.firstLetterCoor();
}

sf::Vector2f Typing::firstLetterCoor() {
    return text.getFirstPosition();
}

void Typing::setPosition(float x, float y) {
    this->x = x;
    this->y = y;

}

bool Typing::empty() {
    return text.empty();
}



void Typing::setLetterSize(unsigned int letterSize) {
    this->letterSize = letterSize;
}



Letter Typing::back() {
    return text.back();
}

void Typing::setLength(float length) {
    this->maxLength = length;
}

bool Typing::isFull() {
    float typingLength;

    for(auto iter = text.begin(); iter != text.end(); ++iter){
        typingLength += iter->getGlobalBounds().width;
    }

    if(typingLength >= maxLength){
        return true;
    } else
        return false;
}

const MultiText &Typing::getText() const {
    return text;
}

void Typing::keyWordFinder(std::list<Letter>::iterator start, std::list<Letter>::iterator end) {
    std::string s;
    auto copyStart = start;
    auto copyEnd = end;

    for (; start != end ; ++start) {
        s += (start->getLetter());

    }

    if (s == "int" || s == "double" || s == "char" ||s == "float"){
        for (; copyStart != copyEnd ; ++copyStart) {
            (copyStart->setColor(sf::Color::Blue));

        }
    }
}

std::string Typing::getText() {
    return text.getString();
}

MultiText Typing::getMT() {
    return text;
}


