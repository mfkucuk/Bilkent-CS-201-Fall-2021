// Mehmet Feyyaz Küçük 22003550

#ifndef CABINET_H
#define CABINET_H

using namespace std;

#include "Chemical.h"

class Cabinet {
    public:
        Cabinet();
        ~Cabinet();
        void initCabinet(int id, int rows, int columns);
        void initShelves(const Cabinet &other);
        void findEmptySlots(int row, int column);
        void findCombustiveSlots(int row, int column);
        bool isSuitableForCombustive(int row, int column);
        int countEmptySlots();
        void returnChemicals();
        

        Chemical **shelves;
        int id;
        int rows;
        int columns;

};

#endif