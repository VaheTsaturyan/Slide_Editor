#include "Sterializer.h"

Sterializer &Sterializer::getSterilizer(){
    static Sterializer sterilizer;
    return sterilizer; 
}