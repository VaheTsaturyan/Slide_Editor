#include "controler.h"


void Controler::startProces(){
    registrComand();
    while(true){
        try{
            parser.input(std::cin);
            parser.setOutputStream(std::cout);
            parser.startProces();
        }
        catch(const std::exception& e){
            std::cerr << e.what() << '\n';
        }
    }
}

void Controler::registrComand(){
    parser.registrComand("Newfpath", std::make_shared<NewComand>());
    /*
    
    parser.registrComand("Newfpath", std::make_shared<NewComand>());
    parser.registrComand("Newfpath", std::make_shared<NewComand>());
    parser.registrComand("Newfpath", std::make_shared<NewComand>());
    parser.registrComand("Newfpath", std::make_shared<NewComand>());
    
    */
    
}