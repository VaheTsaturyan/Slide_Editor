#pragma once

#include "types.h"


#include <vector>
#include <memory>
#include <unordered_set>

using NameComand = std::string;
using Options = std::vector<std::string>;


struct Params{
    std::vector<number> integerArguments;
    std::vector<word> stringArguments;
    
}; 



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class IComand{
public:
    virtual ~IComand() = default;
    virtual void execute() = 0;
    virtual void setParams(std::shared_ptr<Params> params) = 0;
    virtual void setOptions(std::shared_ptr<Options> options) = 0;
    virtual void setEditor(std::shared_ptr<Editor> editor) = 0;
    virtual const Params& getParams() const = 0;
    virtual const Options& getOptions() const = 0;

};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class AComand : public IComand{
public:
    virtual ~AComand() override = default;
    void setParams(std::shared_ptr<Params> params) override;
    void setOptions(std::shared_ptr<Options> options) override;
    void setEditor(std::shared_ptr<Editor> editor) override;
    const Params& getParams() const override;
    const Options& getOptions() const override;

protected:
    virtual bool paramsIsValid() = 0;
    virtual bool optionsIsValid() = 0;

private:
    std::shared_ptr<Editor> editor;
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

