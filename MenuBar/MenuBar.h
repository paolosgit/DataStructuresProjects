//
// Created by Paolo Octoman on 4/2/23.
//

#ifndef INC_3_20PROJ_MENUBAR_H
#define INC_3_20PROJ_MENUBAR_H
#include "../GUI_Component/GUI_Component.h"
#include "Menu.h"
#include <vector>
#include <iostream>
#include <string>

class MenuBar : public GUI_Component{
private:
    std::vector<Menu> menus;
public:
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

    Snapshot *getSnapshot() override;

    void applySnapshot(Snapshot *snapshot) override;

public:
    MenuBar();
    void addItem(int menuIndex, std::string itemText);
    void addMenu(std::string headerName);
    void setPosition(sf::Vector2f position);
    void rePosition();
    void setItemSize(sf::Vector2f size);

};


#endif //INC_3_20PROJ_MENUBAR_H
