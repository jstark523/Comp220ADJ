//
// Created by Jrsta on 12/14/2019.
//
#include "PlayListStorage.h"
#include "PlaylistCollection.h"
#include "SongStorage.h"
#include "SongNode.h"

PlaylistCollection::PlaylistCollection() {
    //std::cout << "" << std::endl;
}


PlayListStorage::PlayListStorage(){
    playlistCount = 0;
    playlistList = new LinkedQueuePlaylist;
}

PlayListStorage::~PlayListStorage(){
    delete[] playlistList;
}

std::string PlayListStorage::playListNames() {
    std::string outPutString ="";
    if(playlistCount > 0) {
        PlaylistNode* iterator = playlistList->getFront();
        SongStorage tempPlaylist = iterator->getItem();
        for (int i = 0; i < playlistCount; i++) {
            outPutString += tempPlaylist.getPlayListName() + "|";
            iterator = iterator->getNext();
            tempPlaylist = iterator->getItem();
        }
    }

    else{
        outPutString = "No playlists made";
    }

    return outPutString;
}

std::string PlayListStorage::getTotalDuration(){
    std::string outPutString ="";
    int durationInt = 0;
    if(playlistCount > 0) {
        PlaylistNode* iterator = playlistList->getFront();
        SongStorage tempPlaylist = iterator->getItem();
        for (int i = 0; i < playlistCount; i++) {
            durationInt += tempPlaylist.getTotalDuration();
            iterator = iterator->getNext();
            tempPlaylist = iterator->getItem();
        }
    }
    if(durationInt == 0){
        outPutString = "No playlists made";
    }

    else{
        outPutString = std::to_string(durationInt);
    }

    return outPutString;
}

std::string PlayListStorage::playListSongs(std::string playListName) {
    std::string outPutString ="";
    if(playlistCount > 0) {
        PlaylistNode* iterator = playlistList->getFront();
        SongStorage tempPlaylist = iterator->getItem();
        for (int i = 0; i < playlistCount; i++) {
            if(tempPlaylist.getPlayListName() == playListName){
                outPutString = tempPlaylist.songsInPlaylist();
            }
            iterator = iterator->getNext();
            tempPlaylist = iterator->getItem();
        }
    }
    if(outPutString == ""){
        outPutString = "Playlist not found/No songs in Playlist";
    }

    return outPutString;
}

void PlayListStorage::addSongToPlaylist(std::string playlistName, class Song songToAdd){
    bool playlistFound = false;
    bool noPlaylists = false;
    if(playlistCount > 0) {

        PlaylistNode* iterator = playlistList->getFront();
        SongStorage tempPlaylist = iterator->getItem();
        for (int i = 0; i < playlistCount; i++) {
            if(tempPlaylist.getPlayListName() == playlistName){
                tempPlaylist.add(songToAdd);
                playlistFound = true;
            }
            iterator = iterator->getNext();
            tempPlaylist = iterator->getItem();
        }
    }
    else{
        noPlaylists = true;
        std::cout<< "No PlayLists Made"<<std::endl;
    }

    if(!noPlaylists && !playlistFound){
        std::cout<< "Playlist of given name Not found in existing playlists"<<std::endl;
    }

}

SongNode* PlayListStorage::nextSong(std::string playListName) {
    SongNode* firstSong;
    if(playlistCount > 0) {
        PlaylistNode* iterator = playlistList->getFront();
        SongStorage tempPlaylist = iterator->getItem();
        for (int i = 0; i < playlistCount; i++) {
            if(tempPlaylist.getPlayListName() == playListName){
                firstSong = tempPlaylist.getSongList()->getFront();
                return firstSong;
            }
            iterator = iterator->getNext();
            tempPlaylist = iterator->getItem();
        }
    }
    std::cout<< "No PlayLists Made/Song Not found"<<std::endl;


}

LinkedQueuePlaylist* PlayListStorage::getPlaylists(){
    return playlistList;
}







