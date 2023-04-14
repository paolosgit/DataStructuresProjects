//
// Created by Paolo Octoman on 3/17/23.
//

#ifndef INC_3_20PROJ_CURSOR_H
#define INC_3_20PROJ_CURSOR_H
#include <SFML/Graphics.hpp>
#include "Letter.h"
#include "Typing.h"
#include "InputBox.h"

class Cursor : public sf::Drawable{
public:
    Cursor();
    void setCharacterSize(Letter letter);

    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;

public:
    void setRelativePosition(Typing typing, InputBox box);
    void show();
    void hide();



private:
    sf::RectangleShape cursor;

};


#endif //INC_3_20PROJ_CURSOR_H
