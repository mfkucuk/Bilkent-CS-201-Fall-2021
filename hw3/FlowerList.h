// Mehmet Feyyaz Küçük 22003550

#include "Flower.h"
using namespace std;

#ifndef FLOWERLIST_H
#define FLOWERLIST_H

class FlowerList {
    public:
        FlowerList();
        FlowerList(const FlowerList& aList);
        ~FlowerList();
        
        bool isEmpty() const;
        int getLength() const;
        bool retrieve(string flowerName, Flower& flower) const;
        bool add(string flowerName);
        bool remove(string flowerName);
        string printFlowers() const;
        string findFlowers(string feature) const;
        void addFeature(string flowerName, string feature);
        void removeFeature(string flowerName, string feature);
        FlowerList& operator=(const FlowerList& other);
    private:
        struct FlowerNode {
            Flower f;
            FlowerNode* next;
        };
        int size;
        FlowerNode* head; 
};

#endif
