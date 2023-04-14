//
// Created by Paolo Octoman on 3/26/23.
//

#ifndef INC_3_20PROJ_POSITION_H
#define INC_3_20PROJ_POSITION_H


#include <SFML/Graphics.hpp>
#include <cmath>


class Position {
public:
    template<class T, class S>
    static void left(const T& obj1, S& obj2, float spacing = 0);

    template<class T, class S>
    static void right(const T& obj1, S& obj2, float spacing = 0);

    template<class T, class S>
    static void center(const T& obj1, S& obj2, float spacing = 0);

    template<class T, class S>
    static void bottom(const T& obj1, S& obj2, float spacing = 0);


    template<class T>
    static void centerText(const T &obj, sf::Text &text);


};

#include "Position.cpp"

#endif//INC_3_20PROJ_POSITION_H
