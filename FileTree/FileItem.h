//
// Created by Paolo Octoman on 4/4/23.
//

#ifndef INC_3_20PROJ_FILEITEM_H
#define INC_3_20PROJ_FILEITEM_H
#include <SFML/Graphics.hpp>
#include "../Helpers/States.h"
#include <string>


class FileItem : public sf::Drawable, public States{
public:
    FileItem();
    FileItem(std::string name);
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void hoverHandler(sf::RenderWindow& window);
    void setItem(statesEnum type);
    void setName(std::string name);
    void setPosition(sf::Vector2f pos);
    void setClickedColor();
    void setNormalColor();
    sf::FloatRect getGlobalBounds() const;
    sf::FloatRect getNameGB()const;
    std::string getName(); //maybe make const?


private:
    sf::Sprite file;
    sf::Sprite folder;
    sf::Text name;

};


#endif //INC_3_20PROJ_FILEITEM_H
