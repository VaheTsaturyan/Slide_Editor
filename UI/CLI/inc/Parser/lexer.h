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

private:
    void convert_String_to_Token();
    typename eTokenType returnTokenType();

private:
    std::string str;
    sToken token;
    eTokenOrder tokeValidFactor;

};

