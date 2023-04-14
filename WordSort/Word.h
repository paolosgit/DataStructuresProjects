//
// Created by Paolo Octoman on 3/23/23.
//

#ifndef INC_3_20PROJ_WORD_H
#define INC_3_20PROJ_WORD_H
#include <SFML/Graphics.hpp>
#include <string>

class Word : public sf::Text{
private:
    std::string word;
    int priority =0;
public:
    int getPriority() const;

public:
    const std::string &getWord() const;

    void setPriority(int priority);

public:
    Word();

    void setWord(const std::string &word);


    Word(std::string word);
    friend bool operator<(const Word& lhs, const Word& rhs);
    friend bool operator>(const Word& lhs, const Word& rhs);
    friend bool operator<=(const Word& lhs, const Word& rhs);
    friend bool operator>=(const Word& lhs, const Word& rhs);
    friend bool operator==(const Word& lhs, const Word& rhs);
    friend bool operator!=(const Word& lhs, const Word& rhs);

    void operator+=(int plus);



};


#endif //INC_3_20PROJ_WORD_H
