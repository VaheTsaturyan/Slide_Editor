#pragma once
#include "types.h"



class AItem{
public:
    explicit AItem(ID id);
    
    AItem(const AItem& other);

    void setGeometry(const sGeometry& geometry);
    sGeometry& getGeometry();
    ID getID() const;
    
    void setAtributs(sAtributs&& atributs);
    sAtributs& getAtributs();
    ~AItem() = default;

private:
    sGeometry geometry_;
    sAtributs atributs_;
    const ID id_;

};
