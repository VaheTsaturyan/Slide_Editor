#include "circle.h"

/*class Circle : public Item, public ItemVisual{
public:
    Circle(ID n):Item(n){};
    
    
    pair<std::unordered_map<eKeysGeometry, Point>, std::unordered_map<attributes, Color>> reed() override;
    

    void construct(std::unordered_map<eKeysGeometry, Point> Geometry, std::unordered_map<attributes, Color> attribut) override;
    void modify(std::unordered_map<eKeysGeometry, Point> Geometry, std::unordered_map<attributes, Color> attribut) override;


private:
    Center center;
    short radius;
    RGB color;
    Thickness line_Thickness;

enum eKeysGeometry{
    CENTER,
    RADIUS,
    START_POINT,
    END_POINT,
    HEIGHT,
    WIDHTH,
};
enum attributes{
    RED,
    GREEN,
    BLUE,
    LINE_THICKNESS
};

};*/


    
pair<std::unordered_map<eKeysGeometry, Point>, std::unordered_map<eAttributes, Color>> Circle::reed() override{

}


void Circle::construct( std::unordered_map<eKeysGeometry, Point> Geometry, std::unordered_map<eAttributes, Color> attribut ) override{
    modifyGeometry(Geometry);
    modifyAttribut(attribut);
}

void Circle::modifyGeometry( std::unordered_map<eKeysGeometry, Point> Geometry ) override{
    radius = Geometry[eKeysGeometry::RADIUS].x;
    center.x = position.x - radius;
    center.y = position.y - radius;
}

