//
// Created by Toby Dragon on 10/30/18.
//

#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList(){
    front = nullptr;
    end = nullptr;
    this->currItemCount = 0;
}

//Destructor
LinkedList::~LinkedList(){
    clearList();
}

 //Big-O is 0(1)
void LinkedList::insertAtEnd(int itemToAdd) {
     LinkedNode *newNode = new LinkedNode(itemToAdd);
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
int LinkedList::getValueAt(int index){
    if(index < 0 or index > currItemCount-1) {
        throw std::out_of_range("Index is not Valid");
    }
    LinkedNode* tempItem = front;
    for(int i=0; i<index; i++){
        tempItem = tempItem->getNext();
    }
    return tempItem->getItem();

}

//Big-O is 0(n)
std::string LinkedList::toString(){
    std::string str;
    str.append("{");
    LinkedNode* tempValue = front;
    if(front!=nullptr) {
        for (int i = 0; i < currItemCount; i++) {
            str.append(std::to_string(tempValue->getItem()));
            if (i<currItemCount-1) {
                str.append(", ");
            }
            tempValue = tempValue->getNext();
        }
    }
    str.append("}");
    return str;
}

//Big-O is 0(1)
bool LinkedList::isEmpty(){
    return (front == nullptr);
}

//Big-O is 0(1)
int LinkedList::itemCount(){
    return currItemCount;
}

//Big-O is 0(n)
void LinkedList::clearList(){
    while ( ! isEmpty()){
        removeValueAtFront();
    }
}

//Big-O is 0(n)
int LinkedList::find(int numToFind){
    LinkedNode* tempValue = front;
    for(int i=0;i<= currItemCount -1;i++){
        if(tempValue->getItem() == numToFind){
            return i;
        }
        tempValue = tempValue->getNext();
    }
    return -1;
}

//Big-O is 0(n)
int LinkedList::findLast(int numToFind){
    LinkedNode* tempValue = front;
    int tempNum = -1;
    for(int i=0;i<currItemCount;i++){
        if(tempValue->getItem() == numToFind){
            tempNum = i;
        }
        tempValue = tempValue->getNext();
    }
    return tempNum;
}

//Big-O is 0(n)
int LinkedList::findMaxIndex(){
    if(isEmpty()) {
        throw std::out_of_range("No valid Items");
    }
    LinkedNode* tempValue = front;
    int tempMax = front->getItem();
    int tempIdx = 0;
    for(int i=0;i<currItemCount;i++){
        if(tempValue->getItem() > tempMax){
            tempIdx = i;
            tempMax = tempValue->getItem();
        }
        tempValue = tempValue->getNext();
    }
    return tempIdx;
}

//Big-O is 0(1)
void LinkedList::insertAtFront(int itemToAdd){
    LinkedNode* newNode = new LinkedNode(itemToAdd);
    if(isEmpty()){
        front = newNode;
        end = newNode;

    }else {
        LinkedNode *tempNode = front;
        front = newNode;
        newNode->setNext(tempNode);
    }
    currItemCount++;
}

//Big-O is 0(n)
void LinkedList::insertAt(int itemToAdd, int index){
    if(index < 0 or index > currItemCount) {
        throw std::out_of_range("Index is not Valid");
    }
    if(index == 0){
        insertAtFront(itemToAdd);
    }
    if(index == currItemCount){
        insertAtEnd(itemToAdd);
    }else {
        LinkedNode *beforeIdx = front;
        LinkedNode *idx = front->getNext();

        LinkedNode *newNode = new LinkedNode(itemToAdd);
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
int LinkedList::removeValueAtEnd(){
    if(isEmpty()) {
        throw std::out_of_range("No valid item to remove");
    }
    int tempItem = end->getItem();
    if(currItemCount==1){
        delete end;
        end= nullptr;
        front= nullptr;
        currItemCount--;
        return  tempItem;
    }
    delete end;
    currItemCount--;
    LinkedNode* tempValue = front;
    for (int i = 0; i <= currItemCount - 1; i++) {
        end = tempValue;
        tempValue = tempValue->getNext();
        }
    return tempItem;
}

//Big-O is 0(1)
int LinkedList::removeValueAtFront(){
    if(isEmpty()) {
        throw std::out_of_range("No valid Items");
    }
    //std::cout<<"test"<<std::endl;

    LinkedNode* tempItem = front;
    int tempNum = tempItem->getItem();
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
int LinkedList::removeValueAt(int index){
    if(index < 0) {
        throw std::out_of_range("Index is not Valid");
    }
    LinkedNode* beforeIdx = front;
    LinkedNode* idx = front->getNext();
    LinkedNode* afterIdx;
    int tempItem;
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

