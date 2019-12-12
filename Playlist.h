//
// Created by Jrsta on 12/11/2019.
//

#ifndef COMP220ADJ_PLAYLIST_H
#define COMP220ADJ_PLAYLIST_H

#include <string>
#include "LinkedQueue.h"

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

    int playlistDuration();

    std::string playNext();

    bool isEmpty();

    void add(LinkedNode *nodeToAdd);

    void remove(std::string songName);

    std::string getPlayListName();

    int getSongCount();

    int getTotalDuration();

    void printSongList();

};

#endif //COMP220ADJ_PLAYLIST_H
