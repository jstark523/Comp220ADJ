//
// Created by Jrsta on 12/14/2019.
//

#ifndef COMP220ADJ_PLAYLISTSTORAGE_H
#define COMP220ADJ_PLAYLISTSTORAGE_H

#include <iostream>
#include "SongStorage.h"
#include "LinkedQueuePlaylist.h"
#include "PlaylistCollection.h"
#include "SongNode.h"



class PlayListStorage : public PlaylistCollection{

private:
    LinkedQueuePlaylist* playlistList;
    int playlistCount;
public:
    PlayListStorage();

    ~PlayListStorage();

    std::string playListNames();

    std::string getTotalDuration();

    std::string playListSongs(std::string playListName);

    void addSongToPlaylist(std::string playlistName, Song songToAdd);

    SongNode* nextSong(std::string playListName);

    LinkedQueuePlaylist* getPlaylists();
};

#endif //COMP220ADJ_PLAYLISTSTORAGE_H
