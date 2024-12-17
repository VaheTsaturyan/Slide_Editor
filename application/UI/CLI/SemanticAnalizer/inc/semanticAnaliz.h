#pragma once
#include "../../types.h"
#include "../../../../Dacument/inc/Slide/types.h"

#include <memory>

namespace  sem{
    

class ISemanticAnalizer {
public:
    virtual bool analiz(const Params& param) = 0;
    virtual void initiliz(sGeometry& geometry, sAtributs& atributs ,const Params& param) = 0;
protected:
};


class GeometryIsValid : public ISemanticAnalizer{
public:
    bool analiz(const Params& param) override;
    void initiliz(sGeometry& geometry, sAtributs& atributs ,const Params& param) override;
protected:
};

class XIsValid : public ISemanticAnalizer{
public:
    bool analiz(const Params& param) override;
    void initiliz(sGeometry& geometry, sAtributs& atributs, const Params& param) override;
protected:
};

class YIsValid : public ISemanticAnalizer{
public:
    bool analiz(const Params& param) override;
    void initiliz(sGeometry& geometry, sAtributs& atributs, const Params& param) override;
protected:
};

class LengthIsValid : public ISemanticAnalizer{
public:
    bool analiz(const Params& param) override;
    void initiliz(sGeometry& geometry, sAtributs& atributs, const Params& param) override;
protected:
};

class HeightIsValid : public ISemanticAnalizer{
public:    
    bool analiz(const Params& param) override;
    void initiliz(sGeometry& geometry, sAtributs& atributs, const Params& param) override;
protected:
};


class ColorFillIsValid : public ISemanticAnalizer{
public:
    bool analiz(const Params& param) override;
    void initiliz(sGeometry& geometry, sAtributs& atributs, const Params& param) override;
protected:
};

class ColorPenIsValid : public ISemanticAnalizer{
public:
    bool analiz(const Params& param) override;
    void initiliz(sGeometry& geometry, sAtributs& atributs, const Params& param) override;
protected:
};


class ThicknessIsValid : public ISemanticAnalizer{
public:
    bool analiz(const Params& param) override;
    void initiliz(sGeometry& geometry, sAtributs& atributs, const Params& param) override;
protected:
};

class TypeIsValid : public ISemanticAnalizer{
public:
    void creatTypeMap();
    bool analiz(const Params& param) override;
    void initiliz(sGeometry& geometry, sAtributs& atributs, const Params& param) override;
protected:
    std::unordered_map<std::string, std::string> typeMap;
};



} // namespace  sem