//
// Created by Paolo Octoman on 3/15/23.
//

#include "States.h"


States::States() {
    load();
}

void States::load()
{
    for (int i = 0; i < LAST_STATE; i++) {
        states[static_cast<statesEnum>(i)] = false;
    }
}

bool States::checkState(statesEnum state) const
{
    return states.at(state);
}

void States::enableState(statesEnum state)
{
    setState(state, true);
}

void States::disableState(statesEnum state)
{
    setState(state, false);
}

void States::setState(statesEnum state, bool value)
{
    states.at(state) = value;
}

void States::toggleState(statesEnum state)
{
    setState(state, !states.at(state));
}
