#pragma once

#include "types.h"
#include "../../../../Dacument/Editor/editor.h"
#include "../../../../Visualizetion/visualizer.h"
#include "../../SemanticAnalizer/inc/semanticFactory.h"

#include <vector>
#include <memory>
#include <unordered_set>



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class IComand{
public:
    virtual ~IComand() = default;
    virtual void execute() = 0;
    virtual void setOptionValue(std::shared_ptr<std::unordered_map<Options, Params>> optionsValue) = 0;
    virtual std::shared_ptr<IComand> returnCopy() = 0;
    virtual std::unordered_map<Options, Params>& getOptionValue() = 0;

};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class AComand : public IComand{
public:
    void setOptionValue(std::shared_ptr<std::unordered_map<Options, Params>> optionsValue) override;
    std::unordered_map<Options, Params>& getOptionValue() override;

protected:
    virtual bool isOptionsValid() = 0;

private:
    std::shared_ptr<std::unordered_map<Options, Params>> optionMap;

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Undo : public AComand{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

protected:
    bool isOptionsValid() override;
 
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Redo : public AComand{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

protected:
    bool isOptionsValid() override;
 
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class New : public AComand{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

protected:  
    bool isOptionsValid() override;
 
};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class AddPage : public AComand{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

protected:
    bool isOptionsValid() override;

private:
    Pos pos;

};





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class PushBackPage : public AComand{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

protected:
    bool isOptionsValid() override;

};






//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class PopBackPage : public AComand{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

protected:
    bool isOptionsValid() override;

};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class RemovePage : public AComand{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

protected:
    bool isOptionsValid() override;

private:
    Pos pos;

};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class OpenPage : public AComand{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

protected:
    bool isOptionsValid() override;

private:
    Pos pos;
};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class SwapPage : public AComand{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

protected:
    bool isOptionsValid() override;

private:
    std::vector<int> vecInt;

};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class AddShape : public AComand{
public:
    //static initSemanticMap();
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;
    
protected:
    bool isOptionsValid() override;

private:
    sem::ShapeInitilizer shpInit;
    sGeometry geometry;
    sAtributs atributs;

};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class RemoveIthem : public AComand{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

protected:
    bool isOptionsValid() override;

private:
    ID id;

};







///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class AChangeIthemGeometry : public AComand{
protected:
    bool isOptionsValid();

protected:
    ID id;
    int changeSize;

};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class MoveVertical : public AChangeIthemGeometry{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class MoveHorizontal : public AChangeIthemGeometry{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ChangeIthemLenghth : public AChangeIthemGeometry{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ChangeIthemHeight : public AChangeIthemGeometry{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class PrintSlide : public AComand{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

protected:
    bool isOptionsValid() override;

};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class PrintPage : public AComand{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

protected:
    bool isOptionsValid() override;

private:
    Pos pos;

};

class DrawPage : public AComand{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

protected:
    bool isOptionsValid() override;

private:
    std::string path;
    Pos pos;

};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Open : public AComand{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

protected:
    bool isOptionsValid() override;

private:
    std::string path;

};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Save : public AComand{
public:
    void execute() override;
    std::shared_ptr<IComand> returnCopy() override;

protected:
    bool isOptionsValid() override;

private:
    std::string path;

};
