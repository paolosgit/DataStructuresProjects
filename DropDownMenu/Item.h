//
// Created by Paolo Octoman on 3/26/23.
//

#ifndef INC_3_20PROJ_ITEM_H
#define INC_3_20PROJ_ITEM_H
#include <SFML/Graphics.hpp>
#include "../Helpers/States.h"


class Item : public sf::Drawable, public States{

private:
    void setUpBox(sf::Vector2f size);
    sf::Color backgroundColor  = sf::Color::Black, hoverColor  = sf::Color::Red;
public:
    sf::RectangleShape box;
    sf::Text text;
    Item();
    Item(std::string text, sf::Vector2f size);
    void oneClick(void (*f)(), sf::RenderWindow &window);
    void eventHandler(sf::RenderWindow& window, const sf::Event& event);
    void update();
    void setBoxSize(sf::Vector2f size);
    sf::Vector2f getBoxSize();
    float getOutlineThiccness();
    void setTextSize(unsigned int size);
    sf::FloatRect getGlobalBounds() const;
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition( );


    void setString(std::string text);
    std::string getString();

    void setPosition(float x, float y);

    void setBorderSizenColor(float size, sf::Color color);
    void setUpText(std::string text);




    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //INC_3_20PROJ_ITEM_H
