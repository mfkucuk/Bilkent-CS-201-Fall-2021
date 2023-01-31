// Mehmet Feyyaz Küçük 22003550

#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack() {
    topPtr = NULL;
}

Stack::Stack(const Stack& aStack) {
    if (aStack.isEmpty()) {
        topPtr = NULL;
    }
    else {
        topPtr = new StackNode;
        topPtr->item = aStack.topPtr->item;

        StackNode* tail = topPtr;
        for (StackNode* cur = aStack.topPtr->next; cur != NULL; cur = cur->next) {
            StackNode* newPtr = new StackNode;
            newPtr->item = cur->item;
            tail->next = newPtr;
            tail = newPtr;
        }
        tail->next = NULL;
    }
}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

bool Stack::isEmpty() const {
    return topPtr == NULL;
}

bool Stack::push(string newItem) {
    StackNode* newPtr = new StackNode;
    newPtr->item = newItem;

    newPtr->next = topPtr;
    topPtr = newPtr;
    return true;
}

bool Stack::pop() {
    if (isEmpty()) {
        return false;
    }

    StackNode* temp = topPtr;
    topPtr = topPtr->next;
    temp->next = NULL;
    delete temp;
    return true;
}

bool Stack::pop(string& stackTop) {
    if (isEmpty()) {
        return false;
    }

    stackTop = topPtr->item;

    StackNode* temp = topPtr;
    topPtr = topPtr->next;
    temp->next = NULL;
    delete temp;
    return true;
}

bool Stack::getTop(string& stackTop) {
    if (isEmpty()) {
        return false;
    }

    stackTop = topPtr->item;
    return true;
}