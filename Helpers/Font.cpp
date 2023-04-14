//
// Created by Paolo Octoman on 3/15/23.
//

#include "Font.h"
sf::Font Font::font;

void Font::loadFont()
{
    font.loadFromFile("Helpers/OpenSans-Bold.ttf");
}

sf::Font &Font::getFont()
{
    loadFont();
    return font;
}