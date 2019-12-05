//
// Created by Toby Dragon on 10/24/17.
//

#include "LinkedStack.h"

//Creates an empty stack
LinkedStack::LinkedStack(){
    top = nullptr;
}

//copy constructor
LinkedStack::LinkedStack(const LinkedStack& stackToCopy){
    if(stackToCopy.top == nullptr){
        top = nullptr;
    }else{

        LinkedNode *currPtr = stackToCopy.top;
        LinkedNode *newCurrPtr = new LinkedNode(stackToCopy.top->getItem());
        top = newCurrPtr;
        currPtr = currPtr->getNext();

        while (currPtr != nullptr) {
            LinkedNode *newNode = new LinkedNode(currPtr->getItem());
            newCurrPtr->setNext(newNode);
            newCurrPtr = newCurrPtr->getNext();
            currPtr = currPtr->getNext();
        }
    }
}

LinkedStack& LinkedStack::operator=(const LinkedStack& stackToCopy){
    if (this != &stackToCopy) {
        while (!isEmpty()) {
            pop();
        }

        if (stackToCopy.top == nullptr) {
            top = nullptr;
        } else {

            LinkedNode *currPtr = stackToCopy.top;
            LinkedNode *newCurrPtr = new LinkedNode(stackToCopy.top->getItem());
            top = newCurrPtr;
            currPtr = currPtr->getNext();

            while (currPtr != nullptr) {
                LinkedNode *newNode = new LinkedNode(currPtr->getItem());
                newCurrPtr->setNext(newNode);
                newCurrPtr = newCurrPtr->getNext();
                currPtr = currPtr->getNext();
            }
        }
    }
    return *this;
}

//destructor
LinkedStack::~LinkedStack(){
    while( ! isEmpty()){
        pop();
    }
}

//puts an item onto the top of the stack
void LinkedStack::push (std::string item){
    LinkedNode* newNode = new LinkedNode(item);
    newNode->setNext(top);
    top = newNode;
}

//takes the item off the top of the stack and returns it
//throws out_of_range exception if the stack is empty
std::string LinkedStack::pop(){
    if(isEmpty()){
        throw std::out_of_range("Stack is empty");
    }

    std::string tempItem = top->getItem();
    LinkedNode* tempTop = top->getNext();
    delete(top);
    top = tempTop;
    return  tempItem;
}

//returns true if the stack has no items, false otherwise
bool LinkedStack::isEmpty(){
    return top == nullptr;
}
