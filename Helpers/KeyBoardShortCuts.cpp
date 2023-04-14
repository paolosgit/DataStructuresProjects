//
// Created by Paolo Octoman on 3/16/23.
//

#include "KeyBoardShortCuts.h"
#include <iostream>

bool KeyBoardShortCuts::isUndo(sf::RenderWindow &window, sf::Event event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl)){
        return true;
    }
    else
        return false;

}
