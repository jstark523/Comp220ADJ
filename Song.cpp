//created by Jason Starkman

#include "Song.h"
#include <string>

Song::Song(std::string songString){
    std::string delimiter = "*";
    std::string artistString = songString.substr(0,songString.find(delimiter));
    songString.erase(0, songString.find(delimiter) + delimiter.length());
    std::string titleString = songString.substr(0, songString.find(delimiter));
    songString.erase(0, songString.find(delimiter) + delimiter.length());
    std::string durationString = songString.substr(0, songString.find(delimiter));
    songString.erase(0, songString.find(delimiter) + delimiter.length());

    title = titleString;
    artist = artistString;
    durationSec = std::stoi(durationString);
    playCount = 0;
}

Song::Song(std::string titleIn, std::string artistIn, int durationIn){
    title=titleIn;
    artist=artistIn;
    durationSec=durationIn;
    playCount=0;
}

std::string Song::getTitle(){
    return title;
}

std::string Song::getArtist() {
    return artist;
}

int Song::getDuration() {
    return durationSec;
}

int Song::getPlayCount() {
    return playCount;
}

std::string Song::songToString(Song songIn){
    std::string songString;

    songString += songIn.getTitle() + "*";
    songString += songIn.getArtist() + "*";
    songString += std::to_string(songIn.getDuration()) + "*";
    songString += std::to_string(songIn.getPlayCount()) + "|";

    return songString;
}