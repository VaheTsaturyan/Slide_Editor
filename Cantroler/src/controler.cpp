#include "controler.h"


void Controler::startProces(){
    registrComand();
    while(true){
        try{
            Parser parser;
            parser.input(std::cin);
            parser.startProces();
            AComand& comand = comandFactory.createComand(parser.getTokensList());
            comand.execute();
        }
        catch(const std::exception& e){
            std::cout << e.what();
            //parser.zeroState();    
        }
    }
}

void Controler::registrComand(){
    comandFactory.registorComand("new", std::make_shared<New>());
    comandFactory.registorComand("addpagepos", std::make_shared<AddPage>());
    comandFactory.registorComand("removepagepos", std::make_shared<RemovePage>());
    comandFactory.registorComand("openpagepos", std::make_shared<OpenPage>());
    comandFactory.registorComand("addtxylengthhight", std::make_shared<AddShape>());
    comandFactory.registorComand("moveverticalidx", std::make_shared<MoveVertical>());
    comandFactory.registorComand("movehorizontalidx", std::make_shared<MoveHorizontal>());
    comandFactory.registorComand("changeithemlengthidlength", std::make_shared<ChangeIthemLenghth>());
    comandFactory.registorComand("changeithemheightidheight", std::make_shared<ChangeIthemHeight>());
    comandFactory.registorComand("removeithrmid", std::make_shared<RemoveIthem>());
}