//
// Created by Paolo Octoman on 3/28/23.
//

#include "TextInputSnapshot.h"

const std::string &TextInputSnapshot::getData() const {
    return data;
}

void TextInputSnapshot::setData(const std::string &data) {
    TextInputSnapshot::data = data;
}
