//
// Created by Bryan Pruett on 12/13/19.
//

#include "PlaylistNode.h"
#include "PlayListStorage.h"
#include "SongStorage.h"

PlaylistNode::PlaylistNode(SongStorage item){
    this->item = item;
    next = nullptr;
}

PlaylistNode::PlaylistNode(const PlaylistNode& nodeToCopy){
    item = nodeToCopy.item;
    next = nullptr;
}
SongStorage PlaylistNode::getItem(){
    return item;
}

PlaylistNode* PlaylistNode::getNext(){
    return next;
}

void PlaylistNode::setItem(SongStorage newItem){
    item = newItem;
}

void PlaylistNode::setNext(PlaylistNode* newNext){
    next = newNext;
}
