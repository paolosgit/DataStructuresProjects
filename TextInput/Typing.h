//
// Created by Paolo Octoman on 3/15/23.
//

#ifndef INC_3_20PROJ_TYPING_H
#define INC_3_20PROJ_TYPING_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "MultiText.h"
#include "../GUI_Component/EventHandler.h"
#include "../GUI_Component/GUI_Component.h"
#include <list>

#include "../GUI_Component/TextInputSnapshot.h"
#include "../GUI_Component/History.h"

class Typing :public GUI_Component{
private:
    MultiText text;
    unsigned int letterSize = 50;
    float x = 500;
    float y = 500;
    float maxLength = 500;

public:
    void setLetterSize(unsigned int letterSize);
    void setPosition(float x, float y);
    bool isFull();
    void setLength(float length);
    States state;

    const MultiText &getText() const;

public:
    Typing();

    unsigned int getCharSize();
    sf::FloatRect firstLetterGGB();

    sf::Vector2f firstLetterCoor();

    std::string getText();

    MultiText getMT();



    Letter back();
    bool empty();

    Snapshot *getSnapshot() override;

    void applySnapshot( Snapshot *snapshot) override;

    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;


    bool is_number(const std::string& s)
    {
        return !s.empty() && std::find_if(s.begin(),
                                          s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
    }

    void keyWordFinder(std::list<Letter>::iterator start, std::list<Letter>::iterator end);
    void update()override;
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const override;


};


#endif //INC_3_20PROJ_TYPING_H

//
//class Typing :public GUI_Component{
//private:
//    MultiText text;
//    unsigned int letterSize = 50;
//    float x = 500;
//    float y = 500;
//    float maxLength = 500;
//
//public:
//    void setLetterSize(unsigned int letterSize);
//    void setPosition(float x, float y);
//    bool isFull();
//    void setLength(float length);
//    States state;
//
//    const MultiText &getText() const;
//
//public:
//    Typing();
//
//    unsigned int getCharSize();
//    sf::FloatRect firstLetterGGB();
//
//    sf::Vector2f firstLetterCoor();
//
//    std::string getText();
//
//    MultiText getMT();
//
//
//
//    Letter back();
//    bool empty();
//
//    Snapshot *getSnapshot() override;
//
//    void applySnapshot( Snapshot *snapshot) override;
//
//    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
//
//
//    bool is_number(const std::string& s)
//    {
//        return !s.empty() && std::find_if(s.begin(),
//                                          s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
//    }
////    void addEventHandler(sf::RenderWindow& window, sf::Event event, InputBox box);
//
//    void keyWordFinder(std::list<Letter>::iterator start, std::list<Letter>::iterator end);
//    void update()override;
//    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
//
//
//};
