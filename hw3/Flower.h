// Mehmet Feyyaz Küçük 22003550

#include <string>
using namespace std;

#ifndef FLOWER_H
#define FLOWER_H

class Flower {
    public:
        Flower();
        Flower(string flowerName);
        Flower(const Flower& aFlower);
        ~Flower();
        
        bool isEmpty() const;
        int getLength() const ;
        bool add(string feature);
        bool remove(string feature);
        string printFlower() const;
        string getFlowerName() const;
        void setFlowerName(string flowerName);
        void initFlower(const Flower& other);
        bool findFeature(string feature) const;
        void removeAllFeatures();
    private:
        struct FeatureNode {
            string feature;
            FeatureNode* next;
        };
        int size;
        string flowerName;
        FeatureNode *head; 
};

#endif
