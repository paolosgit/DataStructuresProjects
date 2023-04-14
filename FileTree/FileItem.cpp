//
// Created by Paolo Octoman on 4/4/23.
//

#include "FileItem.h"
#include "../Helpers/Texture.h"
#include "../Helpers/Font.h"
#include "../Helpers/Position.h"
#include "../Helpers/MouseEvents.h"

FileItem::FileItem() {
    file.setTexture(Texture::getFileTexture());
    folder.setTexture(Texture::getFolderTexture());
    name.setFont(Font::getFont());
    name.setFillColor(sf::Color::Black);


    file.setPosition(500,500);
    folder.setPosition(500,500);
    file.setScale(0.6,0.6);
    folder.setScale(2,2);

}


void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (checkState(IS_FILE)){
        window.draw(file);
    }

    if (checkState(IS_FOLDER)){
        window.draw(folder);
    }

    window.draw(name);
}

void FileItem::setItem(statesEnum type) {
    if (type == IS_FOLDER){
        enableState(IS_FOLDER);
        disableState(IS_FILE);
    }
    else if (type == IS_FILE){
        enableState(IS_FILE);
        disableState(IS_FOLDER);
    }
}

void FileItem::setName(std::string name) {
    this->name.setString(name);
    Position::right(file, this->name);
    if (checkState(IS_FILE)){
        Position::right(file, this->name);
    }
    if (checkState(IS_FOLDER)){
        Position::right(folder, this->name);
    }
}

void FileItem::setPosition(sf::Vector2f pos) {
    file.setPosition(pos);
    folder.setPosition(pos);


    if (checkState(IS_FILE)){
        Position::right(file, this->name);
    }
    if (checkState(IS_FOLDER)){
        Position::right(folder, this->name);
    }
}

sf::FloatRect FileItem::getGlobalBounds() const {
    if (checkState(IS_FILE)){
        return file.getGlobalBounds();
    }
    if (checkState(IS_FOLDER)){
        return folder.getGlobalBounds();
    }
}

FileItem::FileItem(std::string name) : FileItem(){
    setName(name);
}

std::string FileItem::getName() {
    return name.getString();
}

void FileItem::hoverHandler(sf::RenderWindow &window) {
    if (checkState(IS_FILE)){
        if (MouseEvents::hovered(file, window)){
            file.setColor({0,255,255});
            name.setFillColor({0,255,255});
        }
        else
        {
            file.setColor(sf::Color::White);
            name.setFillColor(sf::Color::Black);
        }
    }
    if (checkState(IS_FOLDER)){
        if (MouseEvents::hovered(folder, window)){
            folder.setColor({0,255,255});
            name.setFillColor({0,255,255});
        }
        else
        {
            folder.setColor(sf::Color::White);
            name.setFillColor(sf::Color::Black);
        }
    }
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    hoverHandler(window);
    if (checkState(CLICKED)){
        setClickedColor();
    }
}

void FileItem::setNormalColor() {
    folder.setColor(sf::Color::White);
    name.setFillColor(sf::Color::Black);
}

sf::FloatRect FileItem::getNameGB() const {
    return name.getGlobalBounds();
}

void FileItem::setClickedColor() {
    folder.setColor({0,255,255});
    name.setFillColor({0,255,255});
}




