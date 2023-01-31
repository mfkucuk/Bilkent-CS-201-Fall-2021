// Mehmet Feyyaz Küçük 22003550

#include <iostream>
using namespace std;

#include "LabOrganizer.h"

LabOrganizer::LabOrganizer() {
    numberOfCabinets = 0;
    cabinets = NULL;
}

LabOrganizer::~LabOrganizer() {
    if (numberOfCabinets) {
        delete [] cabinets;
    }
    numberOfCabinets = 0;
}

void LabOrganizer::addCabinet(int id, int rows, int columns) {

    // Check if dimensions are valid
    if (rows > 9 || columns > 9) {
        cout << "Cannot add the cabinet: dimensions are out of bounds" << endl;
        return;
    }
    
    // Check if the id is valid
    for (int i = 0; i < numberOfCabinets; i++) {
        if (id == cabinets[i].id) {
            cout << "Cannot add the cabinet: ID " << id << " already in the system" << endl;
            return;
        }
    }
    

    Cabinet *temp = cabinets;

    // Increase the size of the array.
    cabinets = new Cabinet[numberOfCabinets + 1];

    // Get the previous cabinet information.
    for (int i = 0; i < numberOfCabinets; i++) {
        cabinets[i].initCabinet(temp[i].id, temp[i].rows, temp[i].columns);
        cabinets[i].initShelves(temp[i]);
    }

    // Add the new cabinet.
    cabinets[numberOfCabinets].initCabinet(id, rows, columns);
    
    delete [] temp;
    
    numberOfCabinets++;

    cout << "Added a cabinet: ID " << id << " and dimensions " << rows << " to " << columns << endl;
}

void LabOrganizer::removeCabinet(int id) {

    // Check if the cabinet with the specified id exits.
    bool exists = false;
    for (int i = 0; i < numberOfCabinets; i++) {
        if (id == cabinets[i].id) {
            exists = true;
        }
    }

    if (! exists) {
        cout << "Cabinet " << id << " does not exist in the system" << endl;
        return;
    }

    Cabinet *c;
    for (int i = 0; i < numberOfCabinets; i++) {
        if (id == cabinets[i].id) {
            c = &cabinets[i];
        }
    }

    for (int i = 0; i < c->rows; i++) {
        for (int j = 0; j < c->columns; j++) {
            if (c->shelves[i][j].type != '+') {
                removeChemical(c->shelves[i][j].id);
            }
        }
    }   

    Cabinet *temp = cabinets;

    cabinets = new Cabinet[numberOfCabinets - 1];

    int j = 0;
    for (int i = 0; i < numberOfCabinets; i++) {

        if (id != temp[i].id) {
            cabinets[j].initCabinet(temp[i].id, temp[i].rows, temp[i].columns);
            cabinets[j].initShelves(temp[i]);
            j++;
        }
    }

    delete [] temp;

    numberOfCabinets--;

    cout << "Cabinet " << id << " has been removed" << endl;
}

void LabOrganizer::listCabinets() {
    for (int i = 0; i < numberOfCabinets; i++) {
        cout << "ID: " << cabinets[i].id << ", Dim: " << cabinets[i].rows << "x" << cabinets[i].columns << 
            ", Number of empty slots: " << cabinets[i].countEmptySlots() << endl;;
    }
}

void LabOrganizer::cabinetContents(int id) {

    // Check if the cabinet with the specified id exits.
    bool exists = false;
    for (int i = 0; i < numberOfCabinets; i++) {
        if (id == cabinets[i].id) {
            exists = true;
        }
    }

    if (! exists) {
        cout << "Cabinet " << id << " is not in the system" << endl;
        return;
    }

    // Create the cabinet whose contents are going to be shown.
    Cabinet *c;

    for (int i = 0; i < numberOfCabinets; i++) {
        if (id == cabinets[i].id) {
            c = &cabinets[i];
        }
    }

    // Dynamically allocated array for content array.
    char **content;
    content = new char*[c->rows + 1];

    for (int i = 0; i < c->rows + 1; i++) {
        content[i] = new char[c->columns + 1];
    }

    for (int i = 0; i < c->rows + 1; i++) {
        for (int j = 0; j < c->columns + 1; j++) {
            if (i == 0) {
                content[0][j] = 49 + j - 1; // ascii for numbers
            }
            else if (j == 0) {
                content[i][0] = 65 + i - 1; // ascii for letters 
            }
            else {
                content[i][j] = c->shelves[i-1][j-1].type;
            }
        }
    }

    content[0][0] = ' ';

    cout << "ID: " << id << ", " << c->rows << "x" << c->columns << ", empty: " << c->countEmptySlots();
    cout << ". Chemicals: ";
    c->returnChemicals();
    cout << endl;

    for (int i = 0; i < c->rows + 1; i++) {
        for (int j = 0; j < c->columns + 1; j++) {
            cout << content[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < c->rows + 1; i++) {
        delete [] content[i];
    }

    delete [] content;
}

void LabOrganizer::placeChemical(int cabinetId, string location, string chemType, int chemID) {

    // Check if the cabinet with the specified id exits.
    bool cabinetExists = false;
    for (int i = 0; i < numberOfCabinets; i++) {
        if (cabinetId == cabinets[i].id) {
            cabinetExists = true;
        }
    }

    if (! cabinetExists) {
        cout << "Cabinet " << cabinetId << " is not in the system" << endl;
        return;
    }

    // Check if the chemical with the specified id exits.
    for (int i = 0; i < numberOfCabinets; i++) {
        for (int j = 0; j < cabinets[i].rows; j++) {
            for (int k = 0; k < cabinets[i].columns; k++) {
                if (chemID == cabinets[i].shelves[j][k].id) {
                    cout << "Chemical with ID " << chemID << " already exists in the system" << endl;
                    return;
                }
            }
        }
    }

    Cabinet *c;
    for (int i = 0; i < numberOfCabinets; i++) {
        if (cabinetId == cabinets[i].id) {
            c = &cabinets[i];
        }
    }

    int row = location[0] - 65;
    int col = location[1] - 49;

    // Check if the given location is empty.
    if (c->shelves[row][col].type != '+') {
        cout << "Location " << location << " in the cabinet " << cabinetId << " is already occupied. Nearest possible locations for this chemical: ";
        c->findEmptySlots(row, col);
        cout << endl;
        return;
    }

    // If all conditions are satisfied place the chemical.
    if (chemType == "retardant") {
        c->shelves[row][col].initChemical('r', chemID, location);
        cout << "Retardant chemical with ID " << chemID << " has been placed at location " << location << " in cabinet " << cabinetId << endl; 
    }
    else if (chemType == "combustive") {
        
        // Check if the given space is suitable for a combustive chemical.
        if (! c->isSuitableForCombustive(row, col)) {
            cout << "Location " << location << " in cabinet " << c->id << " is not suitable for a combustive chemical. Nearest possible locations for this chemical: ";
            c->findCombustiveSlots(row, col);
            cout << endl;
            return;
        }

        c->shelves[row][col].initChemical('c', chemID, location);
        cout << "Combustive chemical with ID " << chemID << " has been placed at location " << location << " in cabinet " << cabinetId << endl;
    }

}

void LabOrganizer::findChemical(int id) {

    // Check if the chemical with the specified id exists.
    bool chemicalExists = false;
    for (int i = 0; i < numberOfCabinets; i++) {
        for (int j = 0; j < cabinets[i].rows; j++) {
            for (int k = 0; k < cabinets[i].columns; k++) {
                if (id == cabinets[i].shelves[j][k].id) {
                    chemicalExists = true;
                }
            }
        }
    }

    if (! chemicalExists) {
        cout << "Chemical " << id << " is not in the system" << endl;
        return;
    }

    Cabinet *c;
    Chemical *chem;

    for (int i = 0; i < numberOfCabinets; i++) {
        for (int j = 0; j < cabinets[i].rows; j++) {
            for (int k = 0; k < cabinets[i].columns; k++) {
                if (id == cabinets[i].shelves[j][k].id) {
                    c = &cabinets[i];
                    chem = &cabinets[i].shelves[j][k];
                }
            }
        }
    }

    cout << "Chemical " << id << " is at the location " << chem->location << " in cabinet " << c->id << endl;

}

void LabOrganizer::removeChemical(int id) {
    // Check if the chemical with the specified id exists.
    bool chemicalExists = false;
    for (int i = 0; i < numberOfCabinets; i++) {
        for (int j = 0; j < cabinets[i].rows; j++) {
            for (int k = 0; k < cabinets[i].columns; k++) {
                if (id == cabinets[i].shelves[j][k].id) {
                    chemicalExists = true;
                }
            }
        }
    }

    if (! chemicalExists) {
        cout << "Chemical " << id << " is not in the system" << endl;
        return;
    }

    Cabinet *c;
    Chemical *chem;

    for (int i = 0; i < numberOfCabinets; i++) {
        for (int j = 0; j < cabinets[i].rows; j++) {
            for (int k = 0; k < cabinets[i].columns; k++) {
                if (id == cabinets[i].shelves[j][k].id) {
                    c = &cabinets[i];
                    chem = &cabinets[i].shelves[j][k];
                }
            }
        }
    }

    int row = chem->location[0] - 65;
    int col = chem->location[1] - 49;

    c->shelves[row][col].initChemical('+', -1, "");

    cout << "Chemical " << id << " removed from cabinet " << c->id << endl;
}