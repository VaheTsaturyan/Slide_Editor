#include "../inc/semanticFactory.h"


#include "../../../../Dacument/inc/Slide/types.h"

#include <unordered_map>
#include <stdexcept>
#include <iostream>

namespace sem
{
    
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SemanticFactory::registrSemanticAnalizType(std::string str, std::shared_ptr<ISemanticAnalizer> ptr){
    anilizers.emplace(str, ptr);
}

std::shared_ptr<ISemanticAnalizer> SemanticFactory::getAnilizer(const std::string& optionName){
    auto el = anilizers.find(optionName);
    if(el != anilizers.end()){
        return el->second;
    }
    throw std::runtime_error("wrong option\n");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
sGeometry &AInitilizer::getGeometry(){
    return geometry_;
}

sAtributs &AInitilizer::getAtributs(){
    return atributs_;
}

bool AInitilizer::initiliz(){
    for(auto el : optionsValue_.operator*()){
        std::shared_ptr<ISemanticAnalizer> anilizer = factory.getAnilizer(el.first);
        if(anilizer->analiz(el.second)){
            anilizer->initiliz(geometry_, atributs_, el.second);
        }else{
            return false;
        }
    }
    return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ShapeInitilizer::setOptionValueMap(std::shared_ptr<std::unordered_map<Options, Params>> optionsValue){
    this->optionsValue_ = optionsValue;
    factory.registrSemanticAnalizType("geometry", std::make_shared<GeometryIsValid>());
    factory.registrSemanticAnalizType("g", std::make_shared<GeometryIsValid>());
    factory.registrSemanticAnalizType("x", std::make_shared<XIsValid>());
    factory.registrSemanticAnalizType("y", std::make_shared<YIsValid>());
    factory.registrSemanticAnalizType("l", std::make_shared<LengthIsValid>());
    factory.registrSemanticAnalizType("length", std::make_shared<LengthIsValid>());
    factory.registrSemanticAnalizType("h", std::make_shared<HeightIsValid>());
    factory.registrSemanticAnalizType("height", std::make_shared<HeightIsValid>());
    factory.registrSemanticAnalizType("type", std::make_shared<TypeIsValid>());
    factory.registrSemanticAnalizType("t", std::make_shared<TypeIsValid>());
    factory.registrSemanticAnalizType("thickness", std::make_shared<ThicknessIsValid>());
    factory.registrSemanticAnalizType("thc", std::make_shared<ThicknessIsValid>());
    factory.registrSemanticAnalizType("colorfill", std::make_shared<ColorFillIsValid>());
    factory.registrSemanticAnalizType("cf", std::make_shared<ColorFillIsValid>());
    factory.registrSemanticAnalizType("colorpen", std::make_shared<ColorPenIsValid>());
    factory.registrSemanticAnalizType("cp", std::make_shared<ColorPenIsValid>());
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TextInitilizer::setOptionValueMap(std::shared_ptr<std::unordered_map<Options, Params>> optionsValue){
    optionsValue_ = optionsValue;
    factory.registrSemanticAnalizType("x", std::make_shared<XIsValid>());
    factory.registrSemanticAnalizType("y", std::make_shared<YIsValid>());
    factory.registrSemanticAnalizType("text", std::make_shared<TextIsValid>());
    factory.registrSemanticAnalizType("t", std::make_shared<TextIsValid>());
    factory.registrSemanticAnalizType("thickness", std::make_shared<ThicknessIsValid>());
    factory.registrSemanticAnalizType("thc", std::make_shared<ThicknessIsValid>());
    factory.registrSemanticAnalizType("colorfill", std::make_shared<ColorFillIsValid>());
    factory.registrSemanticAnalizType("cf", std::make_shared<ColorFillIsValid>());
    factory.registrSemanticAnalizType("colorpen", std::make_shared<ColorPenIsValid>());
    factory.registrSemanticAnalizType("cp", std::make_shared<ColorPenIsValid>());

}



} // namespace sem