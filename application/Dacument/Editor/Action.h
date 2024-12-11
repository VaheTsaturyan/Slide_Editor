#pragma once

#include "../inc/Slide/slide.h"

/*
    void setSlide(std::shared_ptr<Slide> slide);

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
    moveVertical moveHorizontal changeIthemLength changeIthemHeight


*/

#include <string>
#include <memory>
#include <unordered_map>
#include <variant>

namespace act{




class IAction{
public:
    virtual ~IAction() = default;
    virtual void doo() = 0;
    virtual std::shared_ptr<IAction> returnUndoAction() = 0;
};





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class PushBack : public IAction{
public:
    PushBack(std::shared_ptr<Slide> slide, std::shared_ptr<Page> page);
    void doo() override;
    std::shared_ptr<IAction> returnUndoAction() override;

private:
    std::shared_ptr<Slide> slide;
    std::shared_ptr<Page> page;

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class PoPBack : public IAction{
public:
    PoPBack(std::shared_ptr<Slide> slide);
    void doo() override;
    std::shared_ptr<IAction> returnUndoAction() override;

private:
    std::shared_ptr<Slide> slide;
    std::shared_ptr<Page> page;

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class AddPage : public IAction{
public:
    AddPage(std::shared_ptr<Slide> slide , Pos pos, std::shared_ptr<Page> page);
    void doo() override;
    std::shared_ptr<IAction> returnUndoAction() override;

private:
    std::shared_ptr<Slide> slide;
    std::shared_ptr<Page> page;
    Slide::Iterator iterator;

};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class RemovePage : public IAction{
public:
    RemovePage(std::shared_ptr<Slide> slide, Pos pos);
    void doo() override;
    std::shared_ptr<IAction> returnUndoAction() override;

private:
    std::shared_ptr<Slide> slide;
    std::shared_ptr<Page> page;    
    Slide::Iterator iterator;
    Pos pos;

};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class SwapPages : public IAction{
public:
    SwapPages(std::shared_ptr<Slide> slide, std::shared_ptr<Page> page1, std::shared_ptr<Page> page2);
    void doo() override;
    std::shared_ptr<IAction> returnUndoAction() override;

private:
    std::shared_ptr<Slide> slide;
    std::shared_ptr<Page> page1;
    std::shared_ptr<Page> page2;    

};



/*
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class OpenPage : public IAction{
public:
    OpenPage(Pos pos);
    void doo() override;
    std::shared_ptr<IAction> returnUndoAction() override;

private:
    std::shared_ptr<Page> page;

};


*/




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class AddShape : public IAction{
public:
    AddShape(std::shared_ptr<Page> page, std::shared_ptr<Ithem> ithem); 
    void doo() override;
    std::shared_ptr<IAction> returnUndoAction() override;
private:
    std::shared_ptr<Page> page;
    std::shared_ptr<Ithem> ithem;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class RemoveIthem : public IAction{
public:
    RemoveIthem(std::shared_ptr<Page> page, ID id);
    void doo() override;
    std::shared_ptr<IAction> returnUndoAction() override;

private:
    std::shared_ptr<Page> page;
    std::shared_ptr<Ithem> ithem;

};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ChangeIthemGeometry : public IAction{
public:
    ChangeIthemGeometry(Ithem& ithem, const sGeometry& geometry);
    void doo() override;
    std::shared_ptr<IAction> returnUndoAction() override;

private:
    Ithem& ithem_;
    sGeometry geometry;

};

}//namespace act