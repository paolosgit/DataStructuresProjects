//
// Created by Paolo Octoman on 3/15/23.
//

#include "Letter.h"
#include "../Helpers/Font.h"
Letter::Letter(){
    setCharacterSize(50);
    setFont(Font::getFont());
    setFillColor(sf::Color::Green);

}

Letter::Letter(const sf::Font &font) {
    setFont(font);
}

void Letter::setColor(sf::Color color) {
    setFillColor(color);
}

Letter::Letter(sf::Color color) {
    setFont(Font::getFont());
    setFillColor(color);
}

void Letter::setSize(float size) {
    setCharacterSize(size);

}

char Letter::getLetter() const {
    return letter;
}

void Letter::setLetter(char letter) {
    this->letter = letter;
}





