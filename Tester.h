//
// Created by Jrsta on 12/5/2019.
//

#ifndef COMP220ADJ_TESTER_H
#define COMP220ADJ_TESTER_H

#include <iostream>
#include "Playlist.h"
#include "SongStorage.h"

void nodeTest();
void songTest();
void queueTest();
void playListTest();
void randomPlaylist();
Playlist* newRandomTest(std::string name, int totalDurationIn, Playlist* library);


#endif //COMP220ADJ_TESTER_H
