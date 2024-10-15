#include "parser.h"

#include <iostream>

void Parser::LexsikAnaliz(){
    lexsik_analizer.setString(std::cin);
    lexsik_analizer.lexerAnaliz();
    lexsik_analizer.convert_String_to_Token();
}
