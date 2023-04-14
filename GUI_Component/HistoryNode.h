//
// Created by Paolo Octoman on 3/17/23.
//

#ifndef INC_3_20PROJ_HISTORYNODE_H
#define INC_3_20PROJ_HISTORYNODE_H
#include "Snapshot.h"
#include "GUI_Component.h"
struct HistoryNode{
    Snapshot* snapshot;
    GUI_Component* component;
};
#endif //INC_3_20PROJ_HISTORYNODE_H
