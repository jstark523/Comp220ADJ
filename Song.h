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
    Song();

    explicit Song(std::string songString);

    Song(std::string artistIn, std::string titleIn, int durationIn);

    static std::string songToString(Song songIn);

    std::string getTitle();

    std::string getArtist();

    int getDuration();

    int getPlayCount();

};



#endif //COMP220ADJ_SONG_H
