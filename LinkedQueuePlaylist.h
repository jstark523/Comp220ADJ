//
// Created by Jrsta on 12/14/2019.
//

#ifndef COMP220ADJ_LINKEDQUEUEPLAYLIST_H
#define COMP220ADJ_LINKEDQUEUEPLAYLIST_H

#include <string>
#include "Playlist.h"
#include "PlaylistNode.h"
#include "PlayListStorage.h"
#include "SongStorage.h"

/**
 * Represents a FIFO data structure (First In First Out). Picture a line
 * to wait for something (first person in is the first person out)
 */

class LinkedQueuePlaylist {
private:
    PlaylistNode* front;
    PlaylistNode* end;

public:

    //Creates an empty queue
    LinkedQueuePlaylist();

    //Copy Constructor
    LinkedQueuePlaylist(const LinkedQueuePlaylist& queueToCopy);

    //assn operator
    LinkedQueuePlaylist& operator=(const LinkedQueuePlaylist& queueToCopy);

    //Destructor
    ~LinkedQueuePlaylist();

    //adds an item to the end of the queue
    void enqueue(SongStorage* item);

    //takes an item off the front of the queue and returns it
    //throws out_of_range exception if the queue is empty
    SongStorage dequeue();

    //returns true if the queue has no items, false otherwise
    bool isEmpty();

    PlaylistNode* getFront();

    PlaylistNode* getEnd();

    void setFront(PlaylistNode* newFront);

    void setEnd(PlaylistNode* newEnd);

};

#endif //COMP220ADJ_LINKEDQUEUEPLAYLIST_H
