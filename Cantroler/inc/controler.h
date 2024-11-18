#pragma once 

#include "../../UI/CLI/inc/cli.h"

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
