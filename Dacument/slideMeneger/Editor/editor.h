#pragma once

#include "../../inc/Slide/slide.h"

class Editor{
public:
    //void addElips(pos x, pos y, length len, lenght high);
    //void addCircle(pos x, pos y, length radius);
    //void addSquare(pos x, pos y, length len);

    void addRectangle(Pos x, Pos y, length len, length high);
    
    void moveVertical(ID id, Pos y);
    void moveHorizontal(ID id, Pos x);

    void changeIthemColor(ID id, color::sColor color);
    void changeIthemLength(ID id, length len);
    void changeIthemHeight(ID id, length high);

    void removeIthem(ID id);

    void setPage(std::shared_ptr<Page> page);
private:
    ID genereytId();

private:
    ID ithemCaont = 0;
    std::shared_ptr<Page> page_;


};