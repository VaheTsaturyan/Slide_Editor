#pragma once

#include "../inc/Slide/slide.h"
#include "../../UI/CLI/types.h"
#include "Action.h"

#include <stack>

class Editor{
public:
    static Editor& getEditor();
    
    void proces(std::shared_ptr<act::IAction> action);
    void undo();
    void redo();
    void clear();
    ID genereytId();

private:
    Editor() = default;


private:
    std::stack<std::shared_ptr<act::IAction>> undo_;
    std::stack<std::shared_ptr<act::IAction>> redo_;
    ID ithemCaont = 0;

};

/*




    void newSlide();
    
    void addPage(Pos pos);
    void pushBackPage();
    void popBackPage();
    void removePage(Pos pos);
    void swapPages(Pos first, Pos second);
    void openPage(Pos pos);
    
    void addShape(std::string type, const std::unordered_map<std::string, int>& paramsMap);
    void removeIthem(ID id);
    
    void moveVertical(ID id, Pos y);
    void moveHorizontal(ID id, Pos x);
    void changeIthemLength(ID id, length len);
    void changeIthemHeight(ID id, length high);

    void changeIthemColor(ID id, color::sColor color);
    

*/