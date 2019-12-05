//
// Created by Toby Dragon on 10/24/17.
//
#include "LinkedQueue.h"

//Creates an empty queue
LinkedQueue::LinkedQueue(){
    front = nullptr;
    end = nullptr;
}

//Copy Constructor
LinkedQueue::LinkedQueue(const LinkedQueue& queueToCopy){
    if(queueToCopy.front == nullptr) {
        front = nullptr;
        end = nullptr;
    }else{
        LinkedNode *currPtr = queueToCopy.front;
        LinkedNode *newCurrPtr = new LinkedNode(queueToCopy.front->getItem());
        front = newCurrPtr;
        currPtr = currPtr->getNext();

        while (currPtr != nullptr) {
            LinkedNode *newNode = new LinkedNode(currPtr->getItem());
            newCurrPtr->setNext(newNode);
            newCurrPtr = newCurrPtr->getNext();
            currPtr = currPtr->getNext();
            end = newCurrPtr;
        }
    }
}

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& queueToCopy){
    if(this != &queueToCopy) {
        while (!isEmpty()) {
            dequeue();
        }

        if (queueToCopy.front == nullptr) {
            front = nullptr;
            end = nullptr;
        } else {
            LinkedNode *currPtr = queueToCopy.front;
            LinkedNode *newCurrPtr = new LinkedNode(queueToCopy.front->getItem());
            front = newCurrPtr;
            currPtr = currPtr->getNext();

            while (currPtr != nullptr) {
                LinkedNode *newNode = new LinkedNode(currPtr->getItem());
                newCurrPtr->setNext(newNode);
                newCurrPtr = newCurrPtr->getNext();
                currPtr = currPtr->getNext();
                end = newCurrPtr;
            }
        }
    }
    return *this;
}

//Destructor
LinkedQueue::~LinkedQueue(){
    while( ! isEmpty()){
        dequeue();
    }
}


//adds an item to the end of the queue
void LinkedQueue::enqueue(std::string item){
    LinkedNode* newNode = new LinkedNode(item);
    //if front is nullptr, end should be nullptr too
    if (front == nullptr){
        front = newNode;
        end = newNode;
    }
    else {
        end->setNext(newNode);
        end = newNode;
    }
}

//takes an item off the front of the queue and returns it
//throws out_of_range exception if the queue is empty
std::string LinkedQueue::dequeue(){
    if(isEmpty()){
        throw std::out_of_range("Queue is empty");
    }else if (front == end){
        std::string tempItem = front->getItem();
        delete(front);
        front = nullptr;
        end = nullptr;
        return tempItem;
    }else{
        std::string tempItem = front->getItem();
        LinkedNode* tempFront = front->getNext();
        delete(front);
        front = tempFront;
        return tempItem;
    }
}

//returns true if the queue has no items, false otherwise
bool LinkedQueue::isEmpty(){
    return front == nullptr;
}