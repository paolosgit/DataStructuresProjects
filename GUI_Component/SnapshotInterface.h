//
// Created by Paolo Octoman on 3/16/23.
//

#ifndef INC_3_20PROJ_SNAPSHOTINTERFACE_H
#define INC_3_20PROJ_SNAPSHOTINTERFACE_H

#include "Snapshot.h"

class SnapshotInterface
{
    // this function will return a snapshot of the object's current state
    virtual Snapshot* getSnapshot() = 0;

    // this function will apply a snapshot to the object.
    //This will revert the object back to the state that has been recorded in the snapshot
    virtual void applySnapshot( Snapshot* snapshot) = 0;


    // Virtual destructor to allow proper cleanup of derived classes
    //virtual ~SnapshotInterface() {}
};


#endif //INC_3_20PROJ_SNAPSHOTINTERFACE_H
