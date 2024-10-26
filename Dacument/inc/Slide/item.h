#pragma once
#include "types.h"

class AItem{
public:
    explicit AItem(ID id);
    
    void setGeometry(const sGeometry& geometry);
    sGeometry& getGeometry();
    ID getID() const;
    
    //virtual void setAtributs() = 0;
    //virtual void getAtributs() = 0;
    virtual ~AItem() = default;
private:
    const ID id_;
    sGeometry geometry_;

};

class Rectangle : public AItem {
public:
    explicit Rectangle(ID id);
};
