cmake_minimum_required(VERSION 3.12)
project(Comp220ADJ)

set(CMAKE_CXX_STANDARD 14)

add_executable(Comp220ADJ main.cpp Song.cpp SongNode.cpp LinkedQueueSong.cpp SongStorage.cpp PlaylistNode.cpp LinkedQueuePlaylist.cpp PlayListStorage.cpp)