//
// Created by faste on 12/13/2019.
//

#include <iostream>
#include <string>
#include "SongNode.h"
#include "LinkedQueueSong.h"
#include "Sort.h"
#include "SongStorage.h"

void Sort::swap(std::string *xp, std::string *yp){
    std::string  temp= *xp;
    *xp= *yp;
    *yp= temp;
}

void Sort::bubbleSort(std::string arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void Sort::printArray(std::string arr[], int size){
        int i;
        for(i=0; i < size; i++)
            std::cout << arr[i] << std::endl;
        std::cout << std::endl;
}

void Sort::sortLibrary(SongStorage* libraryIn){
    if(libraryIn->getSongCount() > 0) {
        std::string arr[libraryIn->getSongCount()];
        SongNode *iterator = libraryIn->getSongList()->getFront();
        Song tempSong = iterator->getItem();
        std::string tempSongString = tempSong.songToString(tempSong);
        arr[0] = tempSongString;
        for (int i = 1; i < libraryIn->getSongCount(); i++) {
            iterator = iterator->getNext();
            tempSong = iterator->getItem();
            tempSongString = tempSong.songToString(tempSong);
            arr[i] = tempSongString;
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        bubbleSort(arr, n);
        std::cout << "Sorted array: \n";
        printArray(arr, n);
    }

    else{
        std::cout<<"Library has no songs"<<std::endl;
    }
}
