//
// Created by Bryan Pruett on 12/13/19.
//

#ifndef COMP220ADJ_PLAYLISTNODE_H
#define COMP220ADJ_PLAYLISTNODE_H

#include "SongStorage.h"
#include "PlayListStorage.h"

class PlaylistNode {

private:
    SongStorage item;
    PlaylistNode* next;
public:
    PlaylistNode();
    PlaylistNode(SongStorage item);
    PlaylistNode(const PlaylistNode& nodeToCopy); //only copies item, next is set to nullptr
    SongStorage getItem();
    PlaylistNode* getNext();
    void setItem(SongStorage newItem);
    void setNext(PlaylistNode* newNext);
};

#endif //COMP220ADJ_PLAYLISTNODE_H
