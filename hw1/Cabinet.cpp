// Mehmet Feyyaz Küçük 22003550

#include <iostream>
using namespace std;
#include "Cabinet.h"

Cabinet::Cabinet() {
    
}

Cabinet::~Cabinet() {
    for (int i = 0; i < rows; i++) {
        delete [] shelves[i];
    }

    delete [] shelves;
}

void Cabinet::initCabinet(int id, int rows, int columns) {
    this->id = id;
    this->rows = rows;
    this->columns = columns;

    shelves = new Chemical*[rows];

    for (int i = 0; i < rows; i++) {
        shelves[i] = new Chemical[columns];
    }
}

void Cabinet::initShelves(const Cabinet &other) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            shelves[i][j].initChemical(other.shelves[i][j]);
        }
    }
}

void Cabinet::findEmptySlots(int row, int column) {

    bool emptySpaceFound = false;
    for (int rad = 1; rad < 10; rad++) {
        for (int i = -rad; i <= rad; i++) {
            for (int j = -rad; j <= rad; j++) {
                if ((row + i >= 0 && row + i < rows) && (column + j >= 0 && column + j < columns)) {
                    if (shelves[row + i][column + j].type == '+') {
                        emptySpaceFound = true;

                        string location = "  ";
                        location[0] = row + i + 65;
                        location[1] = column + j + 49;

                        cout << location << " ";
                    }
                }
            }
        }
        if (emptySpaceFound) {
            return;
        }
    }
}

bool Cabinet::isSuitableForCombustive(int row, int column) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((row + i >= 0 && row + i < rows) && (column + j >= 0 && column + j < columns)) {
                if (shelves[row + i][column + j].type == 'c') {
                    return false;
                }
            }
        }
    }

    return true;
}

void Cabinet::findCombustiveSlots(int row, int column) {

    bool suitableSpaceFound = false;
    for (int rad = 1; rad < 10; rad++) {
        for (int i = -rad; i <= rad; i++) {
            for (int j = -rad; j <= rad; j++) {
                if ((row + i >= 0 && row + i < rows) && (column + j >= 0 && column + j < columns)) {
                    if (isSuitableForCombustive(row + i, column + j)) {
                        suitableSpaceFound = true;

                        string location = "  ";
                        location[0] = row + i + 65;
                        location[1] = column + j + 49;

                        cout << location << " ";
                    }
                }
            }
        }
        if (suitableSpaceFound) {
            return;
        }
    }
}

int Cabinet::countEmptySlots() {
    int result = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (shelves[i][j].type == '+') {
                result++;
            }
        }
    }

    return result;
}

void Cabinet::returnChemicals() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (shelves[i][j].type != '+') {
                cout << shelves[i][j].location << ": " << shelves[i][j].id << " ";
            }
        }
    }
}