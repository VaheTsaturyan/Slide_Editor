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
        throw std::runtime_error("CLI: la -invalid comand !\n");
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
    str.clear();
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
    if(isWord()){
        return eTokenType::WORD;
    }
    if(isOptionNumber()){
        return eTokenType::OPTION_NUMBER;
    }
    if(isOptionWord()){
        return eTokenType::OPTION_WORD;
    }
    if(isArgument()){
        return eTokenType::ARGUMENT;
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
    int pos = std::distance(inputStr.begin(), start);
    int count = std::distance(start, end);
    strings.push_back(inputStr.substr(pos, count));

}

bool Lexer::isWord(){
    for(auto chr : str){
        if(chr < 'a' ||  chr > 'z'){
            return false;
        }
    }
    return true;
}

bool Lexer::isOptionNumber(){
    for(auto chr : str){
        if(chr < '0' ||  chr > '9'){
            return false;
        }
    }
    return true;
}

bool Lexer::isOptionWord(){
    if((str.size() >= 2 && str.front() != '<' && str.back() != '>')||str.size() < 2){
        return false;
    }
    for(int i = 1; i < str.size()-1; ++i){
        if(str[i]<'a' || str[i] > 'z'){
            return false;
        }
    }
    return true;
}

bool Lexer::isArgument()
{
    if(str.size() < 2 || str.front() != '-'){
        return false;
    }
    for(int i = 1; i < str.size(); ++i){
        if(str[i]<'a' || str[i] > 'z'){
            return false;
        }
    }
    return true;
}






















































/*
    isWord()
    isOptionNumber()
    isOptionWord()
    isArgument()


    if (std::all_of(str.begin(), str.end(), [](char ch) {
                                                unsigned char c = static_cast<unsigned char>(ch);
                                                return std::isalpha(c);
                                            })){
        return eTokenType::WORD;
    }       
    if(std::all_of(str.begin(), str.end(),[](char ch) {
                                            unsigned char c = static_cast<unsigned char>(ch);
                                            return std::isdigit(c);
                                        })){
        return eTokenType::OPTION_NUMBER;
    }
    if(str.size() >= 2 && str.front() == '<' && str.back() == '>'){
        if (std::all_of( str.begin() + 1, str.end()-1, [](char ch) {
                                                        unsigned char c = static_cast<unsigned char>(ch);
                                                        return std::isalpha(c);
                                                        }))
            return eTokenType::OPTION_WORD;
    }
    if(str[0] == '-' && str.size() >= 2){
        if(std::all_of( str.begin() + 1, str.end(),  [](char ch) {
                                                        unsigned char c = static_cast<unsigned char>(ch);
                                                        return std::isalpha(c);
                                                        })){
            return eTokenType::ARGUMENT;
        }
    }

*/
