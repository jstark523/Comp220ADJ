//
// Created by Toby Dragon on 10/24/17.
//
#include <iostream>
#include "LinkedQueue.h"
#include "Song.h"
#include "LinkedNode.h"

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

void LinkedQueue::setFront(LinkedNode* newFront){
    front = newFront;
}

void LinkedQueue::setEnd(LinkedNode* newEnd){
    end = newEnd;
}


//adds an item to the end of the queue
void LinkedQueue::enqueue(Song item){
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
Song LinkedQueue::dequeue(){
    if(isEmpty()){
        throw std::out_of_range("Queue is empty");
    }else if (front == end){
        Song tempItem = front->getItem();
        delete(front);
        front = nullptr;
        end = nullptr;
        return tempItem;
    }else{
        Song tempItem = front->getItem();
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

LinkedNode* LinkedQueue::getFront(){
    return front;
}

LinkedNode* LinkedQueue::getEnd(){
    return end;
}

std::string LinkedQueue::to_String() {
    if (front != nullptr) {
        std::string queueString = "";
        LinkedNode* nodeToCopy = front;
        while(nodeToCopy != nullptr){
            queueString += Song::songToString(nodeToCopy->getItem());
            nodeToCopy = nodeToCopy->getNext();
        }
        return queueString;
    }
    else{
        std::cout << "Queue has no songs in it" << std::endl;
    }
}

