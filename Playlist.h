//
// Created by Jrsta on 12/11/2019.
//

#ifndef COMP220ADJ_PLAYLIST_H
#define COMP220ADJ_PLAYLIST_H

#include <string>
#include "LinkedQueue.h"
#include "Song.h"

class PlayList{
private:
    std::string playListName;
    LinkedQueue* songList;
    int songCount;
    int totalDuration;

public:

    PlayList(std::string playListNameIn);

    ~PlayList();

    PlayList& operator=(const PlayList& playListToCopy);

    PlayList(const PlayList& playListToCopy);

    std::string songsInPlaylist();

    int getTotalDuration();

    std::string playNext();

    bool isEmpty();

    void add(Song songToAdd);

    void remove(std::string songName);

    std::string getPlayListName();

    int getSongCount();

    void printSongList();

    std::string songsOfArtist(std::string atristIn);

    Song findSong(std::string artistIn, std::string titleIn);

};

#endif //COMP220ADJ_PLAYLIST_H
