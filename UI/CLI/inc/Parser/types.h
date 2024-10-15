#pragma once 

#include <string>
#include <variant>


using word = std::string;
using number = int;
using argument = char; 


enum class eTokenType{
    WORD,
    NUMBER,
    ARGUMENT,
    BADTYPE
}


struct sToken{
    eTokenType tokenType;
    std::variant<word, number, argument> tokenContent;
};
