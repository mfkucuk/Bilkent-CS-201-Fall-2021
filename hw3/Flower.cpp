// Mehmet Feyyaz Küçük 22003550

#include "Flower.h"
using namespace std;

Flower::Flower() {
    size = 0;
    flowerName = "";
    head = NULL;
}

Flower::Flower(string flowerName) {
    size = 0;
    this->flowerName = flowerName;
    head = NULL;
}

Flower::Flower(const Flower& aFlower) {
    size = aFlower.size;
    flowerName = aFlower.flowerName;
    head = NULL;

    FeatureNode* tail;
    for (FeatureNode* cur = aFlower.head; cur != NULL; cur = cur->next) {
        FeatureNode* newPtr = new FeatureNode;
        newPtr->feature = cur->feature;
        if (head == NULL) {
            head = newPtr;
        }
        else {
            tail->next = newPtr;
        }
        tail = newPtr;
    }
}

Flower::~Flower() {
    FeatureNode* temp;
    while (size > 0) {
        temp = head;
        head = temp->next;
        delete temp;
        size--;
    }
}

bool Flower::isEmpty() const {
    return size == 0;
}

int Flower::getLength() const {
    return size;
}

bool Flower::add(string feature) {
    FeatureNode* newPtr = new FeatureNode;
    newPtr->feature = feature;
    newPtr->next = NULL;

    if (head == NULL) {
        newPtr->next = head;
        head = newPtr;
        size++;
        return true;
    }

    FeatureNode* prev = head;
    FeatureNode* cur;
    for (cur = head; cur != NULL; cur = cur->next) {
        if (feature == cur->feature) {
            delete newPtr;
            return false;
        }

        if (feature < cur->feature) {
            if (cur == head) {
                newPtr->next = head;
                head = newPtr;
            }
            else {
                newPtr->next = prev->next;
                prev->next = newPtr;
                
            }
            size++;
            return true;
        }
        prev = cur;
    }

    newPtr->next = prev->next;
    prev->next = newPtr;
    size++;
    return true;
}

bool Flower::remove(string feature) {
    FeatureNode* prev = NULL;
    for (FeatureNode* cur = head; cur != NULL; cur = cur->next) {
        if (feature == cur->feature) {
            if (cur == head) {
                head = cur->next;
                delete cur;
            }
            else {
                prev->next = cur->next;
                delete cur;
            }
            size--;
            return true;
        }
        prev = cur;
    }

    return false; 
}

string Flower::printFlower() const {
    string result;
    result = flowerName + ": ";
    if (isEmpty()) {
        result += "No feature";
    }
    else {
        for (FeatureNode* cur = head; cur != NULL; cur = cur->next) {
            if (cur->next == NULL) {
                result += cur->feature;
            }
            else {
                result += cur->feature + ", ";
            }
        }
    }
    
    return result;
}

string Flower::getFlowerName() const {
    return flowerName;
}

void Flower::setFlowerName(string flowerName) {
    this->flowerName = flowerName;
} 

void Flower::initFlower(const Flower& other) {
    size = other.size;
    flowerName = other.flowerName;
    head = NULL;

    FeatureNode* tail;
    for (FeatureNode* cur = other.head; cur != NULL; cur = cur->next) {
        FeatureNode* newPtr = new FeatureNode;
        newPtr->feature = cur->feature;
        newPtr->next = NULL;
        if (head == NULL) {
            head = newPtr;
        }
        else {
            tail->next = newPtr;
        }
        tail = newPtr;
    }
}

bool Flower::findFeature(string feature) const {
    for (FeatureNode* cur = head; cur != NULL; cur = cur->next) {
        if (feature == cur->feature) {
            return true;
        }
    }

    return false;
}

void Flower::removeAllFeatures() {
    FeatureNode* temp;
    while (size > 0) {
        temp = head;
        head = temp->next;
        delete temp;
        size--;
    } 
}