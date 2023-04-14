#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextInput/TextInput.h"
#include "WordSort/WordSort.h"
#include "DropDownMenu/DropDownMenu.h"
#include "MenuBar/MenuBar.h"
#include "FileTree/FileTree.h"

int main() {

    sf::RenderWindow window({1300, 1300, 32}, "CS 8");
    window.setKeyRepeatEnabled(false);

    sf::Clock clock;


    TextInput ti;
    ti.setCharacterSize(40);
    ti.setLength(600);
    ti.setPosition(300,700);

    WordSort ws;



    FileTree fileTree;

    fileTree.push("Home/Folder", IS_FOLDER);
    fileTree.push("Home/Folder/Dave", IS_FILE);
    fileTree.push("Home/Folder/Paolo", IS_FOLDER);
    fileTree.push("Home/Folder/Paolo/Mom", IS_FILE);
    fileTree.push("Home/Folder/Paolo/Dad", IS_FILE);
    fileTree.push("Home/file1", IS_FILE);
    fileTree.push("Home/Burger", IS_FOLDER);
    fileTree.push("Home/file2", IS_FILE);
    fileTree.push("Home/Burger/beef", IS_FILE);
    fileTree.push("Home/Burger/lettuce", IS_FILE);
    fileTree.push("Home/Burger/bun", IS_FILE);
    fileTree.push("Home/Burger/Tomato", IS_FILE);







    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (sf::Event::Closed == event.type){
                window.close();
            }
            ti.addEventHandler(window, event);
            fileTree.addEventHandler(window,event);
        }

        ti.getTime(clock.getElapsedTime());

        ti.update();

        ws.update();

        if((event.type == sf::Event::TextEntered || event.type == sf::Event::KeyPressed) && ti.isClicked()){
            ws.prioritize(ti.getText(), ti);
        }



        window.clear(sf::Color::White);

        window.draw(ti);
        window.draw(ws);
        window.draw(fileTree);
        window.display();



        if (clock.getElapsedTime().asSeconds() >= 1){
            clock.restart();
        }
    }







    return 0;

}





//    DropDownMenu ddm;
//    ddm.addItem("Spiderman");
//    ddm.addItem("Miles Morales");
//    ddm.addItem("Spider Gwen");
//    ddm.addItem("Spiderman Noir");
//
//    ddm.setPosition(700,700);
//    ddm.setSize({400, 100});

//    WordSort ws;

//    Menu menu;
//    menu.addItem("Spiderman");
//    menu.addItem("Miles Morales");
//    menu.addItem("Spider Gwen");
//    menu.addItem("Spiderman Noir");
//
//    menu.setHeaderText("Jaime Foxx");
//
//    menu.setPosition(700,700);
//    menu.setSize({400, 100});

//    MenuBar menuBar;
//    menuBar.addMenu("Spiderman");
//    menuBar.addItem(0, "Doc Ock");
//    menuBar.addItem(0, "Goblin");
//    menuBar.addItem(0, "Tombstone");
//
//    menuBar.addMenu("Batman");
//    menuBar.addItem(1, "Joker");
//    menuBar.addItem(1, "Bane");
//    menuBar.addItem(1, "Two Face");
//
//    menuBar.addMenu("Ash Ketchum");
//    menuBar.addItem(2, "Pikachu");
//    menuBar.addItem(2, "Brock");
//    menuBar.addItem(2, "That one ginger");
//
//
//    menuBar.setItemSize({400,100});
//
//    menuBar.setPosition({200, 700});




//        ti.addEventHandler(window, event);
//        ddm.addEventHandler(window,event);
//        History::eventHandler(window,event);
//        menu.addEventHandler(window,event);
//            menuBar.addEventHandler(window,event);


//        ti.getTime(clock.getElapsedTime());

//        ti.update();
//        ws.update();


//        if((event.type == sf::Event::TextEntered || event.type == sf::Event::KeyPressed) && ti.isClicked()){
////            ws.prioritize(ti.getText(), ti);
//        }


//        window.draw(ti);
//        window.draw(ddm);
//        window.draw(ws);
//        window.draw(menu);
//        window.draw(menuBar);