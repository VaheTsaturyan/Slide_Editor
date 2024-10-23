#include "controler.h"


void Controler::startProces(){
    registrComand();
    while(true){
        try{
            parser.input(std::cin);
            parser.startProces();
        }
        catch(const std::exception& e){
            std::cerr << e.what() << '\n';
        }
    }
}

void Controler::registrComand(){
    parser.registrComand("new", std::make_shared<NewComand>());
    parser.registrComand("addslidepos", std::make_shared<NewComand>());
    /*
    
    parser.registrComand("Newfpath", std::make_shared<NewComand>());
    parser.registrComand("Newfpath", std::make_shared<NewComand>());
    parser.registrComand("Newfpath", std::make_shared<NewComand>());
    
    */
    
}