//
// Created by Jrsta on 12/11/2019.
//

#ifndef COMP220ADJ_PLAYLIST_H
#define COMP220ADJ_PLAYLIST_H

#include <string>
#include "LinkedQueueSong.h"
#include "Song.h"
#include "Playlist.h"

class SongStorage : public Playlist{
private:
    std::string playListName;
    LinkedQueueSong* songList;
    int songCount;
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

    std::string songsOfArtist(std::string artistIn);

    Song findSong(std::string artistIn, std::string titleIn);

    std::string getPlayListName();

    int getSongCount();

    void printSongList();

    LinkedQueueSong* getSongList();



};

#endif //COMP220ADJ_PLAYLIST_H
