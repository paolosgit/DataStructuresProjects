//
// Created by Paolo Octoman on 3/16/23.
//

#ifndef INC_3_20PROJ_MOUSEEVENTS_H
#define INC_3_20PROJ_MOUSEEVENTS_H
#include <SFML/Graphics.hpp>
class MouseEvents {

public:
    // returns true if the mouse clicks on the object
    template <class T>
    static bool mouseClicked(T& object, sf::RenderWindow& window);


    // returns true if the mouse clicks anywhere in the window
    template <class T>
    static bool windowClicked(T& object, sf::RenderWindow& window, sf::Event event);


    template <class T>
    // returns true if the mouse has been double clicked
    static bool mouseDoubleClicked();

    template <class T>
    //returns true if the mouse has been triple clicked
    static bool mouseTripleClicked();

    template <class T>
    // returns if the object has been clicked and the mouse has dragged over the object
    static bool draggedOver(T& object, sf::RenderWindow& window, sf::Event event);

    template <class T>
    // returns tru if the mouse is hovered over the object
    static bool hovered(T& object, sf::RenderWindow& window);

private:
    // this is what I used to determine if a double click or triple click occurred
    // you don't have to use this if you don't want to



    //TODO maybe do this later
//    static sf::Clock clock;
//    static int clicks;
//    static void countClicks(sf::Event event);
};




#include "MouseEvents.cpp"
#endif //INC_3_20PROJ_MOUSEEVENTS_H
