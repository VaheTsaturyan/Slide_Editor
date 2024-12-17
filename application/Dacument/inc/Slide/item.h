#pragma once
#include "types.h"



class Ithem{
public:
    explicit Ithem(ID id);
    
    Ithem(const Ithem& other);
    ~Ithem() = default;

    void setGeometry(const sGeometry& geometry);
    void setAtributs(sAtributs&& atributs);

    const sGeometry& getGeometry() const ;
    const sAtributs& getAtributs() const ;
    const std::string& getType() const;

    sGeometry& getGeometry();
    sAtributs& getAtributs();
    std::string& getType();

    ID getID() const;

private:
    sGeometry geometry_;
    sAtributs atributs_;
    const ID id_;
};
