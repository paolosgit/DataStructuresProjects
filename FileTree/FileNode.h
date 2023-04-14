//
// Created by Paolo Octoman on 4/10/23.
//

#ifndef INC_3_20PROJ_FILENODE_H
#define INC_3_20PROJ_FILENODE_H
#include "FileItem.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "../GUI_Component/GUI_Component.h"
class FileNode : public GUI_Component{
private:



public:
    FileItem data;
    std::vector<FileNode*> children;

    int clicks = 0;


    //GUI COMP STUFF
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    Snapshot *getSnapshot() override;
    void applySnapshot(Snapshot *snapshot) override;


    void addChild(statesEnum type, std::string name);
    void position();


};


#endif //INC_3_20PROJ_FILENODE_H
