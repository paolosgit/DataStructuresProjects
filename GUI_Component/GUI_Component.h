//
// Created by Paolo Octoman on 3/16/23.
//

#ifndef INC_3_20PROJ_GUI_COMPONENT_H
#define INC_3_20PROJ_GUI_COMPONENT_H
#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "SnapshotInterface.h"
#include "../Helpers/States.h"
#include "Snapshot.h"


class GUI_Component : public EventHandler, public States, public SnapshotInterface, public sf::Drawable
{
public:
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;


    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

    //from SnapshotInterface
    virtual Snapshot* getSnapshot() = 0;
    virtual void applySnapshot( Snapshot* snapshot) = 0;
};


#endif //INC_3_20PROJ_GUI_COMPONENT_H
