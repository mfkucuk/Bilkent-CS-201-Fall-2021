// Mehmet Feyyaz Küçük 22003550

#include <iostream>
#include "FlowerLibrary.h"
using namespace std;

FlowerLibrary::FlowerLibrary() {
    flowers = FlowerList();
}

FlowerLibrary::~FlowerLibrary() {
    
}

void FlowerLibrary::addFlower(string name) {
    for (int i = 0; i < name.length(); i++) {
        if (name[i] < 97 && name[i] != 32) {
            name[i] += 32;
        }
    }

    if (flowers.add(name)) {
        cout << name << " has been added into the library." << endl;
    }
    else {
        cout << name << " cannot be added into the library because it already exists." << endl;
    }
}

void FlowerLibrary::removeFlower(string name) {
    for (int i = 0; i < name.length(); i++) {
        if (name[i] < 97 && name[i] != 32) {
            name[i] += 32;
        }
    }

    if (flowers.remove(name)) {
        cout << name << " has been removed from the library." << endl;
    }
    else {
        cout << name << " cannot be removed because it's not in the library." << endl;
    }
}

void FlowerLibrary::listFlowers() const {
    if (flowers.isEmpty()) {
        cout << "Library is empty." << endl;
        return;
    }

    cout << flowers.printFlowers() << endl;
}

void FlowerLibrary::listFeatures(string name) const {
    for (int i = 0; i < name.length(); i++) {
        if (name[i] < 97 && name[i] != 32) {
            name[i] += 32;
        }
    }

    Flower f;
    if (flowers.retrieve(name, f)) {
        cout << f.printFlower() << endl;
    }
    else {
        cout << name << " isn't found in the library." << endl;
    }
}

void FlowerLibrary::addFeature(string name, string feature) {
    for (int i = 0; i < name.length(); i++) {
        if (name[i] < 97 && name[i] != 32) {
            name[i] += 32;
        }
    }

    for (int i = 0; i < feature.length(); i++) {
        if (feature[i] < 97 && feature[i] != 32) {
            feature[i] += 32;
        }
    }

    flowers.addFeature(name, feature);
}

void FlowerLibrary::removeFeature(string name, string feature) {
    for (int i = 0; i < name.length(); i++) {
        if (name[i] < 97 && name[i] != 32) {
            name[i] += 32;
        }
    }

    for (int i = 0; i < feature.length(); i++) {
        if (feature[i] < 97 && feature[i] != 32) {
            feature[i] += 32;
        }
    }

    flowers.removeFeature(name, feature);
}

void FlowerLibrary::findFlowers(string feature) const {
    for (int i = 0; i < feature.length(); i++) {
        if (feature[i] < 97 && feature[i] != 32) {
            feature[i] += 32;
        }
    }

    cout << flowers.findFlowers(feature) << endl;
}