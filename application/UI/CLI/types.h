#pragma once 

#include <string>
#include <variant>
#include <unordered_map>
#include <vector>

using word = std::string;
using number = int;
using NameComand = std::string;
using Options = std::vector<std::string>;

//using argument = std::string; 



struct Params{
    std::vector<number> integerArguments;
    std::vector<word> stringArguments;
    
}; 


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






