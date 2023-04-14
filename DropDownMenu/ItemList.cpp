//
// Created by Paolo Octoman on 11/29/22.
//

#include "ItemList.h"
#include "../Helpers/Position.h"

void ItemList::addItem(const Item &item) {
    items.push_back(item);
    position();
}

void ItemList::addItem(const std::string text, void (*f)()) {
    items.emplace_back(text, sf::Vector2f(300.f, 50.f));
    position();
}

void ItemList::setPosition(const sf::Vector2f &position) {
    if (!items.empty()){
        items[0].setPosition(position);
        this->position();
    }

}

void ItemList::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!checkState(HIDDEN)) {
        for (const Item &l: items) {
            target.draw(l);
        }
    }
}

void ItemList::eventHandler(sf::RenderWindow &window, sf::Event event) {
    for (Item& l : items) {
        l.eventHandler(window, event);
    }
}

void ItemList::update() {

}

void ItemList::position() {
    for (int i = 1; i < items.size(); ++i) {
        Position::bottom(items[i-1] , items[i]);
    }
}

ItemList::ItemList() {

}

sf::FloatRect ItemList::getGlobalBounds() {
    sf::FloatRect f  = items[0].getGlobalBounds();
    f.height *= items.size();
    return f;
}

std::vector<Item> &ItemList::getItems() {
    return items;
}

bool ItemList::empty() {
    return items.empty();
}

Item ItemList::getFirst() {
    return items[0];
}

sf::Vector2f ItemList::getPosition() {
    if (!items.empty()){
        return items[0].getPosition();
    }
}
