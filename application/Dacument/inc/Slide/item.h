#pragma once
#include "types.h"



class Ithem{
public:
    explicit Ithem(ID id);
    
    Ithem(const Ithem& other);

    void setGeometry(const sGeometry& geometry);
    sGeometry& getGeometry();
    ID getID() const;
    
    void setAtributs(sAtributs&& atributs);
    sAtributs& getAtributs();
    ~Ithem() = default;

private:
    sGeometry geometry_;
    sAtributs atributs_;
    const ID id_;

};
