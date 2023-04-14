//
// Created by Paolo Octoman on 11/29/22.
//

#include "Item.h"
#include "../Helpers/Position.h"
#include "../Helpers/Font.h"
#include "../Helpers/MouseEvents.h"


void Item::setUpText(std::string text) {
    this->text.setFont(Font::getFont());
    this->text.setString(text);
    this->text.setFillColor(sf::Color::Blue);
    Position::centerText(box, this->text);

}

void Item::setUpBox(sf::Vector2f size) {
    setBoxSize(size);

}

Item::Item() : Item("", {0.f, 0.f}) {

}

Item::Item(std::string text, sf::Vector2f size) {
    setUpText(text);
    setUpBox(size);
}

void Item::oneClick(void (*f)(), sf::RenderWindow &window) {
    if(MouseEvents::mouseClicked(box, window)) {
        f();
    }
}

void Item::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    if(MouseEvents::hovered(box,window)){
        box.setFillColor(hoverColor);
        text.setFillColor(backgroundColor);
    }
    else
    {
        box.setFillColor(backgroundColor);
        text.setFillColor(hoverColor);

    }
}

void Item::update() {

}

void Item::setBoxSize(sf::Vector2f size) {
    box.setSize(size);
    Position::centerText(box, this->text);

}

void Item::setTextSize(unsigned int size) {
    text.setCharacterSize(size);
    Position::centerText(box,this->text);
}

void Item::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (!checkState(HIDDEN)) {
        target.draw(box);
        target.draw(text);
    }
}

sf::FloatRect Item::getGlobalBounds() const {
    return box.getGlobalBounds();
}

void Item::setPosition(sf::Vector2f position) {
    box.setPosition(position);
    Position::centerText(box, text);
}

void Item::setString(std::string text) {
    this->text.setString(text);

}

void Item::setPosition(float x, float y ) {
    setPosition({x,y});
}

std::string Item::getString() {
    return text.getString();
}

void Item::setBorderSizenColor(float size, sf::Color color) {
    box.setOutlineThickness(size);
    box.setOutlineColor(color);
}

sf::Vector2f Item::getBoxSize() {
    return box.getSize();
}

float Item::getOutlineThiccness() {
    return box.getOutlineThickness();
}

sf::Vector2f Item::getPosition() {
    return box.getPosition();
}
