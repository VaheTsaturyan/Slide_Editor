#pragma once

#include "types.h"
#include "../../../../Dacument/slideMeneger/slideMeneger.h"


#include <vector>
#include <memory>

using NameComand = std::string;

struct Params{
    std::vector<number> integerArguments;
    std::vector<word> stringArguments;
}; 


class AComand{
public:
    virtual ~AComand() = default;
    virtual void execute() = 0;
    void setParams(std::shared_ptr<Params> params);
    const Params& getParams() const;
protected:
    virtual bool paramsIsValid() = 0;
private:
    std::shared_ptr<Params> params;
};

class New : public AComand{
public:
    void execute() override;
protected:
    bool paramsIsValid() override;
};


class AddPage : public AComand{
public:
    void execute() override;
protected:
    bool paramsIsValid() override;

};

class RemovePage : public AComand{
public:
    void execute() override;
protected:
    bool paramsIsValid() override;

};


class OpenPage : public AComand{
public:
    void execute() override;
protected:
    bool paramsIsValid() override;

};


class AddRectangle : public AComand{
public:
    void execute() override;
protected:
    bool paramsIsValid() override;

};

class MoveVertical : public AComand{
public:
    void execute() override;
protected:
    bool paramsIsValid() override;

};

class MoveHorizontal : public AComand{
public:
    void execute() override;
protected:
    bool paramsIsValid() override;
};


class ChangeIthemLenghth : public AComand{
public:
    void execute() override;
protected:
    bool paramsIsValid() override;
};

class ChangeIthemHeight : public AComand{
public:
    void execute() override;
protected:
    bool paramsIsValid() override;
};

class RemoveIthem : public AComand{
public:
    void execute() override;
protected:
    bool paramsIsValid() override;
};

