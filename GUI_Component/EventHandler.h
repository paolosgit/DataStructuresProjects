//
// Created by Paolo Octoman on 3/15/23.
//

#ifndef INC_3_20PROJ_EVENTHANDLER_H
#define INC_3_20PROJ_EVENTHANDLER_H

#include <SFML/Graphics.hpp>


class EventHandler{
public:
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;


};


#endif //INC_3_20PROJ_EVENTHANDLER_H
