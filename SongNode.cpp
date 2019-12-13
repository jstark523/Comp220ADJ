//
// Created by Toby Dragon on 10/17/17.
//
#include "SongNode.h"

SongNode::SongNode(Song item){
    this->item = item;
    next = nullptr;
}

SongNode::SongNode(const SongNode& nodeToCopy){
    item = nodeToCopy.item;
    next = nullptr;
}
Song SongNode::getItem(){
    return item;
}

SongNode* SongNode::getNext(){
    return next;
}

void SongNode::setItem(Song newItem){
    item = newItem;
}

void SongNode::setNext(SongNode* newNext){
    next = newNext;
}
