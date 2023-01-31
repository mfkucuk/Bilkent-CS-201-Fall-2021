// Mehmet Feyyaz Küçük 22003550

using namespace std;

#include "Chemical.h"

Chemical::Chemical() {
    type = '+';
    id = -1;
    location = "";
}

Chemical::~Chemical() {
    
}

void Chemical::initChemical(const Chemical &other) {
    this->type = other.type;
    this->id = other.id;
    this->location = other.location;
}

void Chemical::initChemical(char type, int id, string location) {
    this->type = type;
    this->id = id;
    this->location = location;
}