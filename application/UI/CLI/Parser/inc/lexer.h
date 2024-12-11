#pragma once

#include "types.h"

#include <istream>
#include <string>
#include <vector>
#include <sstream>


class Lexer{
public:
    void setString(std::istream& is);
    void lexerAnaliz();
    sToken getToken();
    eTokenOrder getTokenOrder();

private:
    void convert_String_to_Token();
    eTokenType returnTokenType();
    void conversInputStringToStringVector();
    void margeStringVector();
    bool isWord();
    bool isText();
    bool isArgumentNumber();
    bool isArgumentWord();
    bool isOption();
    bool isComma();

private:
    std::vector<std::string> strings;
    std::string inputStr;
    std::string str;
    sToken token;
    eTokenOrder tokeValidFactor;

};

