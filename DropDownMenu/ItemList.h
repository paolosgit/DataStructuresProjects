//
// Created by Paolo Octoman on 3/26/23.
//

#ifndef INC_3_20PROJ_ITEMItemList_H
#define INC_3_20PROJ_ITEMItemList_H

#include "Item.h"
#include <vector>
#include <string>
#include "../Helpers/States.h"
class ItemList : public sf::Drawable, public States{
private:
    std::vector<Item> items;



public:
    ItemList();
    void position();

    bool empty();
    void addItem(const Item& item);
    void addItem(const std::string text, void (*f)() = nullptr);
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition( );

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    sf::FloatRect getGlobalBounds();
    std::vector<Item>&  getItems();
    Item getFirst();



};

#endif //INC_3_20PROJ_ITEMItemList_H
