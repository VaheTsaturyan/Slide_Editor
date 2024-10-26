#pragma once

#include "./Editor/editor.h"
#include "./Sterializer/Sterializer.h"


/*
    void addRectangle(pos x, pos y, length len, lenght high);
    
    void moveVertical(ID id, Pos y);
    void moveHorizontal(ID id, Pos x);

    void changeIthemColor(ID id, color::sColor color);
    void changeIthemLength(ID id, length len);
    void changeIthemHeight(ID id, length high);

    void removeIthem(ID id);

    void setPage(std::shared_ptr<Page> page);
private:
    Id genereytId();

private:
    ID ithemCaont = 0;
    std::shared_ptr<Page> page_;
*/


class SlideMeneger{
public:
    static void newSlide();

    static void addPage(Pos pos);
    static void removePage(Pos pos);
    static void swopPages(Pos first, Pos second);
   
    static void openPage(Pos pos);
    static void addRectangle(pos x, pos y, length len, lenght high);
    
    static void moveVertical(ID id, Pos y);
    static void moveHorizontal(ID id, Pos x);

    //void changeIthemColor(ID id, color::sColor color);
    static void changeIthemLength(ID id, length len);
    static void changeIthemHeight(ID id, length high);

    static void removeIthem(ID id);

private:
    static Editor editor;
    static Sterializer sterializer;
    static Slide slide;
};