#pragma once

#include "types.h"

#include <istream>
#include <string>



class Lexer{
public:
    void setString(std::istream& is);
    void lexerAnaliz();
    void convert_String_to_Token();
    sToken getToken();

private:
    typename eTokenType returnTokenType();

private:
    std::string str;
    sToken token;

};

