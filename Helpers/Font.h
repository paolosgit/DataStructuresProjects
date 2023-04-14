//
// Created by Paolo Octoman on 3/15/23.
//

#ifndef INC_3_20PROJ_FONT_H
#define INC_3_20PROJ_FONT_H


#include <SFML/Graphics.hpp>

class Font
{
private:
    static sf::Font font;
    static void loadFont();
public:

    static sf::Font& getFont();
};



#endif //INC_3_20PROJ_FONT_H
