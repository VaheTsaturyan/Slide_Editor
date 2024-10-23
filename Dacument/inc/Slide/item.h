#pragma once


class Item{
public:
    explicit Item(ID id);
    
    void setGeometry();
    void getGeometry();
    void getID();
    
    virtual void setAtributs() = 0;
    virtual void getAtributs() = 0;
    virtual ~Item() = default;
private:
    const ID id;
    sGeometry geometry;

};

