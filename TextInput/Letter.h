//
// Created by Paolo Octoman on 3/15/23.
//

#ifndef INC_3_20PROJ_LETTER_H
#define INC_3_20PROJ_LETTER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
class Letter : public sf::Text{

public:
    char letter;

    void setLetter(char letter);

    char getLetter() const;

    Letter();
    Letter(const sf::Font& font);
    Letter(sf::Color color);
    void setColor(sf::Color color);
    void setSize(float size);

};


#endif //INC_3_20PROJ_LETTER_H
