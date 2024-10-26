#pragma once


class AItem{
public:
    explicit Atem(ID id);
    
    void setGeometry(const sGeometry& geometry);
    sGeometry& getGeometry() const;
    id getID() const;
    
    //virtual void setAtributs() = 0;
    //virtual void getAtributs() = 0;
    virtual ~AItem() = default;
private:
    const ID id_;
    sGeometry geometry_;

};

class Rectangle : public AItem {

};
