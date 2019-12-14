//
// Created by Jrsta on 12/13/2019.
//

#ifndef COMP220ADJ_SORT_H
#define COMP220ADJ_SORT_H

#include<iostream>
#include <string>
#include "SongNode.h"
#include "LinkedQueueSong.h"
#include "SongStorage.h"

class Sort{
public:
    void swap(std::string *xp, std::string *yp);

    void bubbleSort(std::string arr[], int n);

    void printArray(std::string arr[], int size);

    void sortLibrary(SongStorage* libraryIn);
};

#endif //COMP220ADJ_SORT_H
