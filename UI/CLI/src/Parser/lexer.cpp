#include "lexer.h"

#include <algorithm>
#include  <iterator>

void Lexer::setString(std::istream& is){
    std::getline(is, inputStr);
    if(inputStr.empty()){
        tokeValidFactor = eTokenOrder::NULL_TOKEN;
        return;
    }
    tokeValidFactor = eTokenOrder::VALID;
    conversInputStringToStringVector();
}

void Lexer::lexerAnaliz(){
    if(strings.empty()){
        tokeValidFactor = eTokenOrder::NULL_TOKEN;
        return;
    }
    auto tokenType = returnTokenType();
    if(tokenType == eTokenType::BADTYPE){
        throw std::runtime_error("CLI: invalid comand !\n");
    }
    token.tokenType = tokenType;
    convert_String_to_Token();
}

void Lexer::convert_String_to_Token(){
    switch (token.tokenType)
    {
    case eTokenType::WORD:
        token.tokenContent = str;
        break;
    case eTokenType::OPTION_NUMBER:
        token.tokenContent = std::stoi(str);
        break;
    case eTokenType::OPTION_WORD:
        token.tokenContent = str.substr(1, str.size() - 2);
        break;
    case eTokenType::ARGUMENT:
        token.tokenContent = str.substr(1, str.size()- 1);
        break;
    }
}

sToken Lexer::getToken(){
    return token;
}

eTokenOrder Lexer::getTokenOrder(){
    return tokeValidFactor;
}



eTokenType Lexer::returnTokenType(){
    str = strings.front();
    strings.erase(strings.begin());
    if (std::all_of(str.begin(), str.end(), [](unsigned char c) {
                                                return std::isalpha(c);
                                            })){
        return eTokenType::WORD;
    }       
    if(std::all_of(str.begin(), str.end(), [](unsigned char c) {
                                            return std::isdigit(c);
                                        })){
        return eTokenType::OPTION_NUMBER;
    }
    if(str.size() >= 2 && str.front() == '<' && str.back() == '>'){
        if (std::all_of( str.begin() + 1, str.end()-1, [](unsigned char c) {
                                                            return std::isalpha(c);
                                                        }))
            return eTokenType::OPTION_WORD;
    }
    if(str[0] == '-' && str.size() >= 2){
        if(std::all_of( str.begin() + 1, str.end(),  [](unsigned char c) {
                                                            return std::isalpha(c);
                                                        })){
            return eTokenType::ARGUMENT;
        }
    }
    return eTokenType::BADTYPE;
    
}

void Lexer::conversInputStringToStringVector(){
    auto start = inputStr.begin();
    auto end = find(start, inputStr.end(), ' ');
    while(end != inputStr.end()){
        int pos = std::distance(inputStr.begin(), start);
        int count = std::distance(start, end);
        strings.push_back(inputStr.substr(pos, count));
        start = end + 1;
        end =  find(start, inputStr.end(), ' ');
    }
}   
