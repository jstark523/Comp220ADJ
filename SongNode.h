//
// Created by Toby Dragon on 10/24/16.
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "Song.h"

class SongNode {

private:
    Song item;
    SongNode* next;

public:
    SongNode(Song item);
    SongNode(const SongNode& nodeToCopy); //only copies item, next is set to nullptr
    Song getItem();
    SongNode* getNext();
    void setItem(Song newItem);
    void setNext(SongNode* newNext);
};


#endif //LINKEDNODE_H
