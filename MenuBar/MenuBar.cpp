//
// Created by Paolo Octoman on 4/2/23.
//

#include "MenuBar.h"
#include "../Helpers/Position.h"

MenuBar::MenuBar() {

}

void MenuBar::addItem(int menuIndex, std::string itemText) {
    if (menuIndex < menus.size()){
        menus[menuIndex].addItem(itemText);
    }

}

void MenuBar::addMenu(std::string headerName) {
    Menu menu;
    menu.setHeaderText(headerName);
    menus.push_back(menu);

    if (menus.size() >=2){
        Position::right(menus[menus.size()-2], menus[menus.size()-1]);
        menus.back().setPosition(menus.back().getGlobalBounds().left+20, menus.back().getGlobalBounds().top+20);
    }
}

void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (int i = 0; i < menus.size(); ++i) {
        window.draw(menus[i]);
    }
}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for (int i = 0; i < menus.size(); ++i) {
        menus[i].addEventHandler(window,event);
    }
}

void MenuBar::update() {

}

Snapshot *MenuBar::getSnapshot() {
    return nullptr;
}

void MenuBar::applySnapshot(Snapshot *snapshot) {

}

void MenuBar::setPosition(sf::Vector2f position) {
    if (menus.size() == 1){
        menus[0].setPosition(position.x, position.y);
    }
    else if (menus.size() >=2){
        menus[0].setPosition(position.x, position.y);
        for (int i = 0; i < menus.size()-1; ++i) {
            Position::right(menus[i], menus[i+1]);
            menus[i+1].setPosition(menus[i+1].getGlobalBounds().left+20, menus[i+1].getGlobalBounds().top+20);
        }
    }
}

void MenuBar::rePosition() {
    menus[0].setPosition(menus[0].getGlobalBounds().left, menus[0].getGlobalBounds().top);
    for (int i = 0; i < menus.size()-1; ++i) {
        Position::right(menus[i], menus[i+1]);
        menus[i+1].setPosition(menus[i+1].getGlobalBounds().left+20, menus[i+1].getGlobalBounds().top+20);
    }

}

void MenuBar::setItemSize(sf::Vector2f size) {
    for (int i = 0; i < menus.size(); ++i) {
        menus[i].setSize(size);
    }
    rePosition();
}
