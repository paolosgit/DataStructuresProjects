//
// Created by Paolo Octoman on 3/15/23.
//

#ifndef INC_3_20PROJ_STATES_H
#define INC_3_20PROJ_STATES_H
#include <map>
#include "statesEnum.h"
class States
{
private:
    std::map<statesEnum, bool> states;
    void load();

public:
    States();
    bool checkState(statesEnum state) const;
    void enableState(statesEnum state);
    void disableState(statesEnum state);
    void setState(statesEnum state, bool value);
    void toggleState(statesEnum state);

};


#endif //INC_3_20PROJ_STATES_H
