#pragma once

#include "semanticAnaliz.h"
#include "../../../../Dacument/inc/Slide/types.h"

namespace sem{


    class SemanticFactory{
public:
    void registrSemanticAnalizType();
    std::shared_ptr<ISemanticAnalizer> getAnilizer(const std::string& optionName);

private:
    std::unordered_map<std::string, std::shared_ptr<ISemanticAnalizer>> anilizers;
};


class ShapeInitilizer{
public:
    sGeometry& getGeometry();
    sAtributs& getAtributs();

    void setOptionValueMap(std::shared_ptr<std::unordered_map<Options, Params>> optionsValue);

    bool initiliz();

private:
    std::shared_ptr<std::unordered_map<Options, Params>> optionsValue_;
    SemanticFactory factory;
    sGeometry geometry_;
    sAtributs atributs_;

};


    

} // namespace sem
