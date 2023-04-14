//
// Created by Paolo Octoman on 3/28/23.
//

#ifndef INC_3_20PROJ_TEXTINPUTSNAPSHOT_H
#define INC_3_20PROJ_TEXTINPUTSNAPSHOT_H


#include "Snapshot.h"
#include <string>

class TextInputSnapshot : public Snapshot{
private:
    std::string data;

public:
    const std::string &getData() const;

    void setData(const std::string &data);
};


#endif //INC_3_20PROJ_TEXTINPUTSNAPSHOT_H
