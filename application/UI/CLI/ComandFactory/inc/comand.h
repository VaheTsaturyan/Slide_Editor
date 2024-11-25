#pragma once

#include "types.h"
#include "../../../../Dacument/Editor/editor.h"
#include "../../../../Visualizetion/visualizer.h"


#include <vector>
#include <memory>
#include <unordered_set>



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class IComand{
public:
    virtual ~IComand() = default;
    virtual void execute() = 0;
    virtual void setParams(std::shared_ptr<Params> params) = 0;
    virtual void setOptions(std::shared_ptr<Options> options) = 0;
    virtual Params& getParams() = 0;
    virtual Options& getOptions() = 0;

};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class AComand : public IComand{
public:
    virtual ~AComand() override = default;
    void setParams(std::shared_ptr<Params> params) override;
    void setOptions(std::shared_ptr<Options> options) override;
    Params& getParams() override;
    Options& getOptions() override;

protected:
    virtual bool paramsIsValid() = 0;
    virtual bool optionsIsValid() = 0;

private:
    std::shared_ptr<Params> params;
    std::shared_ptr<Options> options;

};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class New : public AComand{
public:
    void execute() override;

protected:
    bool paramsIsValid() override;
    bool optionsIsValid() override;

};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class AddPage : public AComand{
public:
    void execute() override;

protected:
    bool paramsIsValid() override;
    bool optionsIsValid() override;

};





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class pushBackPage : public AComand{
public:
    void execute() override;

protected:
    bool paramsIsValid() override;
    bool optionsIsValid() override;

};






//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class popBackPage : public AComand{
public:
    void execute() override;

protected:
    bool paramsIsValid() override;
    bool optionsIsValid() override;

};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class RemovePage : public AComand{
public:
    void execute() override;

protected:
    bool paramsIsValid() override;
    bool optionsIsValid() override;

};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class OpenPage : public AComand{
public:
    void execute() override;

protected:
    bool paramsIsValid() override;
    bool optionsIsValid() override;

};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class AddShape : public AComand{
public:
    AddShape();
    void execute() override;

protected:
    bool paramsIsValid() override;
    bool optionsIsValid() override;

private:
    void initOptionsMap();
    void initTypeMap();
    std::unordered_map<std::string, int> genereytMapOpsonValue();

private:
    std::unordered_set<std::string> optionsMap;
    std::unordered_set<std::string> typeMap;

};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class RemoveIthem : public AComand{
public:
    void execute() override;

protected:
    bool paramsIsValid() override;
    bool optionsIsValid() override;

};







///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class AChangeIthemGeometry : public AComand{
protected:
    bool paramsIsValid() override;
    bool optionsIsValid() override;

protected:
    std::unordered_set<std::string> optionsMap;   

};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class MoveVertical : public AChangeIthemGeometry{
public:
    MoveVertical();
    void execute() override;

private:
    void initOptionMap();

};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class MoveHorizontal : public AChangeIthemGeometry{
public:
    MoveHorizontal();
    void execute() override;

private:
    void initOptionMap();

};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ChangeIthemLenghth : public AChangeIthemGeometry{
public:
    ChangeIthemLenghth();
    void execute() override;

private:
    void initOptionMap();

};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ChangeIthemHeight : public AChangeIthemGeometry{
public:
    ChangeIthemHeight();
    void execute() override;

private:
    void initOptionMap();

};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class printSlide : public AComand{
public:
    void execute() override;

protected:
    bool paramsIsValid() override;
    bool optionsIsValid() override;
};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class printPage : public AComand{
public:
    void execute() override;

protected:
    bool paramsIsValid() override;
    bool optionsIsValid() override;
};
