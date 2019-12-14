//
// Created by Jrsta on 12/14/2019.
//

/**
     * This is our .h file creating the pure virtual Playlist collection to be implemented later
 */

#ifndef COMP220ADJ_PLAYLISTCOLLECTION_H
#define COMP220ADJ_PLAYLISTCOLLECTION_H

#include <iostream>
#include "SongStorage.h"
#include "SongNode.h"
#include "LinkedQueuePlaylist.h"

//class LinkedQueuePlaylist;

class PlaylistCollection{

private:
    PlaylistCollection(const PlaylistCollection& playlistCollectionToCopy);

    PlaylistCollection& operator=(const PlaylistCollection& playlistCollectionToCopy);

public:
    PlaylistCollection();

    virtual std::string playListNames()=0;

    virtual std::string getTotalDuration()=0;

    virtual std::string playListSongs(std::string playListName)=0;

    virtual void addSongToPlaylist(std::string playlistName, Song songToAdd)=0;

    virtual SongNode* nextSong(std::string playListName)=0;

    virtual LinkedQueuePlaylist* getPlaylists()=0;

};

#endif //COMP220ADJ_PLAYLISTCOLLECTION_H
