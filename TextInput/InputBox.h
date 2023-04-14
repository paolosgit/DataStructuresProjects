//
// Created by Paolo Octoman on 3/19/23.
//

#ifndef INC_3_20PROJ_INPUTBOX_H
#define INC_3_20PROJ_INPUTBOX_H


#include "Typing.h"
#include <iostream>

class InputBox : public GUI_Component{


    public:
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;



    InputBox();

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

    void setSize(unsigned int letterSize);

    void setPosition(float x, float y);
    void setLength(float size);
    void setSize( Typing text);
    void setPosition( Typing text);
    sf::Vector2f getPosition();
    void setLabel(std::string label);

    Letter getSpacerSize();

    sf::FloatRect getGlobalBounds() const;

    Snapshot *getSnapshot() override;

    void applySnapshot( Snapshot *snapshot) override;

    States state;

private:
    sf::RectangleShape box;
    sf::Text label;
    Letter spacer;
};


#endif //INC_3_20PROJ_INPUTBOX_H
