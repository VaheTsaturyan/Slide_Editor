#pragma once 

#include "../../UI/CLI/inc/cli.h"
#include "../../Dacument/inc/dacumet.h"

#include <iostream>
#include <memory>


class Controler{
public:
    void startProces();
private:
    void registrComand();
private:
    Parser parser;
    //std::shared_ptr<Slide_Collection> slideColection;
};
