#pragma once
#include "types.h"

class AItem{
public:

    explicit AItem(ID id);
    
    void setGeometry(const sGeometry& geometry);
    sGeometry& getGeometry();
    ID getID() const;
    
    void setAtributs(sAtributs&& atributs);
    sAtributs& getAtributs();
    ~AItem() = default;

private:

    const ID id_;
    sGeometry geometry_;
    sAtributs atributs_;

};
