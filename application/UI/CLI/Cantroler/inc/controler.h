#pragma once 

#include "../../ComandFactory/inc/comandCreate.h"
#include "../../Parser/inc/parser.h"
#include "../../../../Dacument/Sterializer/Sterializer.h"
#include "../../../../Visualizetion/visualizer.h"

#include <iostream>
#include <memory>


class Controler{
public:
    void startProces();

private:
    void registrComand();

private:
    ComandFactory comandFactory;
    
};
