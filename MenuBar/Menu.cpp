//
// Created by Paolo Octoman on 4/2/23.
//

#include "Menu.h"
#include "../Helpers/MouseEvents.h"

void Menu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    header.eventHandler(window,event);



    if (MouseEvents::mouseClicked(header, window)){
        header.disableState(CLICKEDOFF);
    }
    if (!header.checkState(CLICKEDOFF)){
        header.setColorSettings(sf::Color::Red, sf::Color::Black);

        list.eventHandler(window,event);
        for (int i =0; i < list.getItems().size(); ++i){
            if (MouseEvents::mouseClicked(list.getItems()[i], window)){
//                header.setText(list.getItems()[i].getString());
            }
        }


        if (MouseEvents::windowClicked(header, window, event)){
            header.enableState(CLICKEDOFF);
            header.setColorSettings(sf::Color::Black, sf::Color::Red);

        }

    }

}

void Menu::setHeaderText(std::string string) {
    header.setText(string);
    header.setColorSettings(sf::Color::Black, sf::Color::Red);

}
