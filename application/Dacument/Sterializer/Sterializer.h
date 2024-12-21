#pragma once

#include "../inc/Slide/slide.h"

#include <boost/json.hpp>

class Sterializer{
public:
    Sterializer() = default;
    void save( const std::string& path, std::shared_ptr<Slide> slide );
    std::shared_ptr<Slide> open(const std::string& path);

private:
    boost::json::object itemToJson(const Ithem& item);
    std::shared_ptr<Ithem> jsonToItem(const boost::json::object& obj);

    boost::json::object pageToJson(std::shared_ptr<Page> slide);
    void jsonToPage(const boost::json::object& obj, std::shared_ptr<Page> page);

private:

};


/*class Serializer {
public: 
    using Variant = std::variant<std::string, double, int>;

public:
    Serializer() = default;
    ~Serializer() = default;
    

private:
};
*/