//
// Created by Paolo Octoman on 3/19/23.
//

#include "InputBox.h"
#include "../Helpers/MouseEvents.h"

void InputBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(label);
    window.draw(box);
}



InputBox::InputBox() {
    label.setFont(Font::getFont());
    spacer.setString("FKDJ");
    spacer.setPosition(500,500);
    label.setCharacterSize(spacer.getCharacterSize());
    label.setFillColor(sf::Color::Black);
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(5);
    box.setPosition(500,500);
    label.setPosition(box.getPosition().x, box.getPosition().y-spacer.getGlobalBounds().height - 25);


}

void InputBox::setSize( Typing text) {
    if (text.empty()){
        box.setSize({500,spacer.getGlobalBounds().height +20});
    }
    else{
        float height = text.firstLetterGGB().height;
        box.setSize({500, height});
    }

}

void InputBox::setPosition( Typing text) {
    box.setPosition(text.firstLetterCoor().x, text.firstLetterCoor().y);
}

void InputBox::setPosition(float x, float y) {
box.setPosition(x,y);
    label.setPosition(box.getPosition().x, box.getPosition().y-spacer.getGlobalBounds().height - 15);

}

sf::Vector2f InputBox::getPosition() {
    return box.getPosition();
}

void InputBox::setLabel(std::string label) {
this->label.setString(label);
}

void InputBox::setSize(unsigned int letterSize) {
    label.setCharacterSize(letterSize);
    spacer.setCharacterSize(letterSize);
    label.setPosition(box.getPosition().x, box.getPosition().y-spacer.getGlobalBounds().height - 15);
    box.setSize({box.getSize().x, spacer.getGlobalBounds().height +10});
}

void InputBox::setLength(float size) {
    box.setSize({size, box.getSize().y});
}

void InputBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents::mouseClicked(box, window)){
        state.enableState(CLICKED);
        box.setOutlineColor(sf::Color::Blue);
        box.setOutlineThickness(8);
    }
    if (MouseEvents::windowClicked(box,window,event)){
        state.disableState(CLICKED);
        box.setOutlineColor(sf::Color::Black);
        box.setOutlineThickness(5);
    }

}

void InputBox::update() {

}

sf::FloatRect InputBox::getGlobalBounds() const{
    return box.getGlobalBounds();
}

Letter InputBox::getSpacerSize() {
    return spacer;
}


Snapshot *InputBox::getSnapshot() {

}

void InputBox::applySnapshot( Snapshot *snapshot) {

}

