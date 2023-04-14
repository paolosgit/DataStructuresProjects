//
// Created by Paolo Octoman on 4/11/23.
//

#include "FileTree.h"
#include "../Helpers/MouseEvents.h"
FileTree::FileTree() {
    root = new FileNode;
    root->data.setItem(IS_FOLDER);
    root->data.setName("Home");
    root->data.setPosition({100,100});
}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(*root);
}

void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    root->addEventHandler(window,event);





}

void FileTree::update() {

}

Snapshot *FileTree::getSnapshot() {
    return nullptr;
}

void FileTree::applySnapshot(Snapshot *snapshot) {

}



void FileTree::push(std::string filepath, statesEnum type) {
    std::vector<std::string> paths = split(filepath);
    FileNode* p = root;


    for (int i = 0; i < paths.size()-1; ++i) {

        if (p != nullptr){
            for (int j = 0; j < p->children.size(); ++j) {
                if (p->children[j]->data.getName() == paths[i]){
                    p = p->children[j];
                    break;
                }
            }
        }
        else
            break;
    }

    if (p != nullptr){
        p->addChild(type, paths.back());
    } else
        std::cout << "Path not found" << std::endl;


}

FileNode *FileTree::search(std::string s, FileNode *node) {


    std::cout <<"SearchString: "<< s << std::endl;

    for (int i = 0; i < node->children.size(); ++i) {
        if (node->children[i]->data.getName() == s){
            return node->children[i];
        }
    }

//    std::cout << "nully";
    return nullptr;
}

void FileTree::setPosition(sf::Vector2f pos) {
    root->data.setPosition(pos);
}

void FileTree::setRootName(std::string name) {
    root->data.setName(name);
}

std::vector<std::string> FileTree::split(std::string filepath) {
    std::stringstream sstr(filepath);
    std::vector<std::string> v;
    while (sstr.good()){
        std::string subtr;
        getline(sstr, subtr, '/');
        v.push_back(subtr);
    }

    return v;
}

void FileTree::treeClickedHandler() {

}


