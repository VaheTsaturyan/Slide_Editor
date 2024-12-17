#include "../inc/semanticAnaliz.h"

#include <unordered_map>
#include <stdexcept>


namespace sem
{
    

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool GeometryIsValid::analiz(const Params& param){
    return (param.vectorInteger.size() == 4 && param.vectorString.empty());
}
void GeometryIsValid::initiliz(sGeometry &geometry, sAtributs &atributs, const Params &param){
    geometry.x = param.vectorInteger[0];
    geometry.y = param.vectorInteger[1];
    geometry.len = param.vectorInteger[2];
    geometry.hig = param.vectorInteger[3];
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool XIsValid::analiz(const Params &param){
    return (param.vectorInteger.size() == 1 && param.vectorString.empty());
}

void XIsValid::initiliz(sGeometry &geometry, sAtributs &atributs, const Params &param){
    geometry.x = param.vectorInteger.front();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool YIsValid::analiz(const Params& param){
    return ( param.vectorInteger.size() == 1 && param.vectorString.empty());
}

void YIsValid::initiliz(sGeometry &geometry, sAtributs &atributs, const Params &param){
    geometry.y = param.vectorInteger.front();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool LengthIsValid::analiz(const Params& param){
    return(param.vectorInteger.size() == 1 && param.vectorString.empty());
}

void LengthIsValid::initiliz(sGeometry &geometry, sAtributs &atributs, const Params &param){
    geometry.len = param.vectorInteger.front();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool HeightIsValid::analiz(const Params& param){
    return(param.vectorInteger.size() == 1 && param.vectorString.empty());
}

void HeightIsValid::initiliz(sGeometry &geometry, sAtributs &atributs, const Params &param){
    geometry.hig = param.vectorInteger.front();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ColorFillIsValid::analiz(const Params& param){
    if(param.vectorInteger.size() == 3 && param.vectorString.empty()){
        return true;
    } else if(param.vectorString.size() == 1 && param.vectorInteger.empty()){
        return true;
    }
    return false;
}

void ColorFillIsValid::initiliz(sGeometry &geometry, sAtributs &atributs, const Params &param){
    if(param.vectorString.empty()){
        color::sColor color(param.vectorInteger[0], param.vectorInteger[1], param.vectorInteger[2]);
        std::string temp;
        temp.push_back(color.red);
        temp.push_back(color.green);
        temp.push_back(color.blue);
        atributs.map.emplace(std::string("colorfill"), temp);
    }else{
        std::unordered_map<std::string, color::sColor> colorMap;
        colorMap.emplace(std::string("black"), color::BLACK);
        colorMap.emplace(std::string("blue"), color::BLUE);
        colorMap.emplace(std::string("green"), color::GREEN);
        colorMap.emplace(std::string("red"), color::RED);
        auto el = colorMap.find(param.vectorString.front());
        if(el == colorMap.end()){
            throw std::runtime_error("The color you specified is not among the built-in colors, please import it in RGB format\n");
        }    
        std::string temp;
        temp.push_back(el->second.red);
        temp.push_back(el->second.green);
        temp.push_back(el->second.blue);
        atributs.map.emplace(std::string("colorfill"), temp);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ColorPenIsValid::analiz(const Params& param){
    if(param.vectorInteger.size() == 3 && param.vectorString.empty()){
        return true;
    } else if(param.vectorString.size() == 1 && param.vectorInteger.empty()){
        return true;
    }
    return false;
}

void ColorPenIsValid::initiliz(sGeometry &geometry, sAtributs &atributs, const Params &param){
    if(param.vectorString.empty()){
        color::sColor color(param.vectorInteger[0], param.vectorInteger[1], param.vectorInteger[2]);
        std::string temp;
        temp.push_back(color.red);
        temp.push_back(color.green);
        temp.push_back(color.blue);
        atributs.map.emplace(std::string("colorpen"), temp);
    }else{
        std::unordered_map<std::string, color::sColor> colorMap;
        colorMap.emplace(std::string("black"), color::BLACK);
        colorMap.emplace(std::string("blue"), color::BLUE);
        colorMap.emplace(std::string("green"), color::GREEN);
        colorMap.emplace(std::string("red"), color::RED);
        auto el = colorMap.find(param.vectorString.front());
        if(el == colorMap.end()){
            throw std::runtime_error("The color you specified is not among the built-in colors, please import it in RGB format\n");
        }    
        std::string temp;
        temp.push_back(el->second.red);
        temp.push_back(el->second.green);
        temp.push_back(el->second.blue);
        atributs.map.emplace(std::string("colorpen"), temp);
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ThicknessIsValid::analiz(const Params& param){
    return (param.vectorInteger.size() == 1 && param.vectorInteger.front() < 255 && param.vectorString.empty());
}

void ThicknessIsValid::initiliz(sGeometry &geometry, sAtributs &atributs, const Params &param){
    atributs.map.emplace(std::string("thickness"), std::to_string(param.vectorInteger.front()));
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TypeIsValid::creatTypeMap(){
    typeMap.emplace(std::string("rectangle"), std::string("rectangle"));
    typeMap.emplace(std::string("r"), std::string("rectangle"));
    typeMap.emplace(std::string("elips"), std::string("elips"));
    typeMap.emplace(std::string("e"), std::string("elips"));
    typeMap.emplace(std::string("line"), std::string("line"));
    typeMap.emplace(std::string("l"), std::string("line"));
}

bool TypeIsValid::analiz(const Params &param){
    creatTypeMap();
    if(param.vectorString.size() == 1 && param.vectorInteger.empty()){
        if(typeMap.find(param.vectorString.front()) != typeMap.end()){
            return true;
        }
        throw std::runtime_error("incomprehensible type\n");
    }
    return false;
}

void TypeIsValid::initiliz(sGeometry &geometry, sAtributs &atributs, const Params &param){
    atributs.map.emplace("type", typeMap[param.vectorString.front()]);
}


} // namespace sem