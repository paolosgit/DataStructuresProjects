//
// Created by Paolo Octoman on 3/15/23.
//

#ifndef INC_3_20PROJ_TEXTINPUT_H
#define INC_3_20PROJ_TEXTINPUT_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../GUI_Component/History.h"
#include "../GUI_Component/GUI_Component.h"
#include "MultiText.h"
#include "Typing.h"
#include "../GUI_Component/History.h"
#include "InputBox.h"
#include "Cursor.h"

class TextInput : public GUI_Component{
public:

    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

    bool isClicked();

    Snapshot *getSnapshot() override;

    void applySnapshot( Snapshot *snapshot) override;

    void setCharacterSize(unsigned int size);
    void setLength(float length);
    void setLabel(std::string label);

    void setPosition(float x, float y);

    TextInput(unsigned int size, float length, std::string label, float x, float y);

    TextInput();
    TextInput(const TextInput& ti);

    sf::FloatRect getGlobalBounds() const;

    void getTime(sf::Time time);

    std::string getText();
private:

    Typing text;
    InputBox box;
    Cursor cursor;

    sf::Time time;
};


#endif //INC_3_20PROJ_TEXTINPUT_H



//class TextInput : public GUI_Component{
//public:
//
//    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
//
//    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
//
//    void update() override;
//
//    Snapshot *getSnapshot() override;
//
//    void applySnapshot( Snapshot *snapshot) override;
//
//    void setCharacterSize(unsigned int size);
//    void setLength(float length);
//    void setLabel(std::string label);
//
//    void setPosition(float x, float y);
//
//    TextInput(unsigned int size, float length, std::string label, float x, float y);
//
//    TextInput();
//    TextInput(const TextInput& ti);
//
//    sf::FloatRect getGlobalBounds() const;
//
//    void getTime(sf::Time time);
//
//    std::string getText();
//private:
//
//    Typing text;
//    InputBox box;
//    Cursor cursor;
//
//    sf::Time time;
//};