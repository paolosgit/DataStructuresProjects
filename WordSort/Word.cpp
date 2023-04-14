//
// Created by Paolo Octoman on 3/23/23.
//

#include "Word.h"
#include "../Helpers/Font.h"
void Word::setWord(const std::string &word) {
    this->word = word;
    setString(word);
}

Word::Word() {
    setFont(Font::getFont());
    setFillColor(sf::Color::Black);
    setCharacterSize(40);

}

Word::Word(std::string word) : Word(){
    this->word = word;
}

bool operator<(const Word &lhs, const Word &rhs) {
    return lhs.priority < rhs.priority;
}

const std::string &Word::getWord() const {
    return word;
}

bool operator>(const Word &lhs, const Word &rhs) {
    return lhs.priority > rhs.priority;
}

bool operator<=(const Word &lhs, const Word &rhs) {
    return lhs.priority <= rhs.priority;
}

bool operator>=(const Word &lhs, const Word &rhs) {
    return lhs.priority >= rhs.priority;
}

bool operator!=(const Word &lhs, const Word &rhs) {
    return lhs.priority != rhs.priority;
}

bool operator==(const Word &lhs, const Word &rhs) {
    return lhs.priority == rhs.priority;
}

void Word::setPriority(int priority) {
    this->priority = priority;
}

void Word::operator+=(int plus) {
    priority+= plus;
}

int Word::getPriority() const {
    return priority;
}

