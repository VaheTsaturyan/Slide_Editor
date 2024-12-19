#include "Sterializer.h"

#include <fstream>
#include <memory>

Sterializer &Sterializer::getSterilizer(){
    static Sterializer sterilizer;
    return sterilizer; 
}

void Sterializer::save(const std::string &path, std::shared_ptr<Slide> slide){
    
    boost::json::array jsonArray;

    for (auto page : *slide) {
        jsonArray.push_back(pageToJson(page));
    }

    std::string jsonString = boost::json::serialize(jsonArray);

    std::ofstream outFile(path);
    outFile << jsonString;
    outFile.close();
}

std::shared_ptr<Slide> Sterializer::open(const std::string &path){
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::string json_str((std::istreambuf_iterator<char>(file)),
                          std::istreambuf_iterator<char>());
    file.close();

    boost::json::value jv = boost::json::parse(json_str);
    boost::json::array json_array = jv.as_array();

    std::shared_ptr<Slide> slide = std::make_shared<Slide>();

    for (const auto& inner_array : json_array) {

        std::shared_ptr<Page> page  = std::make_shared<Page>();

        for (const auto& itemObj : inner_array.as_array()) {
            std::shared_ptr<Ithem> ithem = jsonToItem(itemObj.as_object());
            page->addIthem(*ithem);
        }
        slide->pushBackPage(page);
    }

    return slide;
}



boost::json::object Sterializer::pageToJson(std::shared_ptr<Page> page){
    
    boost::json::object jsonObj;
    boost::json::array itemArr;
    
    for (auto el : *page) {
        itemArr.push_back(itemToJson(el.second));
    }

    jsonObj["items"] = itemArr;
    return jsonObj;

}


boost::json::object Sterializer::itemToJson(const Ithem& item){
    boost::json::object jsonObj;

    jsonObj["id"] = item.getID();
    jsonObj["type"] = item.getType();

    boost::json::object geoObj;
    geoObj["x"] = item.getGeometry().x;
    geoObj["y"] = item.getGeometry().y;
    geoObj["len"] = item.getGeometry().len;
    geoObj["hig"] = item.getGeometry().hig;

    jsonObj["geometry"] = geoObj;

    boost::json::object atrObj;
    for (const auto& atr : item.getAtributs().map) {
        atrObj.emplace(atr.first, atr.second);
    }
    jsonObj["attributes"] = atrObj;

    return jsonObj;    
}


std::shared_ptr<Page> Sterializer::jsonToPage(const boost::json::object &obj){
    auto page = std::make_shared<Page>(); 

    boost::json::array itemsArray = obj.at("items").as_array(); 
    
    for (const auto& itemObjj : itemsArray) {

        page->addIthem(*(jsonToItem(itemObjj.as_object())));
    }

    return page;
}

std::shared_ptr<Ithem> Sterializer::jsonToItem(const boost::json::object &obj){

    int id = obj.at("id").as_int64(); 

    sGeometry geometry;
    sAtributs atributs;

    boost::json::object geometryObj = obj.at("geometry").as_object();
    geometry.x = geometryObj.at("x").as_int64();
    geometry.y = geometryObj.at("y").as_int64();
    geometry.len = geometryObj.at("len").as_int64();
    geometry.hig = geometryObj.at("hig").as_int64();

    boost::json::object atributsObj = obj.at("attributes").as_object();
    
    for (const auto& atr : atributsObj) {
        atributs.map.emplace(atr.key(), atr.value().as_string());
    }

    std::shared_ptr<Ithem> ithem = std::make_shared<Ithem>(id);
    ithem->setGeometry(geometry);
    ithem->setAtributs(std::move(atributs));
    return ithem;
}

/*
void Serializer::save(const std::string& path, std::shared_ptr<Document> doc){

    boost::json::array jsonArray;

    for (const auto& slide : doc->get_slides()) {
        jsonArray.push_back(slide_to_json(slide));
    }

    std::string jsonString = boost::json::serialize(jsonArray);

    std::ofstream outFile(path);
    outFile << jsonString;
    outFile.close();
}



std::shared_ptr<Document> Serializer::load(const std::string& path, std::shared_ptr<Document> doc){
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::string json_str((std::istreambuf_iterator<char>(file)),
                          std::istreambuf_iterator<char>());
    file.close();

    boost::json::value jv = boost::json::parse(json_str);
    boost::json::array json_array = jv.as_array();


    for (const auto& inner_array : json_array) {

        std::shared_ptr<Slide> slide  = std::make_shared<Slide>();

        for (const auto& item_obj : inner_array.as_array()) {
            std::shared_ptr<Item> item = json_to_item(item_obj.as_object());
            slide->add_shape(item);
        }
        doc->add_slide(slide);
    }

    return doc;
}


boost::json::object Serializer::slide_to_json(std::shared_ptr<Slide> slide ){
    boost::json::object jsonObj;

    jsonObj["name"] = slide->get_name();
    jsonObj["index"] = slide->get_index();

    boost::json::array itemArr;
    for (auto item : slide->get_content()) {
        itemArr.push_back(item_to_json(item));
    }
    jsonObj["items"] = itemArr;

    return jsonObj;
}


std::shared_ptr<Slide> Serializer::json_to_slide(const boost::json::object& obj) {
    std::unordered_map<std::string, Serializer::Variant> attributes;

    attributes["name"] = obj.at("name").as_string().data(); 
    attributes["index"] = obj.at("index").as_string().data(); 

    auto slide = std::make_shared<Slide>(attributes); 

    boost::json::array items_array = obj.at("items").as_array(); 
    for (const auto& item_obj : items_array) { 

        slide->add_shape(json_to_item(item_obj.as_object()));
    }

    return slide;
}

boost::json::object Serializer::item_to_json(std::shared_ptr<Item> item) {
    boost::json::object jsonObj;

    jsonObj["type"] = item->get_type();

    boost::json::object geoObj;
    geoObj["x"] = item->get_geometry()._x;
    geoObj["y"] = item->get_geometry()._y;
    geoObj["length"] = item->get_geometry()._length;
    geoObj["width"] = item->get_geometry()._width;

    jsonObj["geometry"] = geoObj;

    boost::json::object attrObj;
    for (const auto& attr : item->get_atributes()) {
        if (std::holds_alternative<std::string>(attr.second)) {
            attrObj[attr.first] = boost::json::value_from(std::get<std::string>(attr.second));
        } else if (std::holds_alternative<double>(attr.second)) {
            attrObj[attr.first] = boost::json::value_from(std::get<double>(attr.second));
        } else if (std::holds_alternative<int>(attr.second)) {
            attrObj[attr.first] = boost::json::value_from(std::get<int>(attr.second));
        }
    }
    jsonObj["attributes"] = attrObj;

    return jsonObj;
}



std::shared_ptr<Item> Serializer::json_to_item(const boost::json::object& obj) {
    std::unordered_map<std::string, Item::Variant> attributes;

    std::string type = obj.at("type").as_string().data(); 

    Item::SItemGeometry geometry;
    boost::json::object geoObj = obj.at("geometry").as_object();
    geometry.set_params(geoObj.at("x").as_int64(), geoObj.at("y").as_int64(), geoObj.at("length").as_int64(), geoObj.at("width").as_int64());

    boost::json::object attrObj = obj.at("attributes").as_object();
    for (const auto& attr : attrObj) {
        std::string key = std::string(attr.key().data());  
        if (attr.value().is_string()) {
            attributes[key] = std::string(attr.value().as_string().data());  
        } else if (attr.value().is_double()) {
            attributes[key] = attr.value().as_double();  
        } else if (attr.value().is_int64()) {
            attributes[key] = static_cast<int>(attr.value().as_int64());  
        }
    }

    std::shared_ptr<Item> item = std::make_shared<Item>(type, geometry, attributes);

    return item;
}
*/