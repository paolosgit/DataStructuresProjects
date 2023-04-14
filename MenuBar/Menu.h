//
// Created by Paolo Octoman on 4/2/23.
//

#ifndef INC_3_20PROJ_MENU_H
#define INC_3_20PROJ_MENU_H
#include "../DropDownMenu/DropDownMenu.h"
class Menu : public DropDownMenu{


public:
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void setHeaderText(std::string string);
};


#endif //INC_3_20PROJ_MENU_H
