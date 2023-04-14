//
// Created by Paolo Octoman on 4/11/23.
//

#ifndef INC_3_20PROJ_FILETREE_H
#define INC_3_20PROJ_FILETREE_H
#include "../GUI_Component/GUI_Component.h"
#include "FileNode.h"
#include <string>
#include <sstream>
#include <iostream>
class FileTree : public GUI_Component{
public:
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    Snapshot *getSnapshot() override;
    void applySnapshot(Snapshot *snapshot) override;

    FileTree();
    void setPosition(sf::Vector2f pos);
    void setRootName(std::string name);
    void push(std::string filepath, statesEnum type);
    void treeClickedHandler();


private:
    FileNode* root = nullptr;
    std::vector<std::string> split(std::string filepath);
    FileNode* search(std::string s, FileNode* node);

};


#endif //INC_3_20PROJ_FILETREE_H
