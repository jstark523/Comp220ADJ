//
// Created by Toby Dragon on 10/24/17.
//
#include <iostream>
#include "LinkedQueueSong.h"
#include "Song.h"
#include "SongNode.h"

//Creates an empty queue
LinkedQueueSong::LinkedQueueSong(){
    front = nullptr;
    end = nullptr;
}

//Copy Constructor
LinkedQueueSong::LinkedQueueSong(const LinkedQueueSong& queueToCopy){
    if(queueToCopy.front == nullptr) {
        front = nullptr;
        end = nullptr;
    }else{
        SongNode *currPtr = queueToCopy.front;
        SongNode *newCurrPtr = new SongNode(queueToCopy.front->getItem());
        front = newCurrPtr;
        currPtr = currPtr->getNext();

        while (currPtr != nullptr) {
            SongNode *newNode = new SongNode(currPtr->getItem());
            newCurrPtr->setNext(newNode);
            newCurrPtr = newCurrPtr->getNext();
            currPtr = currPtr->getNext();
            end = newCurrPtr;
        }
    }
}

LinkedQueueSong& LinkedQueueSong::operator=(const LinkedQueueSong& queueToCopy){
    if(this != &queueToCopy) {
        while (!isEmpty()) {
            dequeue();
        }

        if (queueToCopy.front == nullptr) {
            front = nullptr;
            end = nullptr;
        } else {
            SongNode *currPtr = queueToCopy.front;
            SongNode *newCurrPtr = new SongNode(queueToCopy.front->getItem());
            front = newCurrPtr;
            currPtr = currPtr->getNext();

            while (currPtr != nullptr) {
                SongNode *newNode = new SongNode(currPtr->getItem());
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
LinkedQueueSong::~LinkedQueueSong(){
    while( ! isEmpty()){
        dequeue();
    }
}

void LinkedQueueSong::setFront(SongNode* newFront){
    front = newFront;
}

void LinkedQueueSong::setEnd(SongNode* newEnd){
    end = newEnd;
}


//adds an item to the end of the queue
void LinkedQueueSong::enqueue(Song item){
    SongNode* newNode = new SongNode(item);
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
Song LinkedQueueSong::dequeue(){
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
        SongNode* tempFront = front->getNext();
        delete(front);
        front = tempFront;
        return tempItem;
    }
}

//returns true if the queue has no items, false otherwise
bool LinkedQueueSong::isEmpty(){
    return front == nullptr;
}

SongNode* LinkedQueueSong::getFront(){
    return front;
}

SongNode* LinkedQueueSong::getEnd(){
    return end;
}

std::string LinkedQueueSong::to_String() {
    if (front != nullptr) {
        std::string queueString = "";
        SongNode* nodeToCopy = front;
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

