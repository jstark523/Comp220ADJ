//
// Created by Jrsta on 12/14/2019.
//

/**
     * This .h file is our implementation to the playlist collection
 */

#ifndef COMP220ADJ_PLAYLISTSTORAGE_H
#define COMP220ADJ_PLAYLISTSTORAGE_H

#include <iostream>
#include "SongStorage.h"
#include "PlaylistCollection.h"
#include "LinkedQueuePlaylist.h"
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

    void incPlaylistCount();

    SongStorage findPlaylist(PlaylistCollection* playlists, std::string playlistName);
};

#endif //COMP220ADJ_PLAYLISTSTORAGE_H
