#pragma once 

#include <string>
#include <variant>
#include <unordered_map>

using word = std::string;
using number = int;
//using argument = std::string; 

enum class eTokenType{
    WORD,
    OPTION_NUMBER,
    OPTION_WORD,
    ARGUMENT,
    BADTYPE
};

enum class eTokenOrder{
    VALID,
    //INVALID,
    NULL_TOKEN
};

enum class eState{
    START,
    CMAND,
    ARGUMENT,
    OPTION_WORD,
    OPTION_NUMBER,
    DEAD_STATE
};


struct sToken{
    eTokenType tokenType;
    std::variant<number, word> tokenContent;
};






