#include "lexer.h"



void Lexer::setString(std::istream& is){
    std::getline(is, inputString);
    if(!str.empty()){
        //output "invalid comand"
    }
    split();
}

void Lexer::makeTokenList(){
    while(strings.empty()){
        str = strings.front();
        strings.erase(0);
        lexerAnaliz();
        convert_String_to_Token();
        tokens.push_back(token);
    }
}

void Lexer::lexerAnaliz(){
    auto tokenType = returnTokenType();
    try{
        if(tokenType = eTokenType::BADTYPE){
            //str.clear();
            throw std::runtime_error("CLI: NOT VALID OPTION");
        }
        token.tokenType = tokenType;
    }catch(std::exception& except){
        except.what();
    }

}

void Lexer::convert_String_to_Token(){
    switch (token.tokenType)
    {
    case eTokenType::WORD
        token.tokenContent = str;
        break;
    case eTokenType::NUMBER
        token.tokenContent = std::stoi(str);
        break;
    case eTokenType::ARGUMENT
        token.tokenContent = str[1];
        break;
    }
}

std::vector<sToken>& Lexer::getToken(){
    return tokens;
}


/*            if(std::all_of(str.begin + 2, str.end(), ::isdigit))
                return eTokenType::NUMBER;
            else if (std::all_of(token.begin() + 2, token.end(), ::isalpha))
                return eTokenType::WORD;   */


typename eTokenType Lexer::returnTokenType(){
    if (std::all_of(token.begin(), token.end(), ::isalpha))
        return eTokenType::WORD;
    else if(std::all_of(str.begin, str.end(), ::isdigit))
        return eTokenType::NUMBER;
    if(str[0] == '-'){
        if( str[1] >= 'a' && str[1] <= 'z' ){
            eTokenType::ARGUMENT;
        }
    }else{
        return eTokenType::BADTYPE;
    }
}

void Lexer::split(char delimiter){
    auto begin = inputString.begin();
    auto end = std::find(begin, inputString.end(), delimiter);

    while(end != inputString.end()){
        strings.emplace_back(begin, end);
        begin = ++end;
        end = std::find(begin, inputString.end(), delimiter);
    }

}
