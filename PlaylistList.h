//
// Created by Bryan Pruett on 12/13/19.
//

#ifndef COMP220ADJ_PLAYLISTLIST_H
#define COMP220ADJ_PLAYLISTLIST_H

#include "List.h"
#include "SongNode.h"
#include "Song.h"
#include "PlaylistNode.h"
#include "SongStorage.h"

class PlaylistList : public List{
private:
    PlaylistNode* front;
    PlaylistNode* end;
    int currItemCount;


    //Private to disable copying and assigning from outside class, don't implement these methods
    PlaylistList(const PlaylistList& arrayListToCopy);
    PlaylistList& operator=(const PlaylistList& arrayListToCopy);


public:
    /**
     * Constructor
     */
    PlaylistList();

    //Destructor
    ~PlaylistList();

    /**
     * appends the new item to the end of the list
     * @post the list has an additional value in it, at the end
     */
    void insertAtEnd(SongStorage itemToAdd);

    /**
     * gets a value from the list
     * @param index the location from which to get the value
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    SongStorage getValueAt(int index);

    /**
     * checks if there are any valid items in the list
     * @return true if there are no valid items in the list, false otherwise
     */
    bool isEmpty();

    /**
     * returns a count of valid items currently in the list
     * @returns the number of valid items in the list
     */
    int itemCount();

    /**
     * makes the list empty of valid items
     * @post the list is empty, such that isEmpty() == true
     */
    void clearList();


    /**
     * appends the new item to the beginning of the list
     * @post the list has an additional value in it, at the beginning
     *    all other items are shifted down by one index
     */
    void insertAtFront(SongStorage itemToAdd);

    /**
     * inserts the item into the list so that it can be found with get(index)
     * @param index the location in which to insert this item
     * @post the list has an additional value in it at the specified index,
     *        all further values have been shifted down by one index
     * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
     */
    void insertAt(SongStorage itemToAdd, int index);

    /**
     * removes the item at the end of the list, and returns a copy of that item
     * @post the item at the end is removed from the list
     * @return a copy of the item at the end
     * @throws out_of_range exception if there is no item to remove
     */
    SongStorage removeValueAtEnd();

    /**
     * removes the item at the front of the list, and returns a copy of that item
     * @post the item at the front is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if there is no item to remove
     */
    SongStorage removeValueAtFront();

    /**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    SongStorage removeValueAt(int index);

};



#endif //COMP220ADJ_PLAYLISTLIST_H
