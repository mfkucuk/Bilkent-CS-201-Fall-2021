// Mehmet Feyyaz Küçük 22003550

#include <iostream>
#include "FlowerList.h"
using namespace std;

FlowerList::FlowerList() {
    size = 0;
    head = NULL;
}

FlowerList::FlowerList(const FlowerList& aList) {
    size = aList.size;
    head = NULL;

    FlowerNode* tail;
    for (FlowerNode* cur = aList.head; cur != NULL; cur = cur->next) {
        FlowerNode* newPtr = new FlowerNode;
        newPtr->f.initFlower(cur->f);
        if (head == NULL) {
            head = newPtr;
        }
        else {
            tail->next = newPtr;
        }
        tail = newPtr;
    }
}

FlowerList::~FlowerList() {
    FlowerNode* temp;
    while (size > 0) {
        temp = head;
        head = temp->next;
        delete temp;
        size--;
    }
}

bool FlowerList::isEmpty() const {
    return size == 0;
}

int FlowerList::getLength() const {
    return size;
}

bool FlowerList::retrieve(string flowerName, Flower& flower) const {
    for (FlowerNode* cur = head; cur != NULL; cur = cur->next) {
        if (flowerName == cur->f.getFlowerName()) {
            flower.initFlower(cur->f);
            return true;
        }
    }

    return false;
}

bool FlowerList::add(string flowerName) {
    FlowerNode* newPtr = new FlowerNode;
    newPtr->f.setFlowerName(flowerName);
    newPtr->next = NULL;

    if (head == NULL) {
        newPtr->next = head;
        head = newPtr;
        size++;
        return true;
    }

    FlowerNode* prev = head;
    FlowerNode* cur;
    for (cur = head; cur != NULL; cur = cur->next) {
        if (flowerName == cur->f.getFlowerName()) {
            delete newPtr;
            return false;
        }

        if (flowerName < cur->f.getFlowerName()) {
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

bool FlowerList::remove(string flowerName) {

    for (FlowerNode* cur = head; cur != NULL; cur = cur->next) {
        if (flowerName == cur->f.getFlowerName()) {
            cur->f.removeAllFeatures();
        }
    }

    FlowerNode* prev = NULL;
    for (FlowerNode* cur = head; cur != NULL; cur = cur->next) {
        if (flowerName == cur->f.getFlowerName()) {
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

string FlowerList::printFlowers() const {
    string result;

    for (FlowerNode* cur = head; cur != NULL; cur = cur->next) {
        result += cur->f.printFlower() + "\n";
    }

    return result;
}

string FlowerList::findFlowers(string feature) const {
    string result = feature + " flowers: ";

    for (FlowerNode* cur = head; cur != NULL; cur = cur->next) {
        if (cur->f.findFeature(feature)) {
            result += cur->f.getFlowerName() + ", ";
        }
    }

    if (result == feature + " flowers: ") {
        result += "there is no such flower";
    }
    else {

        // Delete the comma in the end.
        result[result.length() - 2] = 32;
    }

    return result;
}

void FlowerList::addFeature(string name, string feature) {
    for (FlowerNode* cur = head; cur != NULL; cur = cur->next) {
        if (name == cur->f.getFlowerName()) {
            if (cur->f.add(feature)) {
                cout << feature << " is added into " << name << endl;
            }
            else {
                cout << feature << " already exists in " << name << endl;
            }
            return;
        }
    }

    cout << name << " isn't found in the library." << endl;
}

void FlowerList::removeFeature(string name, string feature) {
    for (FlowerNode* cur = head; cur != NULL; cur = cur->next) {
        if (name == cur->f.getFlowerName()) {
            if (cur->f.remove(feature)) {
                cout << feature << " is removed from " << name << endl;
            }
            else {
                cout << feature << " doesn't exist in " << name << endl;
            }
            return;
        }
    }

    cout << name << " isn't found in the library." << endl;
}

FlowerList& FlowerList::operator=(const FlowerList& other) {
    size = other.size;
    head = NULL;

    FlowerNode* tail;
    for (FlowerNode* cur = other.head; cur != NULL; cur = cur->next) {
        FlowerNode* newPtr = new FlowerNode;
        newPtr->f = cur->f;
        if (head == NULL) {
            head = newPtr;
        }
        else {
            tail->next = newPtr;
        }
        tail = newPtr;
    }

    return *this;
}