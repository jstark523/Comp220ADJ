//
// Created by Jrsta on 12/11/2019.
//

#ifndef COMP220ADJ_PLAYLIST_H
#define COMP220ADJ_PLAYLIST_H

#include <string>
#include "LinkedQueue.h"
#include "Song.h"

class SongStorage{
private:
    std::string playListName;
    static LinkedQueue* songList;
    static int songCount;
    int totalDuration;

public:
    SongStorage();

    SongStorage(std::string playListNameIn);

    ~SongStorage();

    SongStorage& operator=(const SongStorage& playListToCopy);

    SongStorage(const SongStorage& playListToCopy);

    std::string songsInPlaylist();

    int getTotalDuration();

    std::string playNext();

    bool isEmpty();

    void add(Song songToAdd);

    void remove(std::string songName);

    static std::string songsOfArtist(std::string atristIn);

    Song findSong(std::string artistIn, std::string titleIn);

    //std::string getPlayListName();

    //int getSongCount();

    //void printSongList();



};

#endif //COMP220ADJ_PLAYLIST_H
