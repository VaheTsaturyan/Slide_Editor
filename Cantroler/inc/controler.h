#pragma once 

#include "../UI/CLI/inc/cli.h"

#include <iostream>



class Controler{
public:
    void startProces();
private:
    void registrComand();

private:
    cli::Parser parser;


};
