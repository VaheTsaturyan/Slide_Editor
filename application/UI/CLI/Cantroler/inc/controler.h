#pragma once 

#include "../../ComandFactory/inc/comandCreate.h"
#include "../../Parser/inc/parser.h"

#include <iostream>
#include <memory>


class Controler{
public:
    void setEditor(std::shared_ptr<Editor> editor);
    void setSterilizer(std::shared_ptr<Sterilizer> sterilizer);
    void startProces();

private:
    void registrComand();

private:
    ComandFactory comandFactory;
    std::shared_ptr<Editor> editor;
    std::shared_ptr<Sterilizer> sterilizer;
};
