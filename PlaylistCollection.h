//
// Created by Jrsta on 12/14/2019.
//

#ifndef COMP220ADJ_PLAYLISTCOLLECCTION_H
#define COMP220ADJ_PLAYLISTCOLLECCTION_H

#include <iostream>
#include "SongStorage.h"
#include "LinkedQueueSong.h"


class PlaylistCollection{

private:
    PlaylistCollection(const PlaylistCollection& playlistCollectionToCopy);

    PlaylistCollection& operator=(const PlaylistCollection& playlistCollectionToCopy);

public:
    PlaylistCollection();

    virtual std::string playListNames()=0;

    virtual std::string getTotalDuration()=0;

    virtual std::string playListSongs(std::string playList name)=0;

    virtual Playlist* findPlaylist()=0;

    virtual void add(Song songToAdd)=0;

    virtual void nextSong(std::string playListName)=0;
};

#endif //COMP220ADJ_PLAYLISTCOLLECCTION_H
