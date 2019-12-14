//
// Created by Jrsta on 12/14/2019.
//

#include <iostream>
#include "LinkedQueuePlaylist.h"
#include "SongStorage.h"
#include "PlaylistNode.h"
#include "Playlist.h"

//Creates an empty queue
LinkedQueuePlaylist::LinkedQueuePlaylist(){
    front = nullptr;
    end = nullptr;
}

//Copy Constructor
LinkedQueuePlaylist::LinkedQueuePlaylist(const LinkedQueuePlaylist& queueToCopy){
    if(queueToCopy.front == nullptr) {
        front = nullptr;
        end = nullptr;
    }else{
        PlaylistNode *currPtr = queueToCopy.front;
        PlaylistNode *newCurrPtr = new PlaylistNode(queueToCopy.front->getItem());
        front = newCurrPtr;
        currPtr = currPtr->getNext();

        while (currPtr != nullptr) {
            PlaylistNode *newNode = new PlaylistNode(currPtr->getItem());
            newCurrPtr->setNext(newNode);
            newCurrPtr = newCurrPtr->getNext();
            currPtr = currPtr->getNext();
            end = newCurrPtr;
        }
    }
}

LinkedQueuePlaylist& LinkedQueuePlaylist::operator=(const LinkedQueuePlaylist& queueToCopy){
    if(this != &queueToCopy) {
        while (!isEmpty()) {
            dequeue();
        }

        if (queueToCopy.front == nullptr) {
            front = nullptr;
            end = nullptr;
        } else {
            PlaylistNode *currPtr = queueToCopy.front;
            PlaylistNode *newCurrPtr = new PlaylistNode(queueToCopy.front->getItem());
            front = newCurrPtr;
            currPtr = currPtr->getNext();

            while (currPtr != nullptr) {
                PlaylistNode *newNode = new PlaylistNode(currPtr->getItem());
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
LinkedQueuePlaylist::~LinkedQueuePlaylist(){
    while( ! isEmpty()){
        dequeue();
    }
}

void LinkedQueuePlaylist::setFront(PlaylistNode* newFront){
    front = newFront;
}

void LinkedQueuePlaylist::setEnd(PlaylistNode* newEnd){
    end = newEnd;
}


//adds an item to the end of the queue
void LinkedQueuePlaylist::enqueue(SongStorage item){
    PlaylistNode* newNode = new PlaylistNode(item);
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
SongStorage LinkedQueuePlaylist::dequeue(){
    if(isEmpty()){
        throw std::out_of_range("Queue is empty");
    }else if (front == end){
        SongStorage tempItem = front->getItem();
        delete(front);
        front = nullptr;
        end = nullptr;
        return tempItem;
    }else{
        SongStorage tempItem = front->getItem();
        PlaylistNode* tempFront = front->getNext();
        delete(front);
        front = tempFront;
        return tempItem;
    }
}

//returns true if the queue has no items, false otherwise
bool LinkedQueuePlaylist::isEmpty(){
    return front == nullptr;
}

PlaylistNode* LinkedQueuePlaylist::getFront(){
    return front;
}

PlaylistNode* LinkedQueuePlaylist::getEnd(){
    return end;
}