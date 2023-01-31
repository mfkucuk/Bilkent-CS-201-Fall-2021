// Mehmet Feyyaz Küçük 22003550



#ifndef CHEMICAL_H
#define CHEMICAL_H

#include <string>
using namespace std;

class Chemical {
    public:

        Chemical();
        ~Chemical();
        void initChemical(const Chemical& other);
        void initChemical(char type, int id, string location);

        char type;
        int id;
        string location;

};

#endif