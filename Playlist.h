//
// Created by Bryan Pruett on 12/13/19.
//

#ifndef COMP220ADJ_PLAYLIST_H_COOLER
#define COMP220ADJ_PLAYLIST_H_COOLER

#include <iostream>
#include "Song.h"

class Playlist{

private:
    Playlist(const Playlist& playListToCopy);

    Playlist& operator=(const Playlist& playListToCopy);

public:
    Playlist();

    virtual std::string songsInPlaylist()=0;

    virtual int getTotalDuration()=0;

    virtual std::string playNext()=0;

    virtual bool isEmpty()=0;

    virtual void add(Song songToAdd)=0;

    virtual void remove(std::string songName)=0;

    virtual std::string songsOfArtist(std::string atristIn)=0;

    virtual Song findSong(std::string artistIn, std::string titleIn)=0;

    virtual std::string getPlayListName()=0;

    virtual int getSongCount()=0;

    virtual void printSongList()=0;

};

#endif //COMP220ADJ_PLAYLIST_H_COOLER
