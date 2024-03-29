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
    delete playlistList;
}

std::string PlayListStorage::playListNames() {
    if(playlistCount == 0){
        return "No Playlists";
    }
    std::string outPutString ="";
    PlaylistNode* iterator = playlistList->getFront();
    while(iterator != nullptr){
        SongStorage tempPlaylist = iterator->getItem();
        outPutString += (tempPlaylist.getPlayListName() + "|");
        iterator = iterator->getNext();
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

void PlayListStorage::incPlaylistCount(){
    this->playlistCount++;
}

SongStorage PlayListStorage::findPlaylist(PlaylistCollection* playlists, std::string playlistName){
    PlaylistNode* iterator = playlistList->getFront();
    SongStorage tempPlaylist = iterator->getItem();
    int count = 0;
    while(count < PlayListStorage::playlistCount) {
        if (tempPlaylist.getPlayListName() == playlistName) {
            return tempPlaylist;
        }else{
            iterator = iterator->getNext();
            tempPlaylist = iterator->getItem();
        }
    }
    std::cout<<"No playlist was found!"<<std::endl;
    return tempPlaylist;
}

int PlayListStorage::getPlaylistCount() {
    return playlistCount;
}