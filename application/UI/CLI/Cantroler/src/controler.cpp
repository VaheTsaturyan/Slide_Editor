#include "controler.h"

void Controler::setEditor(std::shared_ptr<Editor> editor){
    this->editor = editor;
}

void Controler::setSterilizer(std::shared_ptr<Sterilizer> sterilizer){
    this->sterilizer = sterilizer;
}

void Controler::startProces()
{
    registrComand();
    while(true){
        try{
            Parser parser;
            parser.input(std::cin);
            parser.parsing();
            IComand comand = comandFactory.createComand(parser.getComand());
            comand.setParams(parser.getParams());
            comand.setOptions(parser.getOptions());
            comand.setEditor(editor);
            comand.execute();
        }
        catch(const std::exception& e){
            std::cout << e.what();  
        }
    }
}

void Controler::registrComand(){
    comandFactory.registorComand("new", std::make_shared<New>());                                       //new
    comandFactory.registorComand("addpage", std::make_shared<AddPage>());                               //add page -pos
    comandFactory.registorComand("removepage", std::make_shared<RemovePage>());                         //remove page -pos
    comandFactory.registorComand("openpage", std::make_shared<OpenPage>());                             //open page -pos
    comandFactory.registorComand("addshape", std::make_shared<AddShape>());                             //add -t -x -y -length -hight                           
    comandFactory.registorComand("movevertical", std::make_shared<MoveVertical>());                     //move verticalid -x
    comandFactory.registorComand("movehorizontal", std::make_shared<MoveHorizontal>());                 //move horizontalid -x
    comandFactory.registorComand("changeithemlength", std::make_shared<ChangeIthemLenghth>());          //change ithem length -id -length
    comandFactory.registorComand("changeithemheight", std::make_shared<ChangeIthemHeight>());           //change ithem height -id -height
    comandFactory.registorComand("removeithrm", std::make_shared<RemoveIthem>());                       //remove ithrm -id
}