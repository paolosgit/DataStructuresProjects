//
// Created by Paolo Octoman on 3/15/23.
//

#include "MultiText.h"
#include "../Helpers/Font.h"
MultiText::MultiText()
{
    font = Font::getFont();
}







//Accessors and draw
 std::string MultiText::getString(){
    std::string textAsString;
    for(iterator iter = begin(); iter != end(); ++iter){
        textAsString.push_back(iter->letter);
    }
    return textAsString;
}

unsigned int MultiText::getSize(){ return letterList.size(); }

MultiText::iterator MultiText::begin() { return letterList.begin(); }
MultiText::const_iterator MultiText::begin() const{ return letterList.cbegin(); }

MultiText::iterator MultiText::end(){ return letterList.end(); }
MultiText::const_iterator MultiText::end() const{ return letterList.cend(); }


void MultiText::draw(sf::RenderTarget &window, sf::RenderStates states) const
{

    for(auto iter = begin(); iter != end(); ++iter){
        window.draw(*iter);
    }
}

void MultiText::addLetter(std::string letter){

    Letter brandNew;


    if (letterList.empty()){
        brandNew.setString(letter);
        brandNew.setPosition(500,500);
    }
    else
    {
        brandNew = letterList.back();
        brandNew.setString(letter);
        brandNew.setPosition(letterList.back().getPosition().x+1,letterList.back().getPosition().y+1);
        letterList.push_back(brandNew);
    }
}

void MultiText::addLetter(char letter, unsigned int letterSize, float x, float y) {
    Letter brandNew;


    if (letterList.empty()){
        brandNew.setFont(font);
        brandNew.setFillColor(color);
        brandNew.setCharacterSize(letterSize);
        brandNew.setString(letter);
        brandNew.setLetter(letter);
        brandNew.setPosition(x,y);
        letterList.push_back(brandNew);
    }
    else
    {
        brandNew = letterList.back();
        brandNew.setString(letter);
        brandNew.setLetter(letter);
        brandNew.setPosition(letterList.back().getPosition().x+letterList.back().getGlobalBounds().width,letterList.back().getPosition().y);
        letterList.push_back(brandNew);
    }
}

void MultiText::backSpace() {
    if (!letterList.empty()){
        letterList.pop_back();
    }
}

void MultiText::setFont(const sf::Font &font) {
    this->font = font;
}

void MultiText::setColor(const sf::Color &color) {
    this->color = color;
}

unsigned int MultiText::getCharSize() {
    return letterList.front().getCharacterSize();
}

sf::FloatRect MultiText::firstLetterCoor() {
    if (letterList.empty()){

    }
    else
    {
        return letterList.front().getGlobalBounds();
    }
}

sf::Vector2f MultiText::getFirstPosition() {
    if (letterList.empty()){

    }
    else
    {
        return letterList.front().getPosition();
    }

}

void MultiText::setPosition(float x, float y) {
    if (letterList.empty()){

    }
    else
    {
        return letterList.front().setPosition(x,y);
    }
}

bool MultiText::empty() {
    return letterList.empty();
}

Letter MultiText::back() {
    return letterList.back();
}



void MultiText::clear() {
    letterList.clear();
}

