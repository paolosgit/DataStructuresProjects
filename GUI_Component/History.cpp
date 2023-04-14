//
// Created by Paolo Octoman on 3/17/23.
//

#include "History.h"
#include <iostream>

 std::stack<HistoryNode> History::stack;


void History::pushHistory(const HistoryNode &snapshot) {
    stack.push(snapshot);

}

Snapshot* History::topHistory() {
    return stack.top().snapshot;
}

void History::popHistory() {
    if (!stack.empty()){
        top().component->applySnapshot(top().snapshot);
        delete top().snapshot;
        stack.pop();
    }
}

bool History::empty() {
    return stack.empty();
}

void History::push(GUI_Component *component, Snapshot *snapshot) {
    HistoryNode * n = new HistoryNode;
    n->component = component;
    n->snapshot = snapshot;
    stack.push(*n);
}

void History::apply() {
    stack.top().component ->applySnapshot(stack.top().snapshot);
}

HistoryNode &History::top() {
    return stack.top();
}

void History::eventHandler(sf::RenderWindow &, sf::Event event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        popHistory();
    }
}

