//
// Created by Toby Dragon on 10/22/17.
//

#ifndef STACKSANDQUEUES_QUEUE_H
#define STACKSANDQUEUES_QUEUE_H

#include <string>
#include <stdexcept>
#include "SongNode.h"
#include "Song.h"

/**
 * Represents a FIFO data structure (First In First Out). Picture a line
 * to wait for something (first person in is the first person out)
 */
class LinkedQueueSong {
private:
    SongNode* front;
    SongNode* end;

public:
    
    //Creates an empty queue
    LinkedQueueSong();

    //Copy Constructor
    LinkedQueueSong(const LinkedQueueSong& queueToCopy);

    //assn operator
    LinkedQueueSong& operator=(const LinkedQueueSong& queueToCopy);

    //Destructor
    ~LinkedQueueSong();
    
    //adds an item to the end of the queue
    void enqueue(Song item);

    //takes an item off the front of the queue and returns it
    //throws out_of_range exception if the queue is empty
    Song dequeue();

    //returns true if the queue has no items, false otherwise
    bool isEmpty();

    std::string to_String();

    SongNode* getFront();

    SongNode* getEnd();

    void setFront(SongNode* newFront);

    void setEnd(SongNode* newEnd);

};

#endif //STACKSANDQUEUES_QUEUE_H
