#include "lexer.h"



void Lexer::setString(std::istream& is){
    std::getline(is, str, ' ');
    if(!str.empty()){
        tokeValidFactor = eTokenOrder::NULL_TOKEN;
        return;
    }
    tokeValidFactor = eTokenOrder::VALID;
}

void Lexer::lexerAnaliz(){
    auto tokenType = returnTokenType();
    if(tokenType == eTokenType::BADTYPE){
        tokeValidFactor = eTokenOrder::INVALID;
        return;
    }
    token.tokenType = tokenType;
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
        token.tokenContent = str.substr(1, str.szie() - 2);
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



typename eTokenType Lexer::returnTokenType(){
    if (std::all_of(token.begin(), token.end(), ::isalpha)){
        return eTokenType::WORD;
    }       
    if(std::all_of(str.begin, str.end(), ::isdigit)){
        return eTokenType::OPTION_NUMBER;
    }
    if(str.size() >= 2 && str.front() == '<' && str.back() == '>'){
        if (std::all_of( token.begin(), token.end(), ::isalpha))
            return eTokenType::OPTION_WORD;
    }
    if(str[0] == '-' && str.size() >= 2){
        if(std::all_of( token.begin() + 1, token.end(), ::isalpha)){
            return eTokenType::ARGUMENT;
        }
    }
    return eTokenType::BADTYPE;
    
}
