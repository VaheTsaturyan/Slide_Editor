#pragma once

#include <cstddef> 
#include <unordered_map>
#include <string>
#include  <variant>

using Pos = int;
using ID = size_t;
using textSize = size_t;
using length = size_t;
using atrKey = std::string;



namespace color
{
    struct sColor{
        sColor(char red, char green, char blue);
        char red;
        char green;
        char blue;
    };
    
    inline const sColor BLACK = sColor(0,0,0);
    inline const sColor RED = sColor(255,0,0);
    inline const sColor GREEN = sColor(0,255,0);
    inline const sColor BLUE = sColor(0,0,255);
} // namespace color



struct sGeometry{
    sGeometry() = default;
    sGeometry(Pos x_, Pos y_, length len_, length hig_);
    ~sGeometry() = default;
    Pos x;
    Pos y;
    length len;
    length hig;
    sGeometry& operator=(const sGeometry& other);
};



struct sAtributs{
    std::unordered_map<std::string, std::string> map;
    sAtributs& operator=(sAtributs&&);
};

namespace atr{
    inline const atrKey Type = "Type: ";
    inline const atrKey Color = "Color: ";
    inline const atrKey lineThickness = "Line thickness: ";
}//atr

