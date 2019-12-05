//
// Created by Jrsta on 11/18/2019.
//
#ifndef COMP220ADJ_SONG_H
#define COMP220ADJ_SONG_H

#include <string>

class Song{
private:
    std::string title;
    std::string artist;
    int durationSec;
    int playCount;

public:
    Song(std::string songString);

    Song(std::string titleIn, std::string artistIn, int durationIn);

    std::string songToString(Song songIn);

    std::string getTitle();

    std::string getArtist();

    int getDuration();

    int getPlayCount();

};



#endif //COMP220ADJ_SONG_H
