#include "../inc/semanticFactory.h"


#include "../../../../Dacument/inc/Slide/types.h"

#include <unordered_map>
#include <stdexcept>

namespace sem
{
    

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SemanticFactory::registrSemanticAnalizType(){
    anilizers.emplace("geometry", std::make_shared<GeometryIsValid>());
    anilizers.emplace("g", std::make_shared<GeometryIsValid>());
    anilizers.emplace("x", std::make_shared<XIsValid>());
    anilizers.emplace("y", std::make_shared<YIsValid>());
    anilizers.emplace("l", std::make_shared<LengthIsValid>());
    anilizers.emplace("length", std::make_shared<LengthIsValid>());
    anilizers.emplace("h", std::make_shared<HeightIsValid>());
    anilizers.emplace("height", std::make_shared<HeightIsValid>());
    anilizers.emplace("type", std::make_shared<TypeIsValid>());
    anilizers.emplace("t", std::make_shared<TypeIsValid>());
    anilizers.emplace("thickness", std::make_shared<ThicknessIsValid>());
    anilizers.emplace("thc", std::make_shared<ThicknessIsValid>());
    anilizers.emplace("color", std::make_shared<ColorIsValid>());
    anilizers.emplace("c", std::make_shared<ColorIsValid>());

}

std::shared_ptr<ISemanticAnalizer> SemanticFactory::getAnilizer(const std::string& optionName){
    auto el = anilizers.find(optionName);
    if(el != anilizers.end()){
        return el->second;
    }
    throw std::runtime_error("wrong option\n");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
sGeometry &ShapeInitilizer::getGeometry(){
    return geometry_;
}

sAtributs &ShapeInitilizer::getAtributs(){
    return atributs_;
}

void ShapeInitilizer::setOptionValueMap(std::shared_ptr<std::unordered_map<Options, Params>> optionsValue){
    this->factory.registrSemanticAnalizType();
    optionsValue_ = optionsValue;
}

bool ShapeInitilizer::initiliz(){
    for(auto el : (*optionsValue_)){
        std::shared_ptr<ISemanticAnalizer> anilizer = factory.getAnilizer(el.first);
        if(anilizer->analiz(el.second)){
            anilizer->initiliz(geometry_, atributs_, el.second);
        }else{
            return false;
        }
    }
    return true;
}

} // namespace sem