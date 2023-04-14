//
// Created by Paolo Octoman on 3/26/23.
//

#ifndef INC_3_20PROJ_DDM_INPUTBOX_H
#define INC_3_20PROJ_DDM_INPUTBOX_H
#include <SFML/Graphics.hpp>
#include "Item.h"
#include "../Helpers/States.h"

class DDM_InputBox : public sf::Drawable, public States{
private:
    Item itemHeader;

public:
    DDM_InputBox();
    sf::FloatRect getGlobalBounds() const;
    DDM_InputBox(Item item);
    void setText( Item item);
    void setBoxSize(Item item);
    void setBoxSize(sf::Vector2f size);
    sf::Vector2f getBoxSize();
    void setText( std::string string);
    void setPosition(float x, float y);
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void setColorSettings(sf::Color boxColor, sf::Color textColor);


};


#endif //INC_3_20PROJ_DDM_INPUTBOX_H
