#pragma once

#include "../../inc/Slide/slide.h"

class Editor{
public:
    void addElips(pos x, pos y, length len, lenght high);
    void addCircle(pos x, pos y, length radius);
    void addRectangle(pos x, pos y, length len, lenght high);
    void addSquare(pos x, pos y, length len);

    void moveVertical(Pos y);
    void moveHorizontal(Pos x);

    void changeIthemColor(color::sColor color);
    void changeIthemLength(length len);
    void changeIthemHeight(length high);

    void removeIthem(ID id);
private:
    Id genereytId();

private:
    ID ithemCaont;


};