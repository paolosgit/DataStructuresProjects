//
// Created by Paolo Octoman on 3/16/23.
//

#ifndef INC_3_20PROJ_MOUSEEVENTS_CPP
#define INC_3_20PROJ_MOUSEEVENTS_CPP
#include "MouseEvents.h"


template<class T>
bool MouseEvents::mouseClicked(T &object, sf::RenderWindow &window) {
    return hovered(object, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}




// returns true if the mouse clicks anywhere in the window
//THIS IS GONNA NEED A DUMMY OBJECT ARGUMENT
template<class T>
bool MouseEvents::windowClicked(T& object,sf::RenderWindow &window, sf::Event event) {
//    sf::Vector2f m_pos = (sf::Vector2f) sf::Mouse::getPosition(window);
//
//    auto x = window.getSize().x;
//    auto y = window.getSize().y;
//
//    return sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_pos.x <= x && m_pos.y <= y && m_pos.x >= 0 && m_pos.y >= 0;

    return !hovered(object, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}






template<class T>
bool MouseEvents::mouseDoubleClicked() {
    return false;
}

template<class T>
bool MouseEvents::mouseTripleClicked() {
    return false;
}

template<class T>
bool MouseEvents::draggedOver(T &object, sf::RenderWindow &window, sf::Event event) {
    return false;
}

template<class T>
bool MouseEvents::hovered(T &object, sf::RenderWindow &window) {
    sf::Vector2f m_pos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return object.getGlobalBounds().contains(m_pos);
}


#endif //INC_3_20PROJ_MOUSEEVENTS_CPP
