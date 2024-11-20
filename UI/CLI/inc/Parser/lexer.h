#pragma once

#include "types.h"

#include <istream>
#include <string>
#include <vector>



class Lexer{
public:
    void setString(std::istream& is);
    void lexerAnaliz();
    sToken getToken();
    eTokenOrder getTokenOrder();
    void zeroState();

private:
    void convert_String_to_Token();
    eTokenType returnTokenType();
    void conversInputStringToStringVector();
    bool isWord();
    bool isOptionNumber();
    bool isOptionWord();
    bool isArgument();

private:
    std::string inputStr;
    std::string str;
    std::vector<std::string> strings;
    sToken token;
    eTokenOrder tokeValidFactor;

};

