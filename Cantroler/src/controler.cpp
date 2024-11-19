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
    comandFactory.registorComand("new", std::make_shared<New>());                                       //new
    comandFactory.registorComand("addpagepos", std::make_shared<AddPage>());                            //add page -pos
    comandFactory.registorComand("removepagepos", std::make_shared<RemovePage>());                      //remove page -pos
    comandFactory.registorComand("openpagepos", std::make_shared<OpenPage>());                          //open page -pos
    comandFactory.registorComand("addtxylengthhight", std::make_shared<AddShape>());                    //add -t -x -y -length -hight
    comandFactory.registorComand("addtxylh", std::make_shared<AddShape>());                             //add -t -x -y -l -h
    comandFactory.registorComand("moveverticalidx", std::make_shared<MoveVertical>());                  //move verticalid -x
    comandFactory.registorComand("movehorizontalidx", std::make_shared<MoveHorizontal>());              //move horizontalid -x
    comandFactory.registorComand("changeithemlengthidlength", std::make_shared<ChangeIthemLenghth>());  //change ithem length -id -length
    comandFactory.registorComand("changeithemheightidheight", std::make_shared<ChangeIthemHeight>());   //change ithem height -id -height
    comandFactory.registorComand("removeithrmid", std::make_shared<RemoveIthem>());                     //remove ithrm -id
}