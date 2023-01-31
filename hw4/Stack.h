// Mehmet Feyyaz Küçük 22003550

#include <string>
using namespace std;

#ifndef STACK_H
#define STACK_H

class Stack {
    public:
        Stack();
        Stack(const Stack& astack);
        ~Stack();

        bool isEmpty() const;
        bool push(string newItem);
        bool pop();
        bool pop(string& stackTop);
        bool getTop(string& stackTop);
    
    private:
        struct StackNode {
            string item;
            StackNode* next;
        };

        StackNode* topPtr;
};

#endif