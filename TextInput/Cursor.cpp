//
// Created by Paolo Octoman on 3/17/23.
//

#include "Cursor.h"
#include "InputBox.h"

Cursor::Cursor() {
    cursor.setFillColor(sf::Color::Transparent);
    cursor.setSize({6, 10});
}

void Cursor::setCharacterSize(Letter letter) {
    cursor.setSize({cursor.getSize().x, letter.getGlobalBounds().height});
}

void Cursor::setRelativePosition(Typing typing, InputBox box) {
    if (typing.getMT().empty()){
        cursor.setPosition(box.getPosition());
    }
    else
        cursor.setPosition(typing.getMT().back().getPosition().x+typing.getMT().back().getGlobalBounds().width + 3,typing.getMT().back().getPosition().y+5);
}

void Cursor::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(cursor);
}

void Cursor::show() {
    cursor.setFillColor(sf::Color::Black);
}

void Cursor::hide() {
    cursor.setFillColor(sf::Color::Transparent);
}



