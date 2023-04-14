//
// Created by Paolo Octoman on 3/17/23.
//

#ifndef INC_3_20PROJ_HISTORY_H
#define INC_3_20PROJ_HISTORY_H
#include <stack>
#include "GUI_Component.h"
#include "Snapshot.h"
#include <SFML/Graphics.hpp>
struct HistoryNode{
GUI_Component* component;
Snapshot* snapshot;
};


class History {
private:
    static std::stack<HistoryNode> stack;
    static void apply();
public:
    static HistoryNode& top();
    static void pushHistory(const HistoryNode& snapshot);
    static void push(GUI_Component* component, Snapshot* snapshot);
    static Snapshot* topHistory();
    static void popHistory();
    static bool empty();
    static void eventHandler(sf::RenderWindow&, sf::Event event);

};


#endif //INC_3_20PROJ_HISTORY_H

//class History {
//private:
//    static std::stack<HistoryNode> stack;
//    static void apply();
//public:
//    static void pushHistory(const HistoryNode& snapshot);
//    static void push(GUI_Component* component, Snapshot* snapshot);
//    static Snapshot* topHistory();
//    static void popHistory();
//    static bool empty();
//
//
//};