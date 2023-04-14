//
// Created by Paolo Octoman on 3/26/23.
//

#ifndef INC_3_20PROJ_DROPDOWNMENU_H
#define INC_3_20PROJ_DROPDOWNMENU_H
#include "../GUI_Component/GUI_Component.h"
#include "DDM_InputBox.h"
#include "ItemList.h"
#include <iostream>
#include <string>
class DropDownMenu : public GUI_Component{
protected:
    ItemList list;
    DDM_InputBox header;

public:



    DropDownMenu();

    void addItem(const std::string& string);

    void setPosition(float x, float y);
    void setPosition(sf::Vector2f position);

    sf::FloatRect getGlobalBounds() const;

    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

    Snapshot *getSnapshot() override;

    void applySnapshot(Snapshot *snapshot) override;

    void setSize(sf::Vector2f size);

};


#endif //INC_3_20PROJ_DROPDOWNMENU_H
