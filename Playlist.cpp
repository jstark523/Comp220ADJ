//
// Created by Jrsta on 12/11/2019.
//



#include <iostream>
#include "Playlist.h"
#include "LinkedNode.h"
#include "LinkedList.h"
#include "Song.h"
#include "LinkedQueue.h"

PlayList::PlayList(std::string playListNameIn){
    songCount = 0;
    totalDuration = 0;
    playListName = playListNameIn;
    songList = new LinkedQueue();
}

PlayList::~PlayList(){
    delete[] songList;
}


PlayList::PlayList(const PlayList &playListToCopy) {
    songCount = playListToCopy.songCount;
    totalDuration = playListToCopy.totalDuration;
    playListName = playListToCopy.playListName;
    songList = new LinkedQueue(*playListToCopy.songList);
}



PlayList& PlayList::operator=(const class PlayList &playListToCopy) {
    if(this != &playListToCopy) {
        delete[] songList;

        songCount = playListToCopy.songCount;
        totalDuration = playListToCopy.totalDuration;
        playListName = playListToCopy.playListName;
        songList = new LinkedQueue(*playListToCopy.songList);



    }
    return *this;

}

std::string PlayList::songsInPlaylist(){
    if(songCount > 0) {
        LinkedNode *tempNode;
        tempNode = songList->getFront();
        Song tempSong = tempNode->getItem();
        std::string songTitles = "";
        songTitles += tempSong.getTitle();
        for (int i = 1; i < songCount; i++) {
            tempNode = tempNode->getNext();
            tempSong = tempNode->getItem();
            songTitles += ", " + tempSong.getTitle();
        }
        std::string durationString = std::to_string(totalDuration);
        songTitles += ", "+ durationString;
        return songTitles;
    }
    else{
        std::cout<<"No songs in List"<<std::endl;
    }
}

int PlayList::getTotalDuration(){
    return totalDuration;
}

std::string PlayList::playNext() {
    std::string songInfo;
    if(isEmpty()){
        songInfo = "Playlist is empty, add a song to play it.";
    }
    else{
        Song songToPlay = songList->dequeue();
        songInfo = Song::songToString(songToPlay);
        totalDuration -= songToPlay.getDuration();
        songCount -= 1;
        remove(songToPlay.getTitle());
    }
    return songInfo;
}

bool PlayList::isEmpty() {
    return songList->getFront() == nullptr;
}

void PlayList::add(Song songToAdd){
    songList->enqueue(songToAdd);
   totalDuration += songToAdd.getDuration();
   songCount += 1;
}

void PlayList::remove(std::string songName){
    bool songRemoved = false;
    int tempDuration;
    if(songCount > 0) {
        LinkedNode* iterator = songList->getFront();
        Song tempSong = iterator->getItem();
        if(tempSong.getTitle() != songName) {
            for (int i = 1; i < songCount; i++) {
                while (tempSong.getTitle() != songName || songList->getFront() == nullptr) {
                    iterator = iterator->getNext();
                    tempSong = iterator->getItem();
                }
            }

            if(tempSong.getTitle() == songName){

            }
        }
        else{
            if(songCount > 2){
                LinkedNode *nextFront = iterator->getNext();
                tempDuration = iterator->getItem().getDuration();
                delete[] iterator;
                songRemoved = true;
                songList->setFront(nextFront);
            }
            if(songCount == 2){
                LinkedNode *nextFront = iterator->getNext();
                tempDuration = iterator->getItem().getDuration();
                delete[] iterator;
                songRemoved = true;
                songList->setFront(nextFront);
                songList->setEnd(nextFront);
            }
            if(songCount == 1){
                tempDuration = iterator->getItem().getDuration();
                delete[] iterator;
                songRemoved = true;
                songList->setFront(nullptr);
                songList->setEnd(nullptr);
            }
        }
    }

    if(songRemoved == true){
        songCount -= 1;
        totalDuration -= tempDuration;
    }
    else{
        std::cout<<"Song not found in Playlist"<<std::endl;
    }
}

std::string PlayList::songsOfArtist(std::string artistIn){
    std::string outPutString = "";
    if(songCount > 0){
        Song tempSong;
        LinkedNode* iterator = songList->getFront();
        tempSong = iterator->getItem();
        while(iterator != nullptr){
            if(tempSong.getArtist() == artistIn){
                outPutString += tempSong.getTitle() + "*";
                iterator = iterator->getNext();
                tempSong = iterator->getItem();
            }
            else{
                iterator = iterator->getNext();
                tempSong = iterator->getItem();
            }
        }
        if(tempSong.getArtist() == artistIn){
            outPutString += tempSong.getTitle() + "*";
        }

    }
    if (outPutString == "") {
        outPutString = "Songs of that artist weren't found in Playlist";
    }
    else{
        outPutString += "|";
    }

    return outPutString;
}
