//
// Created by Toby Dragon on 10/30/18.
//

#ifndef LAB8SOLN_LINKEDLIST_H
#define LAB8SOLN_LINKEDLIST_H


#include "ListForSongs.h"
#include "SongNode.h"
#include "Song.h"
#include "PlaylistNode.h"
#include "SongStorage.h"

class SongList : public ListForSongs{
private:
    SongNode* front;
    SongNode* end;
     int currItemCount;


    //Private to disable copying and assigning from outside class, don't implement these methods
    SongList(const SongList& arrayListToCopy);
    SongList& operator=(const SongList& arrayListToCopy);


public:
    /**
     * Constructor
     */
    SongList();

    //Destructor
    ~SongList();

    /**
     * appends the new item to the end of the list
     * @post the list has an additional value in it, at the end
     */
    void insertAtEnd(Song itemToAdd);

    /**
     * gets a value from the list
     * @param index the location from which to get the value
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    Song getValueAt(int index);

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
    void insertAtFront(Song itemToAdd);

    /**
     * inserts the item into the list so that it can be found with get(index)
     * @param index the location in which to insert this item
     * @post the list has an additional value in it at the specified index,
     *        all further values have been shifted down by one index
     * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
     */
    void insertAt(Song itemToAdd, int index);

    /**
     * removes the item at the end of the list, and returns a copy of that item
     * @post the item at the end is removed from the list
     * @return a copy of the item at the end
     * @throws out_of_range exception if there is no item to remove
     */
    Song removeValueAtEnd();

    /**
     * removes the item at the front of the list, and returns a copy of that item
     * @post the item at the front is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if there is no item to remove
     */
    Song removeValueAtFront();

    /**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    Song removeValueAt(int index);

};


#endif //LAB8SOLN_LINKEDLIST_H
