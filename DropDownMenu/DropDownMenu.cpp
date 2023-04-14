//
// Created by Paolo Octoman on 3/26/23.
//

#include "DropDownMenu.h"
#include "../Helpers/Position.h"
#include "../Helpers/MouseEvents.h"

void DropDownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(header);
    if (!header.checkState(CLICKEDOFF)){
        window.draw(list);
    }
}

void DropDownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    header.eventHandler(window,event);
    if (MouseEvents::mouseClicked(header, window)){
        header.disableState(CLICKEDOFF);
    }
    if (!header.checkState(CLICKEDOFF)){
        list.eventHandler(window,event);
        for (int i =0; i < list.getItems().size(); ++i){
            if (MouseEvents::mouseClicked(list.getItems()[i], window)){
                header.setText(list.getItems()[i].getString());
            }
        }


        if (MouseEvents::windowClicked(header, window, event)){
            header.enableState(CLICKEDOFF);
        }
    }


}

void DropDownMenu::update() {

}

Snapshot *DropDownMenu::getSnapshot() {
    return nullptr;
}

void DropDownMenu::applySnapshot(Snapshot *snapshot) {

}

DropDownMenu::DropDownMenu() {
    header.setText("Select");
    header.enableState(CLICKEDOFF);
    header.setColorSettings(sf::Color::Black, sf::Color::Red);

}

void DropDownMenu::addItem(const std::string& string) {
    if (list.empty()){
        list.addItem(string);
        header.setBoxSize(list.getFirst());
    }
    else
    list.addItem(string);

    Position::bottom(header,list.getItems()[0]);
    list.setPosition({list.getPosition().x+10, list.getPosition().y});
    list.position();
}

void DropDownMenu::setPosition(float x, float y) {
    header.setPosition(x,y);
    list.setPosition({x,y + header.getBoxSize().y});

}

void DropDownMenu::setPosition(sf::Vector2f position) {
    header.setPosition(position.x, position.y);
    list.setPosition({position.x,position.y + header.getBoxSize().y+10});

}

void DropDownMenu::setSize(sf::Vector2f size) {
    header.setBoxSize(size);
    for (int i = 0; i < list.getItems().size(); ++i) {
        list.getItems()[i].setBoxSize(size);
    }
    list.position();
    header.setPosition(list.getItems()[0].getGlobalBounds().left,list.getItems()[0].getGlobalBounds().top);
}

sf::FloatRect DropDownMenu::getGlobalBounds() const{
    return header.getGlobalBounds();
}


