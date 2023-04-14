//
// Created by Paolo Octoman on 4/8/23.
//

#ifndef INC_3_20PROJ_TEXTURE_H
#define INC_3_20PROJ_TEXTURE_H
#include <SFML/Graphics.hpp>


class Texture {
private:
    static sf::Texture fileTexture;
    static sf::Texture folderTexture;
    static void loadFileTexture();
    static void loadFolderTexture();

public:

    static sf::Texture& getFileTexture();
    static sf::Texture& getFolderTexture();

};


#endif //INC_3_20PROJ_TEXTURE_H
