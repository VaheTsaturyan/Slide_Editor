#pragma once

using Pos = int;
using ID = size_t;
using textSize = size_t;
using length = size_t;





namespace color
{
    struct sColor{
        sColor(char red, char green, char blue);
        char red;
        char green;
        char blue;
    };
    const sColor BLACK = sColor(0,0,0);
    const sColor RED = sColor(255,0,0);
    const sColor GREEN = sColor(0,255,0);
    const sColor BLUE = sColor(0,0,255);

} // namespace color



struct sGeometry{
    sGeometry() = default;
    ~sGeometry() = default;
    Pos x;
    Pos y;
    length len;
    length hig;
    sGeometry& operator=(const sGeometry& other);
};

enum class eAtributs{
    
};

struct sAtributs{

};