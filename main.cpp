#include "./application/application.h"


#include <iostream>

int main(){
    Application& application = Application::getAplication();

    return application.exec();
}