//
// Created by Bryan Pruett on 12/13/19.
//

#include "PlaylistList.h"
#include <iostream>
#include "SongStorage.h"

PlaylistList::PlaylistList(){
    front = nullptr;
    end = nullptr;
    this->currItemCount = 0;
}

//Destructor
PlaylistList::~PlaylistList(){
    clearList();
}

//Big-O is 0(1)
void PlaylistList::insertAtEnd(SongStorage itemToAdd) {
    PlaylistNode *newNode = new PlaylistNode(itemToAdd);
    if (end == nullptr) {
        front = newNode;
        end = newNode;
    }else{
        end->setNext(newNode);
        end = newNode;
    }
    currItemCount++;
}

//Big-O is 0(n)
SongStorage PlaylistList::getValueAt(int index){
    if (index < 0 or index > currItemCount - 1) {
        throw std::out_of_range("Index is not Valid");
    }
    PlaylistNode *tempItem = front;
    for (int i = 0; i < index; i++) {
        tempItem = tempItem->getNext();
    }

    SongStorage tempSong = tempItem->getItem();

    return tempSong;
}

//Big-O is 0(1)
bool PlaylistList::isEmpty(){
    return (front == nullptr);
}

//Big-O is 0(1)
int PlaylistList::itemCount(){
    return currItemCount;
}

//Big-O is 0(n)
void PlaylistList::clearList(){
    while ( ! isEmpty()){
        removeValueAtFront();
    }
}

//Big-O is 0(1)
void PlaylistList::insertAtFront(SongStorage itemToAdd){
    PlaylistNode* newNode = new PlaylistNode(itemToAdd);
    if(isEmpty()){
        front = newNode;
        end = newNode;

    }else {
        PlaylistNode *tempNode = front;
        front = newNode;
        newNode->setNext(tempNode);
    }
    currItemCount++;
}

//Big-O is 0(n)
void PlaylistList::insertAt(SongStorage itemToAdd, int index){
    if(index < 0 or index > currItemCount) {
        throw std::out_of_range("Index is not Valid");
    }
    if(index == 0){
        insertAtFront(itemToAdd);
    }
    if(index == currItemCount){
        insertAtEnd(itemToAdd);
    }else {
        PlaylistNode *beforeIdx = front;
        PlaylistNode *idx = front->getNext();

        PlaylistNode *newNode = new PlaylistNode(itemToAdd);
        for (int i = 1; i < currItemCount; i++) {
            if (i == index) {
                beforeIdx->setNext(newNode);
                newNode->setNext(idx);
                i = currItemCount;
                currItemCount++;
            }
            beforeIdx = beforeIdx->getNext();
            idx = idx->getNext();
        }
    }
}

//Big-O is 0(n)
SongStorage PlaylistList::removeValueAtEnd(){
    if(isEmpty()) {
        throw std::out_of_range("No valid item to remove");
    }
    SongStorage tempItem = end->getItem();
    if(currItemCount==1){
        delete end;
        end= nullptr;
        front= nullptr;
        currItemCount--;
        return  tempItem;
    }
    delete end;
    currItemCount--;
    PlaylistNode* tempValue = front;
    for (int i = 0; i <= currItemCount - 1; i++) {
        end = tempValue;
        tempValue = tempValue->getNext();
    }
    return tempItem;
}

//Big-O is 0(1)
SongStorage PlaylistList::removeValueAtFront(){
    if(isEmpty()) {
        throw std::out_of_range("No valid Items");
    }
    //std::cout<<"test"<<std::endl;

    PlaylistNode* tempItem = front;
    SongStorage tempNum = tempItem->getItem();
    tempItem=tempItem->getNext();
    delete front;
    front = tempItem;
    currItemCount--;
    if(currItemCount == 1){
        end = nullptr;
    }
    return tempNum;
}

//Big-O is 0(n)
SongStorage PlaylistList::removeValueAt(int index){
    if(index < 0) {
        throw std::out_of_range("Index is not Valid");
    }
    PlaylistNode* beforeIdx = front;
    PlaylistNode* idx = front->getNext();
    PlaylistNode* afterIdx;
    SongStorage tempItem;
    if(index==0){
        tempItem = removeValueAtFront();
    }else {
        for (int i = 1; i <currItemCount; i++) {
            if (i == index) {
                afterIdx = idx->getNext();
                tempItem = idx->getItem();
                beforeIdx->setNext(afterIdx);
                delete idx;
                currItemCount--;
                i = currItemCount;
            }
            beforeIdx=beforeIdx->getNext();
            idx=idx->getNext();
        }
    }
    return tempItem;
}