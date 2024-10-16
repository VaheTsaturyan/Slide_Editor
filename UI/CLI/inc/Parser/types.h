#pragma once 

#include <string>
#include <variant>
#include <unordered_map>

using word = std::string;
using number = int;
using argument = char; 

enum class eTokenType{
    WORD,
    NUMBER,
    ARGUMENT,
    BADTYPE
}

enum class eState{
    START,
    CMAND,
    ARGUMENT,
    DEAD_STATE
    //CREATE_COMAND
}


struct sToken{
    eTokenType tokenType;
    std::variant<word, number, argument> tokenContent;
};


/*
struct sAftomat{
    std::unordered_map<eState, > aftomatState;
};

*/
