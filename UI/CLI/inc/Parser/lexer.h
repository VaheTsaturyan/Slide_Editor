#pragma once

#include "types.h"

#include <istream>
#include <string>
#include <vector>



class Lexer{
public:
    void setString(std::istream& is);
    void makeTokenList();
    void lexerAnaliz();
    void convert_String_to_Token();
    std::vector<sToken>& getToken();

private:
    typename eTokenType returnTokenType();
    void split(char delimiter);
private:
    std::vector<std::string> strings;
    std::vector<sToken> tokens;
    std::string inputString;
    std::string str;
    sToken token;

};

