#pragma once

#include "types.h"
#include "../../Dacument/inc/dacumet.h"

#include <vector>
#include <memory>

using Comand = std::string;

struct Params{
    std::vector<number> integerArguments;
    std::vector<word> stringArguments;
}; 


class AComand{
public:
    virtual ~AComand() = default;
    virtual void execute(std::sharide_ptr<Slide_Collection> sldColection) = 0;
    void setParams(Params&& params);
    const Params& getParams() const;
protected:
    virtual bool paramsIsValid() = 0;
private:
    Params params;
};

class NewComand : public AComand{
public:
    void execute(std::shared_ptr<Slide_Collection> sldColection) override;
protected:
    bool paramsIsValid() override;
};


class AddSlide : public AComand{
public:
    void execute(std::shared_ptr<Slide_Collection> sldColection) override;
protected:
    bool paramsIsValid() override;

};
