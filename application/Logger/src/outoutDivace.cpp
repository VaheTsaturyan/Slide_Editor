#include "../inc/outoutDivace.h"

OstreamDivace::OstreamDivace(std::ostream &out) : out(out){
}

void OstreamDivace::print(const std::string& str){
    out<<str;
}