//
// Created by Jrsta on 12/11/2019.
//

#include "Playlist.h"
#include "LinkedNode.h"
#include "LinkedList.h"
#include "Song.h"
#include "LinkedQueue.h"

PlayList::PlayList(std::string playListNameIn){
    songCount = 0;
    totalDuration = 0;
    playListName = playListNameIn;
    songList = new LinkedQueue();
}

PlayList::~PlayList(){
    delete[] songList;
}


PlayList::PlayList(const PlayList &playListToCopy) {
    songCount = playListToCopy.songCount;
    totalDuration = playListToCopy.totalDuration;
    playListName = playListToCopy.playListName;
    songList = new LinkedQueue(*playListToCopy.songList);
}



PlayList& PlayList::operator=(const class PlayList &playListToCopy) {
    if(this != &playListToCopy) {
        delete[] songList;

        songCount = playListToCopy.songCount;
        totalDuration = playListToCopy.totalDuration;
        playListName = playListToCopy.playListName;
        songList = new LinkedQueue(*playListToCopy.songList);



    }
    return *this;

}
//
//std::string PlayList::songsInPlaylist(){
//    std::string songTitles;
//    Song tempSong;
//    for(int i =0; i < songCount; i++){
//        tempSong = songList->getValueAt(i);
//        songTitles += tempSong.getTitle();
//    }
//    return songTitles;
//
//}
//
//int PlayList::playlistDuration() {
//    return totalDuration;
//}
//
//std::string PlayList::playNext() {
//    std::string songInfo;
//    if(isEmpty()){
//        songInfo = "Playlist is empty, add a song to play it.";
//    }
//    else{
//        Song songToPlay = songList->getValueAt(0);
//        songInfo = Song::songToString(songToPlay);
//        totalDuration -= songToPlay.getDuration();
//        songCount -= 1;
//        remove(songToPlay.getTitle());
//    }
//    return songInfo;
//}
//
//bool PlayList::isEmpty() {
//    if (songList->getValueAt(0) == nullptr){
//        return true;
//    }
//    else{
//        return false;
//    }
//
//}
//
//void PlayList::add(Song songToAdd) {
//    LinkedNode *newNode = new LinkedNode(songToAdd);
//    songList->insertAtEnd(newNode);
//    totalDuration += songToAdd.getDuration();
//    songCount += 1;
//}
//
//void PlayList::remove(std::string songName) {
//    Song tempSong;
//    bool songRemoved = false;
//    for(int i =0; i<songCount; i++){
//        tempSong = songList->getValueAt(i);
//        if(tempSong.getTitle() == songName){
//            songCount -= 1;
//            totalDuration -= tempSong.getDuration();
//            songList->removeValueAt(i);
//            songRemoved = true;
//        }
//    }
//    if(songRemoved == false){
//        std::cout<<"Song not found in playList"<<std::endl;
//    }
//}
