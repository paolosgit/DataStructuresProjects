//
// Created by Paolo Octoman on 3/26/23.
//

#include "DDM_InputBox.h"
#include "../Helpers/Position.h"

DDM_InputBox::DDM_InputBox() {
    itemHeader.setString("boyo");
    itemHeader.setPosition(200,200);
    itemHeader.setBoxSize({300,50});
    itemHeader.setBorderSizenColor(10, sf::Color::Red);

}

void DDM_InputBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(itemHeader);
}

void DDM_InputBox::eventHandler(sf::RenderWindow &window, sf::Event event) {
    itemHeader.eventHandler(window,event);
}

void DDM_InputBox::setText( Item item) {
    itemHeader.setUpText(item.getString());
}

DDM_InputBox::DDM_InputBox(Item item) {
    itemHeader.setBoxSize(item.getBoxSize());
}

void DDM_InputBox::setText(std::string string) {
    itemHeader.setUpText(string);
}

void DDM_InputBox::setPosition(float x, float y) {
//    itemHeader.setPosition(x,y - (itemHeader.getGlobalBounds().height - itemHeader.getOutlineThiccness()) );
    itemHeader.setPosition(x,y );

}

void DDM_InputBox::setBoxSize(Item item) {
    itemHeader.setBoxSize(item.getBoxSize());
}

void DDM_InputBox::setBoxSize(sf::Vector2f size) {
    itemHeader.setBoxSize(size);
}


sf::FloatRect DDM_InputBox::getGlobalBounds() const{
    return itemHeader.getGlobalBounds();
}

void DDM_InputBox::setColorSettings(sf::Color boxColor, sf::Color textColor) {
    itemHeader.box.setFillColor(boxColor);
    itemHeader.text.setFillColor(textColor);
}

sf::Vector2f DDM_InputBox::getBoxSize() {
    return itemHeader.getBoxSize();
}

