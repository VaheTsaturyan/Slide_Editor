#pragma once

#include "semanticAnaliz.h"
#include "../../../../Dacument/inc/Slide/types.h"

namespace sem{


class SemanticFactory{
public:
    void registrSemanticAnalizType(std::string str, std::shared_ptr<ISemanticAnalizer> ptr);
    std::shared_ptr<ISemanticAnalizer> getAnilizer(const std::string& optionName);

private:
    std::unordered_map<std::string, std::shared_ptr<ISemanticAnalizer>> anilizers;
};

class IInitilizer{
public:
    virtual sGeometry& getGeometry() = 0;
    virtual sAtributs& getAtributs() = 0;

    virtual void setOptionValueMap(std::shared_ptr<std::unordered_map<Options, Params>> optionsValue) = 0;

    virtual bool initiliz() = 0;    
};

class AInitilizer : public IInitilizer{
public:
    sGeometry& getGeometry() override;
    sAtributs& getAtributs() override;
    virtual bool initiliz() override;    

protected:
    std::shared_ptr<std::unordered_map<Options, Params>> optionsValue_;
    SemanticFactory factory;
    sGeometry geometry_;
    sAtributs atributs_;

};



class ShapeInitilizer : public AInitilizer {
public:
    void setOptionValueMap(std::shared_ptr<std::unordered_map<Options, Params>> optionsValue) override;

};


class TextInitilizer : public AInitilizer{
public:
    void setOptionValueMap(std::shared_ptr<std::unordered_map<Options, Params>> optionsValue) override;

};
    

} // namespace sem
