#include "controler.h"



void Controler::startProces(){
    registrComand();
    while(true){
        try{
            Parser parser;
            parser.input(std::cin);
            parser.parsing();
            std::shared_ptr<IComand> comand = comandFactory.createComand(parser.getComand());
            comand->setOptionValue(parser.getOptionsValue());
            comand->execute();
        }
        catch(const std::exception& e){
            std::cout << e.what();  
        }
    }
}


void Controler::registrComand(){
    comandFactory.registorComand("new", std::make_shared<New>());                                       //new
    comandFactory.registorComand("undo", std::make_shared<Undo>());                                     //undo
    comandFactory.registorComand("redo", std::make_shared<Redo>());                                     //redo
    comandFactory.registorComand("addpage", std::make_shared<AddPage>());                               //add page -pos
    comandFactory.registorComand("pushbackpage", std::make_shared<PushBackPage>());                     //push back page
    comandFactory.registorComand("removepage", std::make_shared<RemovePage>());                         //remove page -pos
    comandFactory.registorComand("popbackpage", std::make_shared<PopBackPage>());                       //pop back page
    comandFactory.registorComand("swappage", std::make_shared<SwapPage>());                             //swsp page
    comandFactory.registorComand("openpage", std::make_shared<OpenPage>());                             //open page -pos
    comandFactory.registorComand("addshape", std::make_shared<AddShape>());                             //add -t -x -y -length -hight                           
    comandFactory.registorComand("movevertical", std::make_shared<MoveVertical>());                     //move verticalid -x
    comandFactory.registorComand("movehorizontal", std::make_shared<MoveHorizontal>());                 //move horizontalid -x
    comandFactory.registorComand("changeithemlength", std::make_shared<ChangeIthemLenghth>());          //change ithem length -id -length
    comandFactory.registorComand("changeithemheight", std::make_shared<ChangeIthemHeight>());           //change ithem height -id -height
    comandFactory.registorComand("removeithrm", std::make_shared<RemoveIthem>());                       //remove ithrm -id
    comandFactory.registorComand("printslide", std::make_shared<PrintSlide>());                         //print slide
    comandFactory.registorComand("printpage", std::make_shared<PrintPage>());                           //printPage

}