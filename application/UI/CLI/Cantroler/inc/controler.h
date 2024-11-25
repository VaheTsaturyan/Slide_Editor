#pragma once 

#include "../../ComandFactory/inc/comandCreate.h"
#include "../../Parser/inc/parser.h"
#include "../../../../Dacument/Sterializer/Sterializer.h"
#include "../../../../Visualizetion/visualizer.h"

#include <iostream>
#include <memory>


class Controler{
public:
    void setEditor(std::shared_ptr<Editor> editor);
    void setSterilizer(std::shared_ptr<Sterializer> sterilizer);
    //void setIstream(std::istream& istrm);
    void setVisualizer(std::shared_ptr<Visualizer> visual);
    void startProces();

private:
    void registrComand();

private:
    ComandFactory comandFactory;
    std::shared_ptr<Editor> editor;
    std::shared_ptr<Sterializer> sterilizer;
    std::shared_ptr<Visualizer> visualizer;
    //std::istream inputStream;
};
