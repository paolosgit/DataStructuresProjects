//
// Created by Paolo Octoman on 4/8/23.
//

#include "Texture.h"

sf::Texture Texture::fileTexture;
sf::Texture Texture::folderTexture;


void Texture::loadFileTexture() {
    fileTexture.loadFromFile("Helpers/file.png");
}

sf::Texture &Texture::getFileTexture() {
    loadFileTexture();
    return fileTexture;
}

void Texture::loadFolderTexture() {
    folderTexture.loadFromFile("Helpers/icons8-pink-cute-folder-48.png");
}

sf::Texture &Texture::getFolderTexture() {
    loadFolderTexture();
    return folderTexture;
}
