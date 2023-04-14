//
// Created by Paolo Octoman on 4/10/23.
//

#include "FileNode.h"
#include "../Helpers/MouseEvents.h"
#include "../Helpers/Position.h"
#include <iostream>

void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(data);
    if (data.checkState(IS_FOLDER)){
        if (data.checkState(CLICKED)){
            for (int i = 0; i < children.size(); ++i) {
                window.draw(*children[i]);
            }
        }
    }
}

void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    data.addEventHandler(window,event);
    if (data.checkState(IS_FOLDER)){
        if (MouseEvents::mouseClicked(data, window)){
            data.enableState(CLICKED);
            position();




        }
        if (data.checkState(CLICKED)){
            for (int i = 0; i < children.size(); ++i) {
                children[i]->addEventHandler(window,event);
            }
        }


        if (MouseEvents::mouseClicked(data, window)){
            ++clicks;
            if (clicks >0 && clicks % 2 ==0){
                data.disableState(CLICKED);
                data.setNormalColor();
                for (int i = 0; i < children.size(); ++i) {
                    children[i]->data.disableState(CLICKED);
                }
            }
        }
    }




}

void FileNode::update() {

}

Snapshot *FileNode::getSnapshot() {
    return nullptr;
}

void FileNode::applySnapshot(Snapshot *snapshot) {

}

void FileNode::addChild(statesEnum type, std::string name) {

    FileNode* child = new FileNode;
    child->data.setItem(type);
    child->data.setName(name);
    children.push_back(child);

}

void FileNode::position() {
    if (!children.empty()){
        children[0]->data.setPosition({data.getNameGB().left + data.getNameGB().width + 20, data.getNameGB().top - 30});
        for (int i = 0; i < children.size()-1; ++i) {
            Position::bottom(children[i]->data, children[i+1]->data);
        }
    }
}
