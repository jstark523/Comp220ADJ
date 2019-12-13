//
// Created by Jrsta on 12/11/2019.
//



#include <iostream>
#include "SongStorage.h"
#include "SongNode.h"
#include "SongList.h"
#include "Song.h"
#include "LinkedQueue.h"
#include "PlaylistNode.h"

SongStorage::SongStorage() {}

SongStorage::SongStorage(std::string playListNameIn){
    songCount = 0;
    totalDuration = 0;
    playListName = playListNameIn;
    songList = new LinkedQueue();
}

SongStorage::~SongStorage(){
    delete[] songList;
}


SongStorage::SongStorage(const SongStorage &playListToCopy) {
    songCount = playListToCopy.songCount;
    totalDuration = playListToCopy.totalDuration;
    playListName = playListToCopy.playListName;
    songList = new LinkedQueue(*playListToCopy.songList);
}



SongStorage& SongStorage::operator=(const class SongStorage
        &playListToCopy) {
    if(this != &playListToCopy) {
        delete[] songList;

        songCount = playListToCopy.songCount;
        totalDuration = playListToCopy.totalDuration;
        playListName = playListToCopy.playListName;
        songList = new LinkedQueue(*playListToCopy.songList);



    }
    return *this;

}

std::string SongStorage::songsInPlaylist(){
    if(songCount > 0) {
        SongNode *tempNode;
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
        return "";
    }
}

int SongStorage::getTotalDuration(){
    return totalDuration;
}

std::string SongStorage::playNext() {
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

bool SongStorage::isEmpty() {
    return songList->getFront() == nullptr;
}

void SongStorage::add(Song songToAdd){
    songList->enqueue(songToAdd);
   totalDuration += songToAdd.getDuration();
   songCount += 1;
}

void SongStorage::remove(std::string songName){
    if (songCount > 0) {
        int songLocation;
        bool songFound = false;
        SongNode *iterator = songList->getFront();
        Song tempSong = iterator->getItem();
        for (int i = 0; i < songCount; i++) {
            if(!songFound){
                if(tempSong.getTitle() == songName){
                    songFound = true;
                    songLocation = i;
                }
                else{
                    iterator = iterator->getNext();
                    tempSong = iterator->getItem();
                }
            }
        }
        if(songFound){
            SongNode* nextNode;
            SongNode* nodeBefore;
            SongNode* nodeAfter;
            iterator = songList->getFront();
            if(songLocation==0){
                if(songCount > 1){
                    nextNode = iterator->getNext();
                    delete [] iterator;
                    songList->setFront(nextNode);
                    songCount--;
                    totalDuration -= tempSong.getDuration();
                }
                else{
                    delete[] iterator;
                    songList->setFront(nullptr);
                    songList->setEnd(nullptr);
                    songCount--;
                    totalDuration -= tempSong.getDuration();
                }
            }
            else if(songLocation == songCount--){
                for(int i = 0; i < songCount - 1; i++){
                    if(i == songCount--){
                        nodeBefore = iterator;
                    }
                    if(iterator->getNext() != nullptr){
                        iterator = iterator->getNext();
                    }

                }
                delete [] iterator;
                songList->setEnd(nodeBefore);
                songCount--;
                totalDuration -= tempSong.getDuration();
            }

            else{
                for(int i = 0; i < songCount - 1; i++){
                    if(i == songLocation--){
                        nodeBefore = iterator;
                    }
                    if(i != songLocation){
                        iterator = iterator->getNext();
                    }
                    if(i==songLocation++){
                        nodeAfter = iterator->getNext();
                        delete [] iterator;
                        nodeBefore->setNext(nodeAfter);
                        songCount--;
                        totalDuration -= tempSong.getDuration();
                    }

                }

            }
        }
        else{
            std::cout<<"Song not found"<<std::endl;
        }
    }
    else{
        std::cout<<"No songs in playList"<<std::endl;
    }

}
std::string SongStorage::songsOfArtist(std::string artistIn){
    std::string outPutString = "";
    if(songCount > 0){
        Song tempSong;
        SongNode* iterator = songList->getFront();
        tempSong = iterator->getItem();
        while(iterator->getNext() != nullptr){
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

Song SongStorage::findSong(std::string artistIn, std::string titleIn) {
    if (songCount > 0) {
        bool songFound = false;
        SongNode *iterator = songList->getFront();
        Song tempSong = iterator->getItem();
        for (int i = 0; i < songCount; i++) {
            if(!songFound){
                if(tempSong.getArtist() == artistIn && tempSong.getTitle() == titleIn){
                    songFound = true;
                }
                else{
                    iterator = iterator->getNext();
                    tempSong = iterator->getItem();
                }
            }
        }
        if(songFound){
            return tempSong;
        }
        else{
            std::cout<<"Song not found"<<std::endl;
        }
    }
    else{
        std::cout<<"No songs in playList"<<std::endl;
        Song failSong;
        return failSong;
    }
    Song failSong;
    return failSong;

}