#pragma once

#include <QPainter>
#include <ostream>

#include "../../Dacument/inc/Slide/slide.h"

class IShape{
public:
    virtual ~IShape() = default;
    virtual void draw(QPainter* painter , const Ithem& ithem) = 0;
    virtual void print(std::ostream& out, const Ithem& ithem) = 0;
    virtual std::shared_ptr<IShape> copy() = 0; 
};

class AShape : public IShape{
protected:
    virtual void setPen(QPainter* painter , const sAtributs& atributs);
    virtual void setBrash(QPainter* painter , const sAtributs& atributs);
};

class RectangleShape : public AShape{
public:    
    void draw(QPainter* painter , const Ithem& ithem);
    void print(std::ostream& out, const Ithem& ithem);
    std::shared_ptr<IShape> copy(); 
};

class ElipsShape : public AShape{
public:    
    void draw(QPainter* painter , const Ithem& ithem);
    void print(std::ostream& out, const Ithem& ithem);
    std::shared_ptr<IShape> copy(); 
};



