#pragma once 

#include <string>
#include <variant>
#include <vector>
#include <unordered_map>


using word = std::string;
using number = int;
using NameComand = std::string;
using Options = std::string;
//using Params = std::variant<std::vector<int>, std::vector<string>>;


struct Params{
    std::vector<number> vectorInteger;
    std::vector<word> vectorString;
}; 




enum class eTokenType{
    WORD,
    OPTION,
    ARGUMENT_NUMBER,
    ARGUMENT_WORD,
    COMMA,
    TEXT,
    BAD_TYPE
};

enum class eTokenOrder{
    VALID,
    NULL_TOKEN
};

enum class eState{
    START,
    CMAND,
    OPTION,
    ARGUMENT_WORD,
    ARGUMENT_NUMBER,
    TEXT,
    DEAD_STATE
};





struct sToken{
    eTokenType tokenType;
    std::variant<int, std::string> tokenContent;
};








