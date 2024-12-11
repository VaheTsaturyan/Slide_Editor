#include "lexer.h"

#include <algorithm>
#include <iterator>



void Lexer::setString(std::istream& is){
    std::getline(is, inputStr);
    if(inputStr.empty()){
        tokeValidFactor = eTokenOrder::NULL_TOKEN;
        return;
    }
    conversInputStringToStringVector();
    margeStringVector();
    tokeValidFactor = eTokenOrder::VALID;
}


void Lexer::lexerAnaliz(){
    if(strings.empty()){
        tokeValidFactor = eTokenOrder::NULL_TOKEN;
        return;
    }
    auto tokenType = returnTokenType();
    if(tokenType == eTokenType::BAD_TYPE){
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
    case eTokenType::OPTION:
        token.tokenContent = str.substr(1, str.size()- 1);
        break;
    case eTokenType::ARGUMENT_NUMBER:
        token.tokenContent = std::stoi(str);
        break;
    case eTokenType::ARGUMENT_WORD:
        token.tokenContent = str.substr(1, str.size() - 2);
        break;
    case eTokenType::COMMA:
        token.tokenContent = str;
        break;
    case eTokenType::TEXT:
        token.tokenContent = str.substr(1, str.size()- 2);
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
    if(isArgumentWord()){
        return eTokenType::ARGUMENT_WORD;
    }
    if(isArgumentNumber()){
        return eTokenType::ARGUMENT_NUMBER;
    }
    if(isOption()){
        return eTokenType::OPTION;
    }
    if(isComma()){
        return eTokenType::COMMA;
    }
    if(isText()){
        return eTokenType::TEXT;
    }

    return eTokenType::BAD_TYPE;
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


void Lexer::margeStringVector(){
    for(size_t i = 0; i < strings.size(); ++i){
        if(strings[i].front() == '"'&& strings[i].back() == '"'){
            continue;
        }
        if(strings[i].front() == '"'){
            size_t j = 1;
            while( (i + j) < strings.size() && strings[i + j].back() != '"' ){
                strings[i] + " " + strings[i + j];
                ++j;   
            }
            strings.erase(std::next(strings.begin(), i + 1), std::next(strings.begin(), i + j));

        }
        if( strings[i].size() != 1 && strings[i].back() == ','){
            strings[i].pop_back();
            strings.insert(std::next(strings.begin(), i+1), ",");
        }
    }

}


bool Lexer::isWord(){
    for(auto chr : str){
        if(chr < 'a' ||  chr > 'z'){
            return false;
        }
    }
    return true;
}


bool Lexer::isText(){
    return (str.size() > 2) && (str.front() == '"' && str.back() == '"');
}


bool Lexer::isArgumentNumber(){
    if( str.front() != '-' && (str.front() < '0' || str.front() > '9')){
        return false;
    }
    for(size_t i = 1; i < str.size(); ++i){
        if(str[i] < '0' ||  str[i] > '9'){
            return false;
        }
    }
    return true;
}


bool Lexer::isArgumentWord(){
    if((str.size() >= 2 && str.front() != '<' && str.back() != '>')||str.size() < 2){
        return false;
    }
    for(size_t i = 1; i < str.size()-1; ++i){
        if(str[i]<'a' || str[i] > 'z'){
            return false;
        }
    }
    return true;
}


bool Lexer::isOption(){
    if(str.size() < 2 || str.front() != '-'){
        return false;
    }
    for(size_t i = 1; i < str.size(); ++i){
        if(str[i]<'a' || str[i] > 'z'){
            return false;
        }
    }
    return true;
}


bool Lexer::isComma(){
    return str.size() == 1 && str.front() == ',';
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

