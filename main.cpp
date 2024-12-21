#include "./application/application.h"


#include <iostream>

int main(int argc, char *argv[]){
    Application application(argc, argv);

    return application.exec();
}