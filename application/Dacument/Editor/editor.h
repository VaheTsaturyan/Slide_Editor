#pragma once

#include "../../inc/Slide/slide.h"

class Editor{
public:
    void setSlide(std::shared_ptr<Slide> slide);

    void newSlide();
    
    void addPage(Pos pos);
    void removePage(Pos pos);
    void swopPages(Pos first, Pos second);
    void openPage(Pos pos);
    
    void addShape(std::string type, Pos x, Pos y, length len, length high);
    void removeIthem(ID id);
    
    void moveVertical(ID id, Pos y);
    void moveHorizontal(ID id, Pos x);
    void changeIthemLength(ID id, length len);
    void changeIthemHeight(ID id, length high);

    void changeIthemColor(ID id, color::sColor color);
    


private:
    ID genereytId();
    void setPage(std::shared_ptr<Page> page);

private:    
    std::shared_ptr<Slide> slide_;
    std::shared_ptr<Page> page_;
    ID ithemCaont = 0;

};