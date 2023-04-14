//
// Created by Paolo Octoman on 3/15/23.
//

#ifndef INC_3_20PROJ_MULTITEXT_H
#define INC_3_20PROJ_MULTITEXT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Letter.h"
#include "../Helpers/Font.h"
#include <string>

class MultiText : public sf::Drawable{
private:
    sf::Font font;
    sf::Color color = sf::Color::Black;



public:
    std::list<Letter> letterList;

    typedef std::list<Letter>::iterator iterator;
    typedef std::list<Letter>::const_iterator const_iterator;

    MultiText();

    void setFont(const sf::Font& font);
    void setColor(const sf::Color &color);
    void clear();


    void addLetter(char letter, unsigned int letterSize, float x, float y);
    void addLetter(std::string letter);

    void backSpace();

    unsigned int getCharSize();
    Letter back();

    sf::FloatRect firstLetterCoor();
    bool empty();

    sf::Vector2f getFirstPosition();
    void setPosition(float x, float y);
     std::string getString();
    unsigned int getSize();
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};



#endif //INC_3_20PROJ_MULTITEXT_H
