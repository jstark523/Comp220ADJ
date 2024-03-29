//
// Created by alex K on 12/5/2019.
//

#include <iostream>
#include "SongNode.h"
#include "Song.h"
#include "LinkedQueueSong.h"
#include "SongStorage.h"

//void nodeTest(){
//    std::cout<<"Testing LinkedNode"<<std::endl;
//    std::cout<<""<<std::endl;
//    Song song1 = Song("Muse", "Showbiz",60);
//    LinkedNode* test1 = new LinkedNode(song1);
//    std::cout<<""<<std::endl;
//
//    //Testing Getters/Node holding Songs/Song initialized with parameter heavy constructor
//    std::cout<<""<<std::endl;
//    std::cout<<"Should print Muse, Showbiz, 60, 0 "<<std::endl;
//    std::cout<< test1->getItem().getArtist() + ", " + test1->getItem().getTitle() + ", " + std::to_string(test1->getItem().getDuration()) + ", "  + std::to_string(test1->getItem().getPlayCount()) <<std::endl;
//
//    Song song2 = Song("RexOrangeCounty*10/10*30");
//    LinkedNode* test2 = new LinkedNode(song2);
//
//    std::cout<<""<<std::endl;
//    //Testing Getters/Node holding Songs/Song initialized with Single String parameter Constructor
//    std::cout<<"Should print RexOrangeCounty, 10/10, 30, 0 "<<std::endl;
//    std::cout<< test2->getItem().getArtist() + ", " + test2->getItem().getTitle() + ", " + std::to_string(test2->getItem().getDuration()) + ", "  + std::to_string(test2->getItem().getPlayCount()) <<std::endl;
//
//    test2->setItem(song1);
//
//    std::cout<<""<<std::endl;
//    //Testing setItem
//
//    std::cout<<"Should print Muse, Showbiz, 60, 0"<<std::endl;
//    std::cout<< test2->getItem().getArtist() + ", " + test2->getItem().getTitle() + ", " + std::to_string(test2->getItem().getDuration()) + ", "  + std::to_string(test2->getItem().getPlayCount()) <<std::endl;
//
//    test2->setItem(song2);
//    test1->setNext(test2);
//
//    //Testing setNext and getNext
//    std::cout<<""<<std::endl;
//    std::cout<<"Should print RexOrangeCounty"<<std::endl;
//    std::cout<< test1->getNext()->getItem().getArtist() << std::endl;
//    std::cout<<""<<std::endl;
//
//    //Testing Copy Constructor
//    std::cout<<"Should print Muse"<<std::endl;
//    LinkedNode* copyNode = new LinkedNode(song1);
//    LinkedNode copiedNode = LinkedNode(*copyNode);
//    std::cout<<copiedNode.getItem().getArtist()<<std::endl;
//
//    std::cout<<""<<std::endl;
//    std::cout<<"Linked Node Tests Complete"<<std::endl;
//}
//
//void songTest() {
//
//    std::cout << "-----Testing Song(std::string songSting)-----" << std::endl;
//    Song song1 = Song("Hermitude*The Buzz*180*0");
//    std::cout << "Song Duration is " << std::to_string(song1.getDuration()) << " Expected: 180" << std::endl;
//    std::cout << "Song Title is " << song1.getTitle() << " Expected: The Buzz" << std::endl;
//    std::cout << "Song Artist is " << song1.getArtist() << " Expected: Artist" << std::endl;
//    std::cout << "Song Playcount is " << std::to_string(song1.getPlayCount()) << " Expected: 0" << std::endl;
//
//    std::cout << "" << std::endl;
//
//    std::cout << "-----Testing Song(std::string artistIn, std::string titleIn, int durationIn" << std::endl;
//    Song song2 = Song("Alan Walker", "On My Way", 193);
//    std::cout << "Song Duration is " << std::to_string(song2.getDuration()) << "Expected: 193" << std::endl;
//    std::cout << "Song Title is " << song2.getTitle() << "Expected: On My Way" << std::endl;
//    std::cout << "Song Artist is " << song2.getArtist() << "Expected: Alan Walker" << std::endl;
//    std::cout << "Song Playcount is " << std::to_string(song2.getPlayCount()) << "Expected: 0" << std::endl;
//
//    std::cout << "" << std::endl;
//
//    std::string songTest = Song::songToString(song2);
//
//    std::cout << songTest << "Expected: Alan Walker*On My Way*193*0" << std::endl;
//}
//
//void queueTest(){
//    Song song1 = Song("Muse", "Showbiz",60);
//    Song song2 = Song("Muse", "Supremacy",60);
//    LinkedQueue* queueToTest = new LinkedQueue();
//    queueToTest->enqueue(song1);
//    queueToTest->enqueue(song2);
//    std::string tempString = queueToTest->to_String();
//
//    std::cout <<  tempString << std::endl;
//}
//
//void playListTest(){
//    Song tempSong1 = Song("Muse", "Showbiz",60);
//    Song tempSong2 = Song("Muse", "Supremacy",60);
//    PlayList* testPlayList = new PlayList("test");
//    testPlayList->PlayList::add(tempSong1);
//    testPlayList->PlayList::add(tempSong2);
//    std::string tempString = testPlayList->PlayList::songsInPlaylist();
//    tempSong1 = testPlayList->findSong("Muse", "Supremacy");
//    tempString = Song::songToString(tempSong1);
//    std::cout<<tempString<<std::endl;
//}
Playlist* randomPlaylist(std::string name, int totalDurationIn, Playlist* libraryIn){
    SongStorage* randomList = new SongStorage(name);
    bool totalDurationReached = false;
    while(totalDurationReached == false){
        int temp= (rand() % (libraryIn->getSongCount()));
        SongNode* iterator;
        Song songTemp;
        iterator = libraryIn->getSongList()->getFront();
        songTemp = iterator->getItem();
        songNotIn = true;
        if(temp == 0){
            if(randomList)
            if(randomList->getTotalDuration() + songTemp.getDuration() < totalDurationIn && songNotIn == true){
                randomList->add(songTemp);
            }
            else{
                totalDurationReached = true;
            }
        }
        else {
            for (int i = 1; i <= temp; i++) {
                iterator = iterator->getNext();
                songTemp = iterator->getItem();
                if(temp == i){
                    if(randomList->getTotalDuration() + songTemp.getDuration() < totalDurationIn){
                        randomList->add(songTemp);
                    }
                    else{
                        totalDurationReached = true;
                    }
                }
            }
        }
    }
    return randomList;
}
void newRandomTest(){
    Song song2 = Song("Muse", "Showbiz",60);
    Song song1 = Song("RexOrangeCounty*10/10*30");
    Playlist* library = new SongStorage();
    library->add(song1);
    library->add(song2);
    std::cout<<library->getSongCount()<<std::endl;
    Playlist* newList = new SongStorage();
    newList = randomPlaylist("chill Vibes", 200, library);
    std::cout<<newList->getTotalDuration()<<std::endl;
    std::cout<<newList->songsInPlaylist()<<std::endl;
}

int main(){
//    nodeTest();
//    songTest();
//    queueTest();
//    playListTest();
    srand(time(NULL));
    newRandomTest();
    return 0;
}

