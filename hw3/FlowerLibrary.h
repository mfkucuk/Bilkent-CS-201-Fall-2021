// Mehmet Feyyaz Küçük 22003550

#include "FlowerList.h"
using namespace std;

#ifndef FLOWERLIBRARY_H
#define FLOWERLIBRARY_H

class FlowerLibrary {
    public:
        FlowerLibrary();
        ~FlowerLibrary();
        
        void addFlower(string name);
        void removeFlower(string name);
        void listFlowers() const;
        void listFeatures(string name) const;
        void addFeature(string name, string feature);
        void removeFeature(string name, string feature);
        void findFlowers(string feature) const;
    private:
        FlowerList flowers;
};

#endif