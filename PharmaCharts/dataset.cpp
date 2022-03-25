#include "dataset.h"

Dataset::Dataset() {}

Dataset::~Dataset() {
    for(auto it=farmaci.begin(); it!=farmaci.end(); ++it)
        delete *it;
}

Farmaco* Dataset::operator[](unsigned int i) const {
    std::vector<Farmaco*>::const_iterator cit = farmaci.begin()+i;
    return *cit;
}

std::vector<Farmaco*>::const_iterator Dataset::begin() const {
    return std::vector<Farmaco*>::const_iterator(farmaci.begin());
}

std::vector<Farmaco*>::const_iterator Dataset::end() const {
    return std::vector<Farmaco*>::const_iterator(farmaci.end());
}

int Dataset::getSize() const {
    return farmaci.size();
}

bool Dataset::isEmpty() const {
    return farmaci.empty();
}

void Dataset::clearAll() {
    for(auto cit = farmaci.begin(); cit!=farmaci.end(); ++cit)
        delete *cit;
    farmaci.clear();
}

void Dataset::insertData(const Farmaco& f) {
    Farmaco* farmaco = const_cast<Farmaco*>(&f);
    farmaci.push_back(farmaco);
}

void Dataset::eraseData(unsigned int i) {
    std::vector<Farmaco*>::iterator it = farmaci.begin()+i;
    if(*it)
        delete *it;
    farmaci.erase(it);
}
