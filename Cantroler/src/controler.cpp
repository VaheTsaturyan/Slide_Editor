#include "controler.h"


void Controler::startProces(){
    registrComand();
    while(true){
        try{
            parser.input(std::cin);
            parser.startProces();
        }
        catch(const std::exception& e){
            std::cout << e.what() << '\n';
        }
    }
}

void Controler::registrComand(){
    parser.registrComand("new", std::make_shared<New>());
    parser.registrComand("addpagepos", std::make_shared<AddPage>());
    parser.registrComand("removepagepos", std::make_shared<RemovePage>());
    parser.registrComand("openpagespos", std::make_shared<OpenPagee>());
    parser.registrComand("addrectanglexylengthhight", std::make_shared<AddRectangle>());
    parser.registrComand("moveverticalidx", std::make_shared<MoveVertical>());
    parser.registrComand("movehorizontalidx", std::make_shared<MoveHorizontal>());
    parser.registrComand("changeithemlengthidlength", std::make_shared<ChangeIthemLenghth>());
    parser.registrComand("changeithemheightidheight", std::make_shared<ChangeIthemHeight>());
    parser.registrComand("removeithrmid", std::make_shared<RemoveIthem>());
}